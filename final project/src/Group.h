#ifndef GROUP_H
#define GROUP_H

#include "Object3D.h"
#include "Ray.h"
#include "Hit.h"

#include <iostream>
#include <vector>

class Group : public Object3D
{
  public:
    // Constructor
    Group()
    {
        groupSize = 0;
    }

    Group(int size) {
        this->groupSize = size;
    }

    // Destructor
    ~Group()
    {
    }

    // Return true if intersection found
    virtual bool intersect(const Ray &r, float tmin, Hit &h) const
    {
        bool intersect = false;
        for (int i=0;i<groupSize;i++) {
            bool this_intersect = objectList[i]->intersect(r, tmin, h);
            intersect |= this_intersect;
        }
        return intersect;
    }

    // Add object to group
    void addObject(Object3D *obj)
    {
        groupSize++;
        objectList.push_back(obj);
    }

    // Update the current angle of every object (relevant for ContinuousTransforms)
    virtual void updateAngle() const {
        for(int i=0; i<groupSize; i++) {
            objectList[i]->updateAngle();
        }
    }

    // Return number of objects in group
    int getGroupSize()
    {
        return groupSize;
    }

  private:
    int groupSize;
    std::vector<Object3D*> objectList;
};

#endif
