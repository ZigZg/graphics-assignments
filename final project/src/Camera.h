#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"

#include <vecmath.h>
#include <float.h>
#include <cmath>

class Camera
{
  public:
    virtual ~Camera() {}

    // Generate rays for each screen-space coordinate
    virtual Ray generateRay(const Vector2f &point) = 0; 

    virtual float getTMin() const = 0; 
};

// refer to assignment handout for the directions of the "direction", "up", and "horizontal" axes (under #5 of Implementation Notes)
// (these vectors act as a coordinate system)
class PerspectiveCamera : public Camera
{
  public:
    PerspectiveCamera(const Vector3f &center, 
                      const Vector3f &direction,
                      const Vector3f &up, 
                      float angle) :
        _center(center),
        _direction(direction.normalized()),
        _up(up),
        _angle(angle)
    {
        this->_horizontal = Vector3f::cross(_direction, _up);
        _up = Vector3f::cross(_horizontal, _direction);
    }

    virtual Ray generateRay(const Vector2f &point)
    {
        //distance from camera to image plane
        float D = 1/(tan(_angle/2.0));
        // calculate direction of ray using the basis of the current coordinate system
        Vector3f dir = D*_direction.normalized() + point[0]*_horizontal.normalized() + point[1]*_up.normalized();
        return Ray(_center, dir.normalized());
    }

    virtual float getTMin() const 
    { 
        return 0.0f;
    }

  private:
    Vector3f _center; 
    Vector3f _direction;
    Vector3f _up;
    float _angle;
    Vector3f _horizontal;
};

#endif //CAMERA_H
