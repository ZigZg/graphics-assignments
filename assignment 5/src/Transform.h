#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Object3D.h"
#include "vecmath.h"

// TODO implement this class
// So that the intersect function first transforms the ray
// Add more fields as necessary
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

    virtual bool intersect(const Ray &r, float tmin, Hit &h) const
    {
        Vector4f r0_w = Vector4f(r.getOrigin(), 1.0f);
        Vector4f rd_w = Vector4f(r.getDirection(), 0.0f);
        Matrix4f M_inverse = M.inverse(NULL, std::numeric_limits<float>::min()); //figure out how to do this
        //M_inverse.print();

        Vector4f r0_o4 = M_inverse*r0_w;
        Vector4f rd_o4 = M_inverse*rd_w;
        Vector3f r0_o = Vector3f(r0_o4[0], r0_o4[1], r0_o4[2]);
        Vector3f rd_o = Vector3f(rd_o4[0], rd_o4[1], rd_o4[2]);
        Ray new_ray = Ray(r0_o, rd_o);

        bool intersect = _object->intersect(new_ray, tmin, h);
        if (intersect) {
          float t = h.getT();
          Vector4f normal = Vector4f(h.getNormal(), 0.0f);
          Material * material = h.getMaterial();
          Matrix4f M_inverse_transpose = M_inverse.transposed();
          Vector4f newNormal4 = M_inverse_transpose*normal;
          Vector3f newNormal = Vector3f(newNormal4[0], newNormal4[1], newNormal4[2]);
          h.set(t, material, newNormal.normalized());
        }
        return intersect;
    }

  protected:
    Matrix4f M;
    Object3D *_object; //un-transformed object	
};

#endif //TRANSFORM_H
