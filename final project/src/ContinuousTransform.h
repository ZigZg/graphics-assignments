#ifndef CONTINUOUSTRANSFORM_H
#define CONTINUOUSTRANSFORM_H

#include "Transform.h"
#include "Object3D.h"
#include "vecmath.h"

//Represents a Transform object that can be rotated continuously
class ContinuousTransform: public Transform
{
  public: 
    ContinuousTransform(const Matrix4f &m, 
              Object3D *obj, float increment) :
        Transform(m, obj) 
    {
        _rotationM = Matrix4f::rotateZ(increment);
    }

    // simply updates the rotation matrix by applying the update matrix
    virtual void updateAngle() {
        //this->M is inherited from the Transform class
        this->M = this->M*_rotationM;
    }

  protected:
    Matrix4f _rotationM; // represents the update matrix that rotates the object
                         // by a certain angle
};

#endif //CONTINUOUSTRANSFORM_H
