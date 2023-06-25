#include "includes.h"
#include "ObjectBase.h"
#include "Vector.h"

//конструктор копирования, создает вектор, который является копией другого вектора.
Vector::Vector(const Vector& other) : elements(new ObjectBase*[other.size]), size(other.size) {
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
    realSize = other.realSize;
}

Vector::~Vector() {
    for (int i = 0; i < realSize; i++) {
        delete elements[i];
    }
    delete[] elements;
}

//оператор присваивания, который позволяет скопировать один вектор в другой.
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        elements = new ObjectBase*[other.size];
        size = other.size;
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
        realSize = other.realSize;
    }
    return *this;
}

//оператор доступа к элементам вектора по индексу.
ObjectBase& Vector::operator[](int index) {
    if (index >= realSize) {
        throw "fuck";
    }
    return *elements[index];
}

int Vector::getsize() {
    return realSize;
}

void Vector::resize(int newSize) {
    ObjectBase** newElements = new ObjectBase*[newSize];
    int copySize = newSize < size ? newSize : size;
    for (int i = 0; i < copySize; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    size = newSize;
}

void Vector::push_back(ObjectBase* element) {
    if (realSize == size) {
        resizeAndAdd(element);
        return;
    }
    elements[realSize] = element;
    realSize++;        
}

void Vector::remove(int ind) {
    delete elements[ind];
    size--;
    realSize--;
    for (int i = ind; i < realSize; i++) {
        elements[i] = elements[i + 1];
    }
}

void Vector::resizeAndAdd(ObjectBase* element) {
    ObjectBase** newElements = new ObjectBase*[size + 1];//увеливаем размер на один
    for (int i = 0; i < realSize; i++) {
        newElements[i] = elements[i];//копируем старые элементы в новые
    }
    newElements[realSize] = element;//новый элемент в конец вектора
    delete[] elements;//освобождаем память
    elements = newElements;//присваиваем указатель на новую память
    size++;
    realSize++;
}
