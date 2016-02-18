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
#include <string>

// NOTE: most (if not all) of the mathematics behind the code here can be found in the assignment 5 handout

Renderer::Renderer(const ArgParser &args) :
    _args(args),
    _scene(args.input_file)
{
}

Renderer::~Renderer()
{
}

// gets a ray's reflected direction
Vector3f 
mirrorDirection(const Vector3f &normal, const Vector3f &incoming)
{
    return incoming - 2 * (Vector3f::dot(incoming, normal)) * normal;
}

// gets a ray's transmitted direction
bool
transmittedDirection(const Vector3f &normal, 
                     const Vector3f &incoming, 
                     float index_i,
                     float index_t, 
                     Vector3f &transmitted)
{
    float sqrtValue =  1.0 - (pow(index_i, 2.0) * (1.0 - pow(Vector3f::dot(incoming, normal), 2.0)))/pow(index_t, 2.0);
    if (sqrtValue >= 0){
        transmitted = ((index_i * (incoming - normal * Vector3f::dot(incoming, normal)))/index_t - normal*sqrt(sqrtValue)).normalized();
        return true;
    } else {
        return false;
    }
}

// creates a motion blur, either horizontal or vertical
void blur(const Image &oldImage, Image &newImage, bool horizontal) {
    float K [5] = {0.1201, 0.2339, 0.2931, 0.2339, 0.1201};
    int width = oldImage.getWidth();
    int height = oldImage.getHeight();
    if (!horizontal) {
        int oldWidth = width;
        width = height;
        height = oldWidth;
    }
    for (float x=0.0; x<width; x++) {
        for (float y=0.0; y<height; y++) {
            float minusTwo = std::max(y-2, 0.0f);
            float minusOne = std::max(y-1, 0.0f);
            float plusOne = std::min(y+1, height-1.0f);
            float plusTwo = std::min(y+2, height-1.0f);
            if (horizontal) {
                Vector3f newColor = oldImage.getPixel(x, minusTwo)*K[0] + oldImage.getPixel(x, minusOne)*K[1] + oldImage.getPixel(x, y)*K[2] + oldImage.getPixel(x, plusOne)*K[3] + oldImage.getPixel(x, plusTwo) * K[3];
                newImage.setPixel(x, y, newColor);
            } else {
                Vector3f newColor = oldImage.getPixel(minusTwo, x)*K[0] + oldImage.getPixel(minusOne, x)*K[1] + oldImage.getPixel(y, x)*K[2] + oldImage.getPixel(plusOne, x)*K[3] + oldImage.getPixel(plusTwo, x) * K[3];
                newImage.setPixel(y, x, newColor);
            }
        }
    }
}

// gets a pixel's neighbors
std::vector<Vector2f> getNeighbors(float width, float height, float x, float y) {
    std::vector<Vector2f> neighbors;
    // "neighbors" vector will also contain the center pixel (the one whose neighbors we're looking for)

    // looks at x-1, x, and x+1
    for (float i=0.0; i<3.0; i++) {
        float neighbor_x = x+i-1;
        if (neighbor_x >= 0.0f && neighbor_x < width) {
            // investigate each of the pixels with this x-value
            // looks at y-1, y, and y+1
            for (float j=0.0; j<3.0; j++) {
                float neighbor_y = y+j-1;
                if (neighbor_y >= 0.0f && neighbor_y < height) {
                    // neighbor lies within image boundaries, push coordinates to the vector
                    neighbors.push_back(Vector2f(neighbor_x, neighbor_y));
                }
            }
        }
    }
    return neighbors;
}

// computes the average color of all of a pixel's neighbors
Vector3f getAverageColor(Image &image, int x, int y) {
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<Vector2f> neighbors = getNeighbors(width, height, x, y);
    Vector3f localColor = Vector3f::ZERO;
    // adds together all the neighbors' colors
    for (float i=0.0; i<neighbors.size(); i++) {
        Vector2f neighbor = neighbors[i];
        localColor += image.getPixel(neighbor[0], neighbor[1]);
    }
    // divides total color by number of neighbors to average the color out
    localColor = Vector3f(localColor[0]/neighbors.size(), localColor[1]/neighbors.size(), localColor[2]/neighbors.size());
    return localColor;
}

void
Renderer::Render()
{
    // This is the main loop that should be based on your assignment 4 main
    // loop. You will need to modify it to switch from ray casting to ray
    // tracing, to cast shadows and anti-aliasing (via jittering and
    // filtering).

    // retrieves constants from _args
    int width = _args.width;
    int height = _args.height;
    if (_args.jitter) {
        // triples the dimensions if jitter is on
        width *= 3;
        height *= 3;
    }
    float minDepth = _args.depth_min;
    float maxDepth = _args.depth_max;

    Camera * camera = _scene.getCamera();
    Group * group = _scene.getGroup();
    float tmin = camera->getTMin();

    // create a series of images (usually to showcase a continuous rotation)
    for(int n=0; n < 1; n++){
        // get the number appended to the end of the filename
        std::string n_str = std::to_string(n+1);

        bool depthFile = !_args.depth_file.empty();
        bool normalFile = !_args.normals_file.empty();

        // three image types: the output image, a depth visualization image, and a normal visualization image
        Image output = Image(width, height); //should instantiate image of black pixels
        Image depth = Image(0, 0);
        Image normal = Image(0, 0);

        // divide the filename between the name (e.g. "output") and the extension (e.g. ".png")
        std::string outputName = _args.output_file.substr(0, _args.output_file.size()-4);
        std::string outputExt = _args.output_file.substr(_args.output_file.size() - 4, 4);
        // combine them with the number to get the whole filename (e.g. "output1.png")
        std::string outputFilename = outputName + n_str + outputExt;

        // if no "depth" argument specified in command line, don't make depth image
        std::string depthFilename;
        if (depthFile) {
            depth = Image(width, height);
            std::string depthName = _args.depth_file.substr(0, _args.depth_file.size()-4);
            std::string depthExt = _args.depth_file.substr(_args.depth_file.size()-4, 4);
            depthFilename = depthName + n_str + depthExt;
        }

        // if no "normal" argument specified in command line, don't make normal image
        std::string normalFilename;
        if (normalFile) {
            normal = Image(width, height);
            std::string normalName = _args.normals_file.substr(0, _args.normals_file.size()-4);
            std::string normalExt = _args.normals_file.substr(_args.normals_file.size()-4, 4);
            normalFilename = normalName + n_str + normalExt;
        }

        //for each pixel
        for (float x=0.0; x<width; x++){
            for (float y=0.0; y<height; y++) {
                //instantiate a hit object
                Hit h = Hit();

                //instantiate a ray object
                // r_i and r_j are offset values; randomly generated and used if jitter is on
                float r_i = 0.0;
                float r_j = 0.0;
                if (_args.jitter) {
                    r_i = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) - 0.5;
                    r_j = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) - 0.5;
                }
                Ray ray = camera->generateRay(Vector2f(2*(x+r_i)/width-1, 2*(y+r_j)/height-1));

                //gets the background color
                Vector3f backgroundColor = _scene.getBackgroundColor(ray.getDirection());

                //goes through each object in the group, checks if it intersects with the ray, and updates
                // the hit object accordingly
                bool intersect = group->intersect(ray, tmin, h);
                
                if (intersect) {
                    float t = h.getT();
                    Material * material = h.getMaterial();
                    Vector3f pixelColor = traceRay(ray, tmin, 0.0, 1.0, h);
                    output.setPixel(x, y, pixelColor);

                    // calculates greyscale value for depth visualization
                    if (depthFile) {
                        float interval = maxDepth-minDepth;
                        float greyscale = (t-minDepth)/interval;
                        depth.setPixel(x, y, Vector3f(1-greyscale));
                    }

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
        if (_args.filter) {
            Image outputBlur = Image(width, height);
            blur(output, outputBlur, true);
            blur(output, outputBlur, false);
            int newWidth = width/3;
            int newHeight = height/3;
            Image outputBlurDown = Image(newWidth, newHeight);

            //assumes that jittering is also on as well
            for (int x=1; x<width; x+=3){
                for (int y=1; y<height; y+=3) {
                    Vector3f localColor = getAverageColor(outputBlur, x, y);
                    outputBlurDown.setPixel(x/3, y/3, localColor);
                }
            }
            outputBlurDown.savePNG(outputFilename);
        } else {
            output.savePNG(outputFilename);
        }
        if (depthFile){
            depth.savePNG(depthFilename);
        }
        if (normalFile) {
            normal.savePNG(normalFilename);
        }
        // update all objects that need rotating
        group->updateAngle();
        for(int i=0;i<_scene.getNumLights();i++) {
            //get the light source
            Light * light = _scene.getLight(i);
            light->updateAngle();
        }
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
    float epsilon = 0.001f; // when tracing rays, ray origin must be slightly away from surface (displace it by epsilon)
    int maxBounces = _args.bounces;
    bool shadows = _args.shadows;
    Group * group = _scene.getGroup();
    Vector3f rayDirection = ray.getDirection();
    Vector3f normal = hit.getNormal();
    Material * material = hit.getMaterial();
    float index_t = material->getRefractionIndex();
    if (refr_index > 1) {
        // currently inside an object; ray will be going out into air, so next refraction index will be 1
        index_t = 1.0;
    }
    Vector3f newNormal = Vector3f(normal[0], normal[1], normal[2]);
    if (refr_index > index_t) {
        // currently inside a object, normal must be reversed
        newNormal *= -1;
    }

    //get the intersection point
    float t = hit.getT();
    Vector3f p = ray.pointAtParameter(t);

    int numLights = _scene.getNumLights();
    Vector3f dirToLight;
    Vector3f color;
    float distanceToLight;
    Vector3f pixelColor = Vector3f::ZERO;

    //get the shading component
    for(int i=0;i<numLights;i++) {
        //get the light source
        Light * light = _scene.getLight(i);
        // get the direction and distance to the light, and the light's color
        light->getIllumination(p, dirToLight, color, distanceToLight);

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
                pixelColor += material->shade(ray, hit, dirToLight, color);
            }
        // else do normal shading
        } else {
            pixelColor += material->shade(ray, hit, dirToLight, color);
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
            // gets the color reflected from other objects
            otherReflColor = traceRay(reflectedRay, tmin, bounces+1, refr_index, reflectedHit);
        } else {
            // gets the object's local color
            otherReflColor = k_d;
        }  
    } else {
        // gets the background color
        otherReflColor = _scene.getBackgroundColor(reflectedRay.getDirection());
    }
    Vector3f totalReflColor = reflColor*otherReflColor;

    // get the refraction component
    // check if transmission occurs
    Vector3f transmittedDir;
    bool transmitted = transmittedDirection(newNormal, rayDirection, refr_index, index_t, transmittedDir);

    // get the color from the refracted ray (if refracted)
    Vector3f refrColor;
    if (transmitted) {
        //get the transmitted ray and the associated hit object
        Ray transmittedRay = Ray(p, transmittedDir);
        Hit transmittedHit = Hit();

        // see if ray intersects any of the objects
        bool refrIntersect = group->intersect(transmittedRay, tmin+epsilon, transmittedHit);
        if (refrIntersect){
            if (bounces < maxBounces) {
                // trace ray and get the end color
                refrColor = traceRay(transmittedRay, tmin, bounces+1, index_t, transmittedHit);
            } else {
                // get the object's local color
                refrColor = k_d;
            }
        } else {
            // get the background color
            refrColor = _scene.getBackgroundColor(transmittedRay.getDirection());
        }
    } else {
        refrColor = k_d;
    }
    Vector3f totalRefrColor = reflColor*refrColor;

    //get weights for Schlick's approximation to Fresnel's equation
    float R0 = pow(((index_t - refr_index)/(index_t + refr_index)), 2.0);
    float c = clampApprox(rayDirection, normal, transmittedDir, refr_index, index_t);
    float R = R0 + (1.0 - R0) * pow((1.0 - c), 4.0);
    pixelColor += R * totalReflColor + (1.0-R) * totalRefrColor;

    Vector3f c_ambient = _scene.getAmbientLight();
    pixelColor += k_d * c_ambient;
    return pixelColor;
}
