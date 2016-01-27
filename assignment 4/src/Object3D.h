#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "Ray.h"
#include "Hit.h"
#include "Material.h"

#include <string>

class Object3D
{
  public:
    // Constructor
    Object3D()
    {
        material = NULL;
    }

    // Destructor
    virtual ~Object3D() {}

    Object3D(Material *material)
    {
        this->material = material;
    }

    const std::string & getType() const {
        return type;
    }

    // returns the material
    Material * getMaterial() const {
        return material;
    }

    //checks if specified ray intersects with object
    virtual bool intersect(const Ray &r, float tmin, Hit &h) const = 0;

  private:
    std::string type;
    Material *material;
};

#endif
