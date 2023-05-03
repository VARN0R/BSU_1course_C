#pragma once
#include <iostream>
#include <cstring>

class MyString{
    int length;
    char* data;
public:
    //конструктор по умолчанию
    MyString();

    //конструктор с параметром
    MyString (const char* str);

    //конструктор копирования
    MyString(const MyString& other);

    //конструктор перемещения
    MyString (MyString&& other);

    //деструктор
    ~MyString();

    MyString& operator=(const MyString& other);

    MyString& operator=(MyString&& other);

    friend std::istream& operator>>(std::istream& in, MyString& str);

    friend std::ostream& operator<<(std::ostream& out, MyString& str);

    void insert(char ch, int pos);

    void deleteLeadSpaces();

    void addChar(const MyString& other);
 };