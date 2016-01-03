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

void
Renderer::Render(int width,
                 int height,
                 const std::string &outputFilename,
                 float minDepth,
                 float maxDepth,
                 const std::string &depthFilename,
                 const std::string &normalFilename)
{
    Vector3f backgroundColor = sceneParser->getBackgroundColor();
    Image output = Image(width, height); //should instantiate image of black pixels
    Image depth = Image(width, height);
    Image normal = Image(0, 0);
    bool normalFile = !normalFilename.empty();
    if (normalFile) {
        normal = Image(width, height);
    }

    Camera * camera = sceneParser->getCamera();
    Group * group = sceneParser->getGroup();
    float tmin = camera->getTMin();
    for (float x=0.0; x<width; x++){
        for (float y=0.0; y<height; y++) {
            //instantiates a hit object
            Hit h = Hit();

            //instantiates a ray object
            Ray ray = camera->generateRay(Vector2f(2*x/width-1, 2*y/height-1));

            //goes through each object in the group, checks if it intersects with the ray, and updates
            // the hit object accordingly
            bool intersect = group->intersect(ray, tmin, h);
            
            if (intersect) {
                float t = h.getT();
                Vector3f p = ray.pointAtParameter(t);
                Material * material = h.getMaterial();
                int numLights = sceneParser->getNumLights();
                Vector3f dirToLight;
                Vector3f col;
                float distanceToLight;
                Vector3f pixelColor = Vector3f::ZERO;
                for(int i=0;i<numLights;i++) {
                    //get the light source
                    Light * light = sceneParser->getLight(i);
                    light->getIllumination(p, dirToLight, col, distanceToLight);
                    pixelColor += material->shade(ray, h, dirToLight, col);
                }
                Vector3f k_d = material->getDiffuseColor(); //check this
                //Texture texture = material->getTexture();
                /*if (texture.isValid()) {
                    Vector2f uv = h.getTexCoord();
                    std::cout << uv[0] << ", " << uv[1] << std::endl;
                    k_d = texture.getTexel(uv[0], uv[1]);
                }*/
                Vector3f c_ambient = sceneParser->getAmbientLight();
                pixelColor += k_d*c_ambient;
                output.setPixel(x, y, pixelColor);

                float interval = maxDepth-minDepth;
                float greyscale = (t-minDepth)/interval;
                depth.setPixel(x, y, Vector3f(1-greyscale));

                if (normalFile) {
                    Vector3f vecNormal = h.getNormal();
                    float R = std::abs(vecNormal[0]);
                    float G = std::abs(vecNormal[1]);
                    float B = std::abs(vecNormal[2]);
                    normal.setPixel(x, y, Vector3f(R, G, B));
                }
            } else {
                output.setPixel(x, y, backgroundColor);
            }
        }
    }
    output.savePNG(outputFilename);
    depth.savePNG(depthFilename);
    if (normalFile) {
        normal.savePNG(normalFilename);
    }

    // Loop over each pixel in the image, shooting a ray
    // through that pixel and finding its intersection with
    // the scene. Write the color at the intersection to that
    // pixel in your output image.
    //
    // Use the Image class to write out the requested output files.
}
