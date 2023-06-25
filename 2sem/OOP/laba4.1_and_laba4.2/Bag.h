#pragma once
#include "ObjectBase.h"
#include "includes.h"

class Bag : public ObjectBase {
protected:
    char* timeOfDay; 
public:
    Bag();

    Bag(int x1, int y1, int x2, int y2, const char* time);

    Bag(const Bag& other);

    Bag(Bag&& other) noexcept;

    void operator=(const Bag& other);

    void operator=(Bag&& other) noexcept;

    string getType() const override;

    void printDetails() const override;

    ~Bag();
};
