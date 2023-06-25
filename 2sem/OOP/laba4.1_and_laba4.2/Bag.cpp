#include "Bag.h"

Bag::Bag() : timeOfDay(new char [STR_LIM]) {
}

Bag::Bag(int x1, int y1, int x2, int y2, const char* time)
    : ObjectBase(x1, y1, x2, y2), timeOfDay(new char [STR_LIM]) {
    strcpy_s(timeOfDay, STR_LIM, time);
}

Bag::Bag(const Bag& other) : ObjectBase(other) {
    strcpy_s(timeOfDay, STR_LIM, other.timeOfDay);
}

Bag::Bag(Bag&& other) noexcept: ObjectBase(std::move(other)) {
    swap(timeOfDay, other.timeOfDay);
}

void Bag::operator=(const Bag& other){
    ObjectBase::operator=(other);
    strcpy_s(timeOfDay, STR_LIM, other.timeOfDay);
}

void Bag::operator=(Bag&& other) noexcept{
    ObjectBase::operator=(std::move(other));
    swap(timeOfDay, other.timeOfDay);
}

string Bag::getType() const {
    return "Bag\n";
}

void Bag::printDetails() const {
    ObjectBase::printDetails();
    cout << "Time of Day: " << timeOfDay << "\n";
}

Bag::~Bag() {
    delete[] timeOfDay;
}

