#include "Person.h"  

Person::Person(int x1, int y1, int x2, int y2, const char* g, 
    RecognitionStatus c, RecognitionStatus gl, RecognitionStatus b)
    : ObjectBase(x1, y1, x2, y2), gender(new char[STR_LIM]) {
    strcpy_s(gender, STR_LIM, g);
    child = c;
    glasses = gl;
    beard = b;
}

Person::Person(Person&& other) noexcept 
    : ObjectBase(std::move(other)) {
    swap(gender, other.gender); 
    swap(child, other.child); 
    swap(glasses, other.glasses);
    swap(beard, other.beard); 
}

void Person::operator=(const Person& other) {
    ObjectBase::operator=(other);
    strcpy_s(gender, STR_LIM, other.gender);
    child = other.child; 
    glasses = other.glasses;
    beard = other.beard;
}

void Person::operator=(Person&& other) noexcept {
    ObjectBase::operator=(std::move(other));
    swap(gender, other.gender); 
    swap(child, other.child); 
    swap(glasses, other.glasses);
    swap(beard, other.beard); 
}

char* Person::getGender() {
    return gender;
}

string Person::getChild() {
    return getStatusName(child);
}

string Person::getGlasses() {
    return getStatusName(glasses);
}

string Person::getBeard() {
    return getStatusName(beard);
}

void Person::setGender(const char* newGen) {
    strcpy_s(gender, STR_LIM, newGen);
}

void Person::setChild(RecognitionStatus rs) {
    child = rs;
}

void Person::setBeard(RecognitionStatus rs) {
    beard = rs;
}

void Person::setGlasses(RecognitionStatus rs) {
    glasses = rs;
}

    string Person::getType() const{
    return "Person\n";
}

void Person::printDetails() const {
    ObjectBase::printDetails();
    cout << "Gender: " << gender << "\n";
    cout << "Child: " << getStatusName(child)  << "\n";
    cout << "Glasses: " << getStatusName(glasses) << "\n";
    cout << "Beard: " << getStatusName(beard) << "\n";
}

Person::~Person() {
    delete[] gender;
}
