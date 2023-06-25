#pragma once
#include "includes.h"
#include "Person.h"
#include "ObjectBase.h"

class Cyclist : public Person {
protected:
    char* bikeColor; 
public:
    Cyclist();
    
    Cyclist(int x1, int y1, int x2, int y2, 
    const char* g, 
    RecognitionStatus c, 
    RecognitionStatus gl,  
    RecognitionStatus b, 
    const char* bc);

    Cyclist(const Cyclist& other);

    Cyclist(Cyclist&& other) noexcept;

    void operator=(const Cyclist& other);

    void operator=(Cyclist&& other) noexcept;
    
    void setBikeColor(const char* bc);

    char* getBikeColor();

    string getType() const override;

    void printDetails() const override;

    ~Cyclist();
};
