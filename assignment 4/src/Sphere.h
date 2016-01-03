#ifndef SPHERE_H
#define SPHERE_H

#include "Object3D.h"

#include <vecmath.h>
#include <cmath>
#include <algorithm>

// TODO:
// Implement functions and add more fields as necessary
class Sphere : public Object3D
{
  public:
    Sphere() { 
        // unit ball at the center
      center = Vector3f::ZERO;
      radius = 1.0;
      material = NULL;
    }

    Sphere(const Vector3f &center, 
           float radius, 
           Material *material) :
        Object3D(material)
    {
        this->center = center;
        this->radius = radius;
        this->material = material;
    }

    virtual bool intersect(const Ray &r, float tmin, Hit &h) const
    {
        //TODO: need to account for sphere not being at origin
        Vector3f R_zero = r.getOrigin();
        Vector3f R_d = r.getDirection();
        float a = Vector3f::dot(R_d, R_d);
        float b = 2*Vector3f::dot(R_zero, R_d) - 2*Vector3f::dot(R_d, center);
        float c = Vector3f::dot(R_zero, R_zero) - pow(radius, 2.0) - 2*Vector3f::dot(R_zero, center) + Vector3f::dot(center, center);
        float d_squared = pow(b, 2.0) - 4*a*c;
        float t;
        if (d_squared > 0){
          float t_minus = (-b - sqrt(d_squared))/(2.0*a); 
          float t_plus = (-b + sqrt(d_squared))/(2.0*a);
          t = std::min(t_minus, t_plus);
        } else if (d_squared == 0) {
          t = (-b)/(2.0*a);
        } else {
          return false;
        }
        float current_t = h.getT();
        if (t>=tmin && t < current_t) {
          Vector3f Q = r.pointAtParameter(t)-center;
          Vector3f normal = Q.normalized();
          h.set(t, material, normal);
        } else {
          return false;
        }
    }

  private:
    Vector3f center;
    float radius;
    Material *material;
};

#endif
