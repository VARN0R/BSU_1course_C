#pragma once
#include "includes.h"
#include "ObjectBase.h"

class Person : public ObjectBase {
protected:
    char* gender; 
    RecognitionStatus child; 
    RecognitionStatus glasses; 
    RecognitionStatus beard; 
public:
    Person() 
        : gender(new char[STR_LIM]), 
        child(NOT_RECOGNIZED), 
        glasses(NOT_RECOGNIZED),
        beard(NOT_RECOGNIZED) {
        }

    Person(int x1, int y1, int x2, int y2, const char* g, 
        RecognitionStatus c, RecognitionStatus gl, RecognitionStatus b);

    Person(const Person& other) 
        : ObjectBase(other),
        gender(other.gender), 
        child(other.child), 
        glasses(other.glasses),
        beard(other.beard) {}

    Person(Person&& other) noexcept;

    void operator=(const Person& other);

    void operator=(Person&& other) noexcept;

    char* getGender();

    string getChild();

    string getGlasses();

    string getBeard();

    void setGender(const char* newGen);

    void setChild(RecognitionStatus rs);

    void setBeard(RecognitionStatus rs);

    void setGlasses(RecognitionStatus rs);

    string getType() const override;

    void printDetails() const override;

    ~Person();
};