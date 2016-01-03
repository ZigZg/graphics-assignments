#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object3D.h"
#include <vecmath.h>
#include <cmath>
#include <iostream>

// TODO: implement this class.
class Triangle: public Object3D
{
  public:
    Triangle(const Vector3f &a, 
             const Vector3f &b, 
             const Vector3f &c, 
             const Vector3f &na,
             const Vector3f &nb,
             const Vector3f &nc,
             Material *m) :
        Object3D(m),
        _hasTex(false)
    {
        // TODO: implement
        this->_vertices[0] = a;
        this->_vertices[1] = b;
        this->_vertices[2] = c;
        this->_normals[0] = na;
        this->_normals[1] = nb;
        this->_normals[2] = nc;
        this->material = m;
    }

    virtual bool intersect(const Ray &ray, float tmin, Hit &hit) const {
        Vector3f R_0 = ray.getOrigin();
        Vector3f R_d = ray.getDirection();

        //constants
        float ax = _vertices[0][0];
        float ay = _vertices[0][1];
        float az = _vertices[0][2];
        float bx = _vertices[1][0];
        float by = _vertices[1][1];
        float bz = _vertices[1][2];
        float cx = _vertices[2][0];
        float cy = _vertices[2][1];
        float cz = _vertices[2][2];

        float deter_A = Matrix3f::determinant3x3(ax-bx, ax-cx, R_d[0],
                              ay-by, ay-cy, R_d[1],
                              az-bz, az-cz, R_d[2]);
        if (deter_A == 0) {
          return false;
        } else {
          float beta_deter = Matrix3f::determinant3x3(ax-R_0[0], ax-cx, R_d[0],
                                            ay-R_0[1], ay-cy, R_d[1],
                                            az-R_0[2], az-cz, R_d[2]);
          float beta = beta_deter/deter_A;

          float gamma_deter = Matrix3f::determinant3x3(ax-bx, ax-R_0[0], R_d[0],
                                             ay-by, ay-R_0[1], R_d[1],
                                             az-bz, az-R_0[2], R_d[2]);
          float gamma = gamma_deter/deter_A;

          float t_deter = Matrix3f::determinant3x3(ax-bx, ax-cx, ax-R_0[0],
                                         ay-by, ay-cy, ay-R_0[1],
                                         az-bz, az-cz, az-R_0[2]);
          float t = t_deter/deter_A;

          float t_current = hit.getT();
          if (beta+gamma <= 1 && beta >= 0 && gamma >= 0 && t >= tmin && t < t_current) {
            float alpha = 1-beta-gamma;
            Vector3f normal = alpha*_normals[0] + beta*_normals[1] + gamma*_normals[2];
            if (_hasTex) {
              //get UV coordinates of intersection point
              Vector2f uv = alpha*_texCoords[0] + beta*_texCoords[1]  + gamma*_texCoords[2]; //check this
              hit.setTexCoord(uv);
            }
            hit.set(t, material, normal.normalized());
            return true;
          } else {
            return false;
          }
        }
    }

    void setTex(const Vector2f &uva,
                const Vector2f &uvb,
                const Vector2f &uvc)
    {
        _texCoords[0] = uva;
        _texCoords[1] = uvb;
        _texCoords[2] = uvc;
        _hasTex = true;
    }

    bool hasTex() const {
        return _hasTex;
    }

  private:
    bool _hasTex;
    Vector3f _vertices[3];
    Vector3f _normals[3];
    Vector2f _texCoords[3];
    Material * material;
};

#endif //TRIANGLE_H
