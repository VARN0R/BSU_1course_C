#pragma once
#define N 10000000
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

template<typename T>
class Vector {
private:
    T* elements;
    int size;
public:
    //список инициализации членов
    Vector() : elements(nullptr), size(0) {}
    
    //конструктор, создает вектор заданного размера.
    Vector(int size) : elements(new T[size]), size(size) {}
    
    //конструктор копирования, создает вектор, который является копией другого вектора.
    Vector(const Vector& other) : elements(new T[other.size]), size(other.size) {
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    
    Vector(Vector&& other) : elements(other.elements), size(other.size) {
        other.elements = nullptr;
        other.size = 0;
    }

     ~Vector() {
        delete[] elements;
    }
    
    //оператор присваивания, который позволяет скопировать один вектор в другой.
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] elements;
            elements = new T[other.size];
            size = other.size;
            for (int i = 0; i < size; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }
    
    Vector& operator=(Vector&& other) {
    if (this != &other) {
        delete[] elements;
        elements = other.elements;
        size = other.size;
        other.elements = nullptr;
        other.size = 0;
        }
        return *this;
    }

    //оператор доступа к элементам вектора по индексу.
    T& operator[](int index) {
        return elements[index];
    }

    const T& operator[](int index) const {
        return elements[index];
    }

    int getsize() const {
        return size;
    }

    void fillrand() {
        
        // инициализируем генератор случайных чисел с помощью текущего времени
        srand(time(nullptr));
        for (int i = 0; i < size; i++) {
            elements[i] = rand();
        }
    }

    void resize(int newSize) {
        T* newElements = new T[newSize];
        T copySize = newSize < size ? newSize : size;
        for (int i = 0; i < copySize; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        size = newSize;
    }
    
    void push_back(int element) {
        T* newElements = new T[size + 1];//увеливаем размер на один
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];//копируем старые элементы в новые
        }
        newElements[size] = element;//новый элемент в конец вектора
        delete[] elements;//освобождаем память
        elements = newElements;//присваиваем указатель на новую память
        size++;
    }
};