#pragma once
#include "includes.h"
#include "ObjectBase.h"

class Vector {
private:
    ObjectBase** elements;
    int size;
    int realSize = 0;
public:
    //список инициализации членов
    Vector() : elements(nullptr), size(0) {}
    
    //конструктор, создает вектор заданного размера.
    Vector(int size) : elements(new ObjectBase*[size]), size(size) {}
    
    //конструктор копирования, создает вектор, который является копией другого вектора.
    Vector(const Vector& other);
    
    ~Vector();
    
    //оператор присваивания, который позволяет скопировать один вектор в другой.
    Vector& operator=(const Vector& other);
    
    //оператор доступа к элементам вектора по индексу.
    ObjectBase& operator[](int index);

    int getsize();

    void resize(int newSize);
    
    void push_back(ObjectBase* element);

    void remove(int ind);
private:
    void resizeAndAdd(ObjectBase* element);
};