#pragma once
#include "includes.h"
class ObjectBase {
protected:
    int xmin, ymin, xmax, ymax;
public:
    ObjectBase();
    
    ObjectBase(int x1, int y1, int x2, int y2);

    ObjectBase(const ObjectBase& other);
 
    ObjectBase(ObjectBase&& other)  noexcept;

    virtual void operator=(ObjectBase&& other) noexcept;

    virtual void operator=(const ObjectBase& other);
  
    void setXMIN(int x1);
    
    void setYMIN(int y1);

    void setXMAX(int x2);
    
    void setYMAX(int y2);

    int getXMIN();

    int getYMIN();

    int getXMAX();

    int getYMAX();


    virtual std::string getType() const = 0;
       
    virtual ~ObjectBase(); 

    virtual void printDetails() const;
    
    // Оператор реализон не очень корректно // The operator is not implemented very correctly
    friend ostream& operator<<(ostream& os, ObjectBase& g){
        g.printDetails();
        return os;
    }
};