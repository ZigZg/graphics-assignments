#ifndef GROUP_H
#define GROUP_H

#include "Object3D.h"
#include "Ray.h"
#include "Hit.h"

#include <iostream>
#include <vector>

/// TODO: 
/// Implement Group
/// Add data structure to store a list of Object* 
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
        groupSize++; //check if this works
        objectList.push_back(obj);
    }

    // Return number of objects in group
    int getGroupSize()
    {
        return groupSize;
    }

  private:
    int groupSize;
    std::vector<Object3D*> objectList; //check this
};

#endif
