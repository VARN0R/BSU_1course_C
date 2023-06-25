#pragma once
#include "ObjectBase.h"
#include "includes.h"

class Car : public ObjectBase {
protected:
    char* color; 
    char* number; 
    bool isTaxi; 
public:
    void setColor(const char* col);

    char* getColor();

    void setNumber(const char* num);

    char* getNumber();

    void setIsTaxi(bool tax);

    bool getIsTaxi();

    Car();

    Car(int x1, int y1, int x2, int y2, const char* c, const char* n, bool taxi);

    Car(const Car& other);

    Car(Car&& other) noexcept;

    void operator=(const Car& other);

    void operator=(Car&& other) noexcept;

    string getType() const override;

    void printDetails() const override;

    ~Car();
};
