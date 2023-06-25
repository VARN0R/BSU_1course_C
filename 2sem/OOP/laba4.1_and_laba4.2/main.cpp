#include "includes.h"
#include "ObjectBase.h"
#include "Person.h"
#include "Cyclist.h"
#include "Car.h"
#include "Bag.h"
#include "vector.h"
using namespace std;

int main() {
    Vector entities;
    entities.push_back(new Person (10, 20, 100, 150, "Male", NOT_PRESENT, NOT_PRESENT, NOT_PRESENT));
    entities.push_back(new Cyclist (50, 60, 200, 250, "Female", NOT_PRESENT, NOT_PRESENT, NOT_PRESENT, "Red"));
    entities.push_back(new Bag (80, 70, 150, 160, "Morning"));
    entities.push_back(new Car (120, 90, 300, 200, "Blue", "ABC123", true));

    for (int i = 0; i < entities.getsize(); i++) {
        cout << entities[i];
        cout << "-----------------\n";
    }

    cout << endl;
    cout << endl;

    Bag* bag1 = new Bag(1,2,3,4,"Morning");
    Bag* bag2 = new Bag(5,7,8,10, "evening");
    *bag2 = std::move(*bag1);
    cout << bag2->getXMAX();
    cout << bag1->getXMAX();
    
    return 0;
}
