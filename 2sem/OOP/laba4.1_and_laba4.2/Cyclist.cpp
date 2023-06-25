#include "Cyclist.h"

Cyclist::Cyclist() : bikeColor(new char [STR_LIM]) {
}

Cyclist::Cyclist(int x1, int y1, int x2, int y2, 
const char* g, 
RecognitionStatus c, 
RecognitionStatus gl,  
RecognitionStatus b, 
const char* bc)
    : Person(x1, y1, x2, y2, g, c, gl, b), bikeColor(new char [STR_LIM]) {
    strcpy_s(bikeColor, STR_LIM, bc);
    
}

Cyclist::Cyclist(const Cyclist& other) : Person(other){
    strcpy_s(bikeColor, STR_LIM, other.bikeColor);
}

Cyclist::Cyclist(Cyclist&& other) noexcept : Person(std::move(other)){
    swap(bikeColor, other.bikeColor);
}

void Cyclist::operator=(const Cyclist& other) {
    Person::operator=(other);
    strcpy_s(bikeColor, STR_LIM, other.bikeColor);
}

void Cyclist::operator=(Cyclist&& other) noexcept {
    Person::operator=(std::move(other));
    swap(bikeColor, other.bikeColor);
}

void Cyclist::setBikeColor(const char* bc){
    strcpy_s(bikeColor, STR_LIM, bc);
}

char* Cyclist::getBikeColor(){
    return bikeColor;
}

string Cyclist::getType() const {
    return "Cyclist\n";
}

void Cyclist::printDetails() const {
    Person::printDetails();
    cout << "Bike Color: " << bikeColor << "\n";
}

Cyclist::~Cyclist() {
    delete[] bikeColor;
}

