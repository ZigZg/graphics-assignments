#ifndef LIGHT_H
#define LIGHT_H

#include <Vector3f.h>

#include "Object3D.h"

#include <limits>
#include <cmath>

class Light
{
  public:
    virtual ~Light()
    {
    }

    virtual void getIllumination(const Vector3f &p, 
                                 Vector3f &dir, 
                                 Vector3f &col, 
                                 float &distanceToLight) const = 0;

    virtual void updateAngle() {};
};

class DirectionalLight : public Light
{
  public:
    DirectionalLight(const Vector3f &d, const Vector3f &c) :
        _direction(d.normalized()),
        _color(c)
    {
    }

    /// @param p unsed in this function
    /// @param distanceToLight not well defined because it's not a point light
    virtual void getIllumination(const Vector3f &p, 
                                 Vector3f &dir, 
                                 Vector3f &col, 
                                 float &distanceToLight) const
    {
        // the direction to the light is the opposite of the
        // direction of the directional light source
        dir = -_direction;
        col = _color;
        distanceToLight = std::numeric_limits<float>::max();
    }

  private:
    Vector3f _direction;
    Vector3f _color;
};

// Represents a spotlight. Width is the angle in which the light is the brighest,
// whereas the area between the falloff angle and width is where the light starts
// to fade off
class SpotLight : public Light
{
  public:
    SpotLight(const Vector3f &p, const Vector3f &d, const Vector3f &c, float width, float falloff) :
        _position(p),
        _direction(d),
        _color(c),
        _width(width),
        _falloff(falloff)
    {
    }

    ~SpotLight()
    {
    }

    //idea for how to implement this came from http://www.web3d.org/documents/specifications/19775-1/V3.3/Part01/components/lighting.html#SpotLight
    virtual void getIllumination(const Vector3f &p,
                                 Vector3f &dir,
                                 Vector3f &col,
                                 float &distanceToLight) const
    {
      // discover the direction and distance of the vector between the spotlight's
      // origin and the point of intersection for an object
      dir = _position - p;
      distanceToLight = dir.abs();
      dir = dir / dir.abs(); //normalized

      // Find the angle between the intersection point and the spotlight,
      // using the formula len(A)*len(B)*cos(theta) = dot(A, B)
      float multLen = dir.abs() * _direction.abs();
      float angle = acos(Vector3f::dot(dir, _direction)/multLen);

      // determine how intense the light should be
      float multiplier;
      if (angle >= _falloff) {
        // none if outside the spotlight range
        multiplier = 0.0f;
      } else if (angle <= _width) {
        // brightest if within width angle
        multiplier = 1.0f;
      } else {
        // fades out relative to where it is between width and falloff
        multiplier = (angle - _falloff)/(_width - _falloff);
      }
      col = _color*multiplier;
    }

  protected:
    Vector3f _position;
    Vector3f _color;
    float _falloff; //in radians
    float _width; //ditto
    Vector3f _direction;
};

// A continuously rotating spotlight - works similarly to ContinuousTransform
class RotatingSpotLight : public SpotLight
{
  public: 
    RotatingSpotLight(const Vector3f &p, const Vector3f &d, const Vector3f &c, float width, float falloff, float increment) :
        SpotLight(p, d, c, width, falloff)
        {
          _M = Matrix4f::rotateY(increment);
        }

    virtual void updateAngle() {
      _position = _M * _position;
      _direction = _M * _direction;
    }

  protected:
    Matrix4f _M;
};

class PointLight : public Light
{
  public:
    PointLight(const Vector3f &p, const Vector3f &c, float falloff) :
        _position(p),
        _color(c),
        _falloff(falloff)
    {
    }

    ~PointLight()
    {
    }

    virtual void getIllumination(const Vector3f &p, 
                                 Vector3f &dir, 
                                 Vector3f &col, 
                                 float &distanceToLight) const
    {
        // the direction to the light is the opposite of the
        // direction of the directional light source
        dir = _position - p;
        distanceToLight = dir.abs();
        dir = dir / dir.abs();
        col = _color / (1.0f + _falloff * distanceToLight * distanceToLight);
    }

  private:
    Vector3f _position;
    Vector3f _color;
    float _falloff;
};

#endif // LIGHT_H
