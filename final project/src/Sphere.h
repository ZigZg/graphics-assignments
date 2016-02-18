#ifndef SPHERE_H
#define SPHERE_H

#include "Object3D.h"

#include <vecmath.h>
#include <cmath>
#include <algorithm>

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

    // parametric equation for ray: P(t) = R_0 + t*R_d (point = origin + direction*parameter)
    // implicit equation for sphere: dot(P, P) - r^2 = 0 (P = point, r = radius)
    // combined equations: dot(R_d, R_d)*t^2 + 2*dot(R_d, R_0)*t + dot(R_0, R_0) - r^2 = 0
    // use quadratic equation to find t
    virtual bool intersect(const Ray &r, float tmin, Hit &h) const
    {
        Vector3f R_zero = r.getOrigin();
        Vector3f R_d = r.getDirection();
        //includes calculations to account for non-zero sphere center
        float a = Vector3f::dot(R_d, R_d);
        float b = 2 * Vector3f::dot(R_zero, R_d) - 2 * Vector3f::dot(R_d, center);
        float c = Vector3f::dot(R_zero, R_zero) - pow(radius, 2.0) - 2 * Vector3f::dot(R_zero, center) + Vector3f::dot(center, center);
        float d_squared = pow(b, 2.0) - 4*a*c;
        float t;
        if (d_squared > 0){
          // ray intersects sphere at two points
          float t_minus = (-b - sqrt(d_squared))/(2.0 * a); 
          float t_plus = (-b + sqrt(d_squared))/(2.0 * a);
          t = std::min(t_minus, t_plus);
          if (t<=tmin) {
            // first intersection point is behind the camera, i.e. camera is inside the sphere
            t = std::max(t_minus, t_plus);
          }
        } else if (d_squared == 0) {
          // ray intersects sphere at one point
          t = (-b)/(2.0 * a);
        } else {
          // ray doesn't intersect sphere
          return false;
        }
        float current_t = h.getT();
        if (t>=tmin && t < current_t) {
          // the sphere is now the closest object (and isn't behind the camera)
          Vector3f Q = r.pointAtParameter(t)-center;
          Vector3f normal = Q.normalized();
          // update the hit object to reflect the new, closer value of t
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
