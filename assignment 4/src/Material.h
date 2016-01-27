#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>
#include <algorithm>

#include "Hit.h"
#include "Ray.h"
#include "Texture.h"

class Material
{
  public:
    Material(const Vector3f &diffuseColor,
             const Vector3f &specularColor = Vector3f::ZERO, 
             float shininess = 0) :
        _diffuseColor(diffuseColor),
        _specularColor(specularColor), 
        _shininess(shininess)
    {
    }

    virtual ~Material()
    {
    }

    virtual const Vector3f & getDiffuseColor() const 
    { 
        return _diffuseColor;
    }

    // diffuse shading component
    float
    clampDiffuse(const Vector3f &dirToLight, const Vector3f &normal)
    {
        return std::max(Vector3f::dot(dirToLight, normal), 0.0f);
    }

    // specular component in Phong shading model
    float
    clampSpecular(const Vector3f &dirToLight, const Vector3f &dirReflect) {
        float dotProduct = Vector3f::dot(dirToLight, dirReflect)
        if (dotProduct > 0) {
            return pow(dotProduct, _shininess);
        } else {
            return 0;
        }
    }

    //shade as a result of a single light
    Vector3f shade(const Ray &ray, 
                   const Hit &hit,
                   const Vector3f &dirToLight, 
                   const Vector3f &lightColor) 
    {
        Vector3f d = ray.getDirection();
        Vector3f normal = hit.getNormal();
        Vector3f k_d = _diffuseColor;

        // calculates direction of reflected ray
        Vector3f dirReflect = d - 2 * Vector3f::dot(d, normal) * normal;

        // if the material has a texture, get the color at the texture's corresponding uv coordinates
        if(_texture.isValid()) {
            Vector2f uv = hit.getTexCoord();
            k_d = _texture.getTexel(uv[0], uv[1]);
        }

        return clampDiffuse(dirToLight, normal) * lightColor * k_d + clampSpecular(dirToLight, dirReflect) * lightColor * _specularColor;
    }

    void loadTexture(const std::string &filename)
    {
        _texture.load(filename);
    }

  private:
    Vector3f _diffuseColor;
    Vector3f _specularColor;
    float _shininess;
    Texture _texture;
};

#endif // MATERIAL_H
