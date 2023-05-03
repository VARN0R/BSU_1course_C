#include "laba2.4.h"
    
//конструктор по умолчанию
MyString::MyString() : data(nullptr), length(0){};

//конструктор с параметром
MyString::MyString (const char* str) : length(strlen(str)), data(new char[length+1]){
    strcpy_s(data, length+1, str);
}

//конструктор копирования
MyString::MyString(const MyString& other) : length(other.length), data(new char [length + 1]){
    strcpy_s(data, length+1, other.data);
} 

//конструктор перемещения
MyString::MyString (MyString&& other) : length(other.length), data(new char [length + 1]){
    strcpy_s(data,  length+1, other.data);
    other.data = nullptr;
    other.length = 0;
}

//деструктор
MyString::~MyString(){
    delete []data;
}

MyString& MyString::operator=(const MyString& other){
    if (this != &other){
        delete []data;
        length = other.length;
        data = new char[length + 1];
        strcpy_s(data, length+1, other.data);
        
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other){
    if (this != &other){
        length = other.length;
        data = new char[length + 1];
        strcpy_s(data, length+1, other.data);
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, MyString& str){
    char buffer[1024];
    in >> buffer;
    str = buffer;
    return in;
}

std::ostream& operator<<(std::ostream& out, MyString& str){
    out << str.data;
    return out;
}

void MyString::insert(char ch, int pos){
    if (pos > 0 || pos < length){
        data[pos] = ch;
    }
}

void MyString::deleteLeadSpaces(){
    int spaces = 0;
    while (data[spaces] == ' ' && spaces <= length)  {
        spaces++;
    }
    *(data+spaces-1) = '\0';
    char* leading_spaces = data;
    length -= spaces;
    data += spaces;
    delete[] leading_spaces;
}

void MyString::addChar(const MyString& other){
    int minLength = std::min(length, other.length);
    for (int i = 0; i < minLength; ++i) {
        if (data[i] == ' ' && other.data[i] != ' ') {
            insert(other.data[i], i);
        }
    }
}