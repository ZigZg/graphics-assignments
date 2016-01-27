#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Object3D.h"
#include "vecmath.h"

class Transform: public Object3D
{
  public: 
    Transform(const Matrix4f &m, 
              Object3D *obj) :
        _object(obj) 
    {
      this->M = m;
      this->_object = obj;
    }

    // transforms ray, then tests for intersection in the usual way
    virtual bool intersect(const Ray &r, float tmin, Hit &h) const
    {
        Matrix4f M_inverse = M.inverse(NULL, std::numeric_limits<float>::min());

        // M is 4x4, so change all vectors to contain 4 elements
        Vector4f r0 = Vector4f(r.getOrigin(), 1.0f);
        Vector4f rd = Vector4f(r.getDirection(), 0.0f);

        // transform ray
        Vector4f r0_inverse_4 = M_inverse * r0;
        Vector4f rd_inverse_4 = M_inverse * rd;

        // transform back to 3-element vectors, create new ray
        Vector3f r0_inverse = Vector3f(r0_inverse_4[0], r0_inverse_4[1], r0_inverse_4[2]);
        Vector3f rd_inverse = Vector3f(rd_inverse_4[0], rd_inverse_4[1], rd_inverse_4[2]);
        Ray new_ray = Ray(r0_inverse, rd_inverse);

        // check for intersection
        bool intersect = _object->intersect(new_ray, tmin, h);
        if (intersect) {
          float t = h.getT();
          Material * material = h.getMaterial();

          // normal transformed by multiplying with the transpose of the inverse of M
          Vector4f normal = Vector4f(h.getNormal(), 0.0f);
          Matrix4f M_inverse_transpose = M_inverse.transposed();
          Vector4f newNormal_4 = M_inverse_transpose * normal;
          Vector3f newNormal = Vector3f(newNormal_4[0], newNormal_4[1], newNormal_4[2]);
          h.set(t, material, newNormal.normalized());
        }
        return intersect;
    }

  protected:
    Matrix4f M;
    Object3D *_object; //un-transformed object	
};

#endif //TRANSFORM_H
