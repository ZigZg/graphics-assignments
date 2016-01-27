#include "Renderer.h"

#include "SceneParser.h"
#include "Image.h"
#include "Camera.h"



Renderer::Renderer(const std::string &sceneFilename)
{
    // Parse the scene using SceneParser.
    this->sceneParser = new SceneParser(sceneFilename);

}

Renderer::~Renderer()
{
    delete sceneParser; sceneParser = NULL;
}


// Loops over each pixel in the image, shooting a ray
// through that pixel and finding its intersection with
// the scene. Writes the color at the intersection to that
// pixel in the output image.
//
// Uses the Image class to write out the requested output files.
void
Renderer::Render(int width,
                 int height,
                 const std::string &outputFilename,
                 float minDepth,
                 float maxDepth,
                 const std::string &depthFilename,
                 const std::string &normalFilename)
{
    // three image types: the output image, a depth visualization image, and a normal visualization image
    Image output = Image(width, height); // instantiates image of black pixels
    Image depth = Image(width, height);
    Image normal = Image(0, 0);

    // if no "normal" argument specified in command line, don't make normal image
    bool normalFile = !normalFilename.empty();
    if (normalFile) {
        normal = Image(width, height);
    }

    Vector3f backgroundColor = sceneParser->getBackgroundColor();
    Camera * camera = sceneParser->getCamera();
    Group * group = sceneParser->getGroup();
    float tmin = camera->getTMin();

    // for each pixel
    for (float x=0.0; x<width; x++){
        for (float y=0.0; y<height; y++) {
            //instantiate a hit object
            Hit h = Hit();

            //instantiate a ray object
            Ray ray = camera->generateRay(Vector2f(2*x/width-1, 2*y/height-1));

            // goes through each object in the group, checks if it intersects with the ray, and updates
            // the hit object accordingly
            bool intersect = group->intersect(ray, tmin, h);
            
            if (intersect) {
                float t = h.getT();
                Vector3f p = ray.pointAtParameter(t);
                Material * material = h.getMaterial();
                Vector3f pixelColor = Vector3f::ZERO;

                int numLights = sceneParser->getNumLights();
                Vector3f dirToLight;
                Vector3f color;
                float distanceToLight;
                for(int i=0;i<numLights;i++) {
                    // get the light source
                    Light * light = sceneParser->getLight(i);
                    // get the direction and distance to the light, and the light's color
                    light->getIllumination(p, dirToLight, color, distanceToLight);
                    // calculates the shade from the light
                    pixelColor += material->shade(ray, h, dirToLight, color);
                }

                // adds color from ambient light and the material's innate color
                Vector3f k_d = material->getDiffuseColor();
                Vector3f c_ambient = sceneParser->getAmbientLight();
                pixelColor += k_d*c_ambient;
                output.setPixel(x, y, pixelColor);

                // calculates greyscale value for depth visualization
                float interval = maxDepth-minDepth;
                float greyscale = (t-minDepth)/interval;
                depth.setPixel(x, y, Vector3f(1-greyscale));

                if (normalFile) {
                    // calculates RGB value to use for normal visualization based on normal direction
                    Vector3f vecNormal = h.getNormal();
                    float R = std::abs(vecNormal[0]);
                    float G = std::abs(vecNormal[1]);
                    float B = std::abs(vecNormal[2]);
                    normal.setPixel(x, y, Vector3f(R, G, B));
                }
            } else {
                // no intersection; pixel set to background color
                output.setPixel(x, y, backgroundColor);
            }
        }
    }

    // generate the images
    output.savePNG(outputFilename);
    depth.savePNG(depthFilename);
    if (normalFile) {
        normal.savePNG(normalFilename);
    }
}
