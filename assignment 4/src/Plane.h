#ifndef PLANE_H
#define PLANE_H

#include "Object3D.h"

#include <vecmath.h>
#include <cmath>

class Plane: public Object3D
{
  public:
    Plane(const Vector3f &normal, float d, Material *m) :
        Object3D(m)
    {
    	this->normal = normal;
    	this->d = d;
    	this->material = m;
    }

    // parametric equation for ray: P(t) = R_0 + t*R_d (point = origin + direction*parameter)
    // implicit plane equation: dot(normal, P) - d = 0 (P = point)
    // combined equations: dot(normal, R_0) + t*dot(normal, R_d) - d
    // solving for t: t = (d-dot(normal, R_0))/(dot(normal, R_d))
    virtual bool intersect(const Ray &r, float tmin, Hit &h) const 
    {
        Vector3f R_zero = r.getOrigin();
        Vector3f R_d = r.getDirection();
        float denominator = Vector3f::dot(normal, R_d);
        float t;
        if (denominator == 0) {
            // ray is parallel to plane
        	return false;
        } else {
        	t = (d-Vector3f::dot(normal, R_zero))/denominator;
        }

        // update hit to reflect closest value of t
        float current_t = h.getT();
        if (t >= tmin && t < current_t) {
        	h.set(t, material, normal);
        } else {
        	return false;
        }
    }

 private:
 	Vector3f normal;
 	float d; //offset of plane from origin
 	Material *material;
};
#endif //PLANE_H


