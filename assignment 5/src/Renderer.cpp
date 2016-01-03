#include "Renderer.h"

#include "ArgParser.h"
#include "Camera.h"
#include "Hit.h"
#include "Image.h"
#include "Ray.h"
#include "VecUtils.h"

#include <limits>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <vector>

Renderer::Renderer(const ArgParser &args) :
    _args(args),
    _scene(args.input_file)
{
}

Renderer::~Renderer()
{
}

// IMPLEMENT THESE FUNCTIONS
// These function definitions are mere suggestions. Change them as you like.
Vector3f 
mirrorDirection(const Vector3f &normal, const Vector3f &incoming)
{
    return incoming - 2*(Vector3f::dot(incoming, normal))*normal;
}

bool
transmittedDirection(const Vector3f &normal, 
                     const Vector3f &incoming, 
                     float index_i,
                     float index_t, 
                     Vector3f &transmitted)
{
    float sqrtValue =  1.0-(pow(index_i, 2.0)*(1.0-pow(Vector3f::dot(incoming, normal), 2.0)))/pow(index_t, 2.0);
    if (sqrtValue >= 0){
        transmitted = ((index_i*(incoming-normal*Vector3f::dot(incoming, normal)))/index_t - normal*sqrt(sqrtValue)).normalized();
        return true;
    } else {
        return false;
    }
}

void blur(const Image &oldImage, Image &newImage, bool horizontal) {
    float K [5] = {0.1201, 0.2339, 0.2931, 0.2339, 0.1201};
    int width;
    int height;
    if (horizontal) {
        width = oldImage.getWidth();
        height = oldImage.getHeight();
    } else {
        width = oldImage.getHeight();
        height = oldImage.getWidth();
    }
    //std::cout << width << ", " << height << std::endl;
    for (float x=0.0; x<width; x++) {
        for (float y=0.0; y<height; y++) {
            float minusTwo = std::max(y-2, 0.0f);
            float minusOne = std::max(y-1, 0.0f);
            float plusOne = std::min(y+1, height-1.0f);
            float plusTwo = std::min(y+2, height-1.0f);
            if (horizontal) {
                //std::cout << x << ", " << y << std::endl;
                Vector3f newColor = oldImage.getPixel(x, minusTwo)*K[0] + oldImage.getPixel(x, minusOne)*K[1] + oldImage.getPixel(x, y)*K[2] + oldImage.getPixel(x, plusOne)*K[3] + oldImage.getPixel(x, plusTwo) * K[3];
                //newColor.print();
                newImage.setPixel(x, y, newColor);
            } else {
                //std::cout << y << ", " << x << std::endl;
                Vector3f newColor = oldImage.getPixel(minusTwo, x)*K[0] + oldImage.getPixel(minusOne, x)*K[1] + oldImage.getPixel(y, x)*K[2] + oldImage.getPixel(plusOne, x)*K[3] + oldImage.getPixel(plusTwo, x) * K[3];
                //newColor.print();
                newImage.setPixel(y, x, newColor);
            }
        }
    }
}

std::vector<Vector2f> getNeighbors(float width, float height, float x, float y) {
    std::vector<Vector2f> neighbors;
    for (float i=0.0; i<3.0; i++) {
        float neighbor_x = x+i-1;
        float neighbor_x_new;
        neighbor_x_new = std::max(0.0f, neighbor_x);
        neighbor_x_new = std::min(neighbor_x, width-1);
        for (float j=0.0; j<3.0; j++) {
            float neighbor_y = y+j-1;
            float neighbor_y_new;
            neighbor_y_new = std::max(0.0f, neighbor_y);
            neighbor_y_new = std::min(neighbor_y, height-1);
            if (neighbor_x == neighbor_x_new && neighbor_y == neighbor_y_new) {
                neighbors.push_back(Vector2f(neighbor_x, neighbor_y));
            }
        } 
    }
    return neighbors;
}

Vector3f getAverageColor(Image &image, int x, int y) {
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<Vector2f> neighbors = getNeighbors(width, height, x, y);
    Vector3f localColor = Vector3f::ZERO;
    for (float i=0.0; i<neighbors.size(); i++) {
        Vector2f neighbor = neighbors[i];
        localColor += image.getPixel(neighbor[0], neighbor[1]);
    }
    //localColor.print();
    localColor = Vector3f(localColor[0]/neighbors.size(), localColor[1]/neighbors.size(), localColor[2]/neighbors.size());
    //localColor.print();
    return localColor;
}

void
Renderer::Render()
{
    // TODO: IMPLEMENT 

    // This is the main loop that should be based on your assignment 4 main
    // loop. You will need to modify it to switch from ray casting to ray
    // tracing, to cast shadows and anti-aliasing (via jittering and
    // filtering).
    int width = _args.width;
    int height = _args.height;
    if (_args.jitter) {
        width *= 3;
        height *= 3;
    }
    std::string outputFilename = _args.output_file;
    float minDepth = _args.depth_min;
    float maxDepth = _args.depth_max;
    std::string depthFilename = _args.depth_file;
    std::string normalFilename = _args.normals_file;
    Image output = Image(width, height); //should instantiate image of black pixels
    Image depth = Image(width, height);
    Image normal = Image(0, 0);
    bool normalFile = !normalFilename.empty();
    if (normalFile) {
        normal = Image(width, height);
    }

    Camera * camera = _scene.getCamera();
    Group * group = _scene.getGroup();
    float tmin = camera->getTMin();

    //for each pixel
    for (float x=0.0; x<width; x++){
        for (float y=0.0; y<height; y++) {

            //instantiates a hit object
            Hit h = Hit();

            //instantiates a ray object
            float r_i = 0.0;
            float r_j = 0.0;
            if (_args.jitter) {
                r_i = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) - 0.5;
                r_j = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) - 0.5;
            }
            Ray ray = camera->generateRay(Vector2f(2*(x+r_i)/width-1, 2*(y+r_j)/height-1)); //check if only adding to x and y, or to whole argument

            //gets the background color
            Vector3f backgroundColor = _scene.getBackgroundColor(ray.getDirection());

            //goes through each object in the group, checks if it intersects with the ray, and updates
            // the hit object accordingly
            bool intersect = group->intersect(ray, tmin, h);
            
            if (intersect) {
                float t = h.getT();
                Material * material = h.getMaterial();
                Vector3f pixelColor = traceRay(ray, tmin, 0.0, 1.0, h); //or should 1.0 be material->getRefractionIndex()?
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
    if (_args.filter) {
        Image outputBlur = Image(width, height);
        //output.getPixel(300, 300).print();
        blur(output, outputBlur, true);
        blur(output, outputBlur, false);
        //outputBlur.getPixel(300, 300).print();
        int newWidth = width/3;
        int newHeight = height/3;
        Image outputBlurDown = Image(newWidth, newHeight);

        //assumes that jittering is also on as well
        for (int x=1; x<width; x+=3){
            for (int y=1; y<height; y+=3) {
                Vector3f localColor = getAverageColor(outputBlur, x, y);
                //localColor.print();
                outputBlurDown.setPixel(x/3, y/3, localColor);
            }
        }
        outputBlurDown.savePNG(outputFilename);
    } else {
        output.savePNG(outputFilename);
    }
    depth.savePNG(depthFilename);
    if (normalFile) {
        normal.savePNG(normalFilename);
    }
}

float clampApprox(const Vector3f &incoming,
                  const Vector3f &normal,
                  const Vector3f &transmitted,
                  float index_i,
                  float index_t
                  )
{
    if (index_i <= index_t) {
        return std::abs(Vector3f::dot(incoming, normal));
    } else {
        return std::abs(Vector3f::dot(transmitted, normal));
    }
}

//compute the final color along a ray
Vector3f
Renderer::traceRay(const Ray &ray, 
                   float tmin, 
                   int bounces,
                   float refr_index, 
                   Hit &hit) const
{
    float epsilon = 0.001f;
    int maxBounces = _args.bounces;
    bool shadows = _args.shadows;
    Group * group = _scene.getGroup();
    Vector3f rayDirection = ray.getDirection();
    Vector3f normal = hit.getNormal();
    Material * material = hit.getMaterial();
    float index_t = material->getRefractionIndex();
    if (refr_index > 1) {
        index_t = 1.0;
    }
    Vector3f newNormal = Vector3f(normal[0], normal[1], normal[2]);
    if (refr_index > index_t) {
        newNormal *= -1;
    }

    //get the intersection point
    float t = hit.getT();
    Vector3f p = ray.pointAtParameter(t);

    int numLights = _scene.getNumLights();

    Vector3f dirToLight;
    Vector3f col;
    float distanceToLight;
    Vector3f pixelColor = Vector3f::ZERO;

    //get the shading component
    for(int i=0;i<numLights;i++) {
        //get the light source
        Light * light = _scene.getLight(i);
        light->getIllumination(p, dirToLight, col, distanceToLight);

        //if shadows are enabled, do shadow casting
        if (shadows) {
            //create ray from intersection point to light source
            Ray shadowRay = Ray(p, dirToLight);

            //create a Hit object for the new ray
            Hit lightHit = Hit(distanceToLight, NULL, NULL);

            //intersect the new ray with every object
            group->intersect(shadowRay, tmin+epsilon, lightHit);

            //check if the ray hit any of the objects
            if (lightHit.getT() == distanceToLight) {
                // if not, add the local shading term to the color
                //std::cout << "hello" << std::endl;
                pixelColor += material->shade(ray, hit, dirToLight, col);
            }
        // else do normal shading
        } else {
            pixelColor += material->shade(ray, hit, dirToLight, col);
        }
    }
    // get the reflective component
    // get the ray and the hit
    Ray reflectedRay = Ray(p, mirrorDirection(newNormal, rayDirection));
    Hit reflectedHit = Hit();

    //see if the ray intersects any of the objects
    bool reflectIntersect = group->intersect(reflectedRay, tmin+epsilon, reflectedHit);

    Vector3f k_d = material->getDiffuseColor();
    Vector3f reflColor = material->getSpecularColor();
    Vector3f otherReflColor;
    if (reflectIntersect) {
        if (bounces < maxBounces) {
            otherReflColor = traceRay(reflectedRay, tmin, bounces+1, refr_index, reflectedHit);
        } else {
            otherReflColor = k_d;
        }  
    } else {
        otherReflColor = _scene.getBackgroundColor(reflectedRay.getDirection());
    }
    Vector3f totalReflColor = reflColor*otherReflColor;

    //get the refraction component
    //get the transmitted ray and the associated hit object
    Vector3f transmittedDir;
    bool transmitted = transmittedDirection(newNormal, rayDirection, refr_index, index_t, transmittedDir);

    //get the color from the refracted ray (if refracted)
    Vector3f refrColor;
    if (transmitted) {
        Ray transmittedRay = Ray(p, transmittedDir);
        Hit transmittedHit = Hit();
        bool refrIntersect = group->intersect(transmittedRay, tmin+epsilon, transmittedHit);
        if (refrIntersect){
            if (bounces < maxBounces) {
                refrColor = traceRay(transmittedRay, tmin, bounces+1, index_t, transmittedHit);
            } else {
                refrColor = k_d;
            }
        } else {
            refrColor = _scene.getBackgroundColor(transmittedRay.getDirection());
        }
    } else {
        refrColor = k_d;
    }
    Vector3f totalRefrColor = reflColor*refrColor;

    //get weights for Schlick's approximation to Fresnel's equation
    float R0 = pow(((index_t-refr_index)/(index_t+refr_index)), 2.0);
    float c = clampApprox(rayDirection, normal, transmittedDir, refr_index, index_t);
    float R = R0+(1.0-R0)*pow((1.0-c), 4.0);
    pixelColor += R*totalReflColor + (1.0-R)*totalRefrColor;

    Vector3f c_ambient = _scene.getAmbientLight();
    pixelColor += k_d*c_ambient;
    return pixelColor;
}
