#include "ObjectBase.h"
#include <fstream>

ObjectBase::ObjectBase() : xmin(0), ymin(0), xmax(0), ymax(0) {
}

ObjectBase::ObjectBase(int x1, int y1, int x2, int y2)
    : xmin(x1), ymin(y1), xmax(x2), ymax(y2) {
}

ObjectBase::ObjectBase(const ObjectBase& other) 
    : xmin(other.xmin), ymin(other.ymin), xmax(other.xmax), ymax(other.ymax) {
}

ObjectBase::ObjectBase(ObjectBase&& other)  noexcept
{
    swap(xmin, other.xmin);
    swap(ymin, other.ymin);
    swap(xmax, other.xmax);
    swap(ymax, other.ymax);
}

void ObjectBase::operator=(ObjectBase&& other) noexcept {
    swap(xmin, other.xmin);
    swap(ymin, other.ymin);
    swap(xmax, other.xmax);
    swap(ymax, other.ymax);
}

void ObjectBase::operator=(const ObjectBase& other) {
    xmin = other.xmin;
    ymin = other.ymin;
    xmax = other.xmax;
    ymax = other.ymax;
}

void ObjectBase::setXMIN(int x1){
    xmin = x1;
}

void ObjectBase::setYMIN(int y1){
    ymin = y1;
}

void ObjectBase::setXMAX(int x2){
    xmax = x2;
}

void ObjectBase::setYMAX(int y2){
    ymax = y2;
}

int ObjectBase::getXMIN(){
    return xmin;
}

int ObjectBase::getYMIN(){
    return ymin;
}

int ObjectBase::getXMAX(){
    return xmax;
}

int ObjectBase::getYMAX(){
    return ymax;
}
    
ObjectBase::~ObjectBase() {} 

void ObjectBase::printDetails() const {
    cout << getType();
    cout << "Coordinates: (" << xmin << ", " << ymin << ") - ("
                << xmax << ", " << ymax << ")\n";
}
