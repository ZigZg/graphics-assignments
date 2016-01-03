#ifndef PLANE_H
#define PLANE_H

#include "Object3D.h"

#include <vecmath.h>
#include <cmath>

// TODO: Implement Plane representing an infinite plane
// Choose your representation, add more fields and fill in the functions
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

    virtual bool intersect(const Ray &r, float tmin, Hit &h) const 
    {
        Vector3f R_zero = r.getOrigin();
        Vector3f R_d = r.getDirection();
        float denominator = Vector3f::dot(normal, R_d);
        float t;
        if (denominator == 0) {
        	return false;
        } else {
        	t = (d-Vector3f::dot(normal, R_zero))/denominator;
        }
        float current_t = h.getT();
        if (t >= tmin && t < current_t) {
        	h.set(t, material, normal);
        } else {
        	return false;
        }
    }

 private:
 	Vector3f normal;
 	float d;
 	Material *material;
};
#endif //PLANE_H


