#include "Car.h"

void Car::setColor(const char* col){
    strcpy_s(color, STR_LIM, col);
}

char* Car::getColor(){
    return color;
}

void Car::setNumber(const char* num){
    strcpy_s(number, STR_LIM, num);
} 

char* Car::getNumber(){
    return number;
}

void Car::setIsTaxi(bool tax){
    isTaxi = tax;
}

bool Car::getIsTaxi(){
    return isTaxi;
}

Car::Car() : color(new char [STR_LIM]), number(new char [STR_LIM]), isTaxi(false) {
}

Car::Car(int x1, int y1, int x2, int y2, const char* c, const char* n, bool taxi)
    : ObjectBase(x1, y1, x2, y2), isTaxi(taxi), color(new char [STR_LIM]), number(new char [STR_LIM]) {
    strcpy_s(color, STR_LIM, c);
    strcpy_s(number, STR_LIM, n);
}

Car::Car(const Car& other) : ObjectBase(other), isTaxi(other.isTaxi){
    strcpy_s(color, STR_LIM, other.color);
    strcpy_s(number, STR_LIM, other.number); 
}

Car::Car(Car&& other) noexcept: ObjectBase(std::move(other)) {
    swap(color, other.color);
    swap(number, other.number);
    swap(isTaxi, other.isTaxi);
}

void Car::operator=(const Car& other) {
    ObjectBase::operator=(other);
    strcpy_s(color, STR_LIM, other.color);
    strcpy_s(number, STR_LIM, other.number);
    isTaxi = other.isTaxi; 
}

void Car::operator=(Car&& other) noexcept {
    ObjectBase::operator=(std::move(other));
    swap(color, other.color);
    swap(number, other.number);
    swap(isTaxi, other.isTaxi);
}

string Car::getType() const {
    return "Car\n";
}

void Car::printDetails() const {
    ObjectBase::printDetails();
    cout << "Color: " << color << "\n";
    cout << "Number: " << number << "\n";
    cout << "Is Taxi: " << (isTaxi ? "Yes" : "No") << "\n";

}

Car::~Car() {
    delete[] color;
    delete[] number;
}

