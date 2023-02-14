#include<bits/stdc++.h>
#include "laba1.3.h"
using namespace std;
int main(){
int amount_elements;

cout << "Enter amount elements of array" << endl;
cin >> amount_elements;

int* Array = new int [amount_elements];
cout << "Enter elements of array" << endl;
for (int i = 0; i < amount_elements; i++){
	cin >> Array[i];
}

cout<< *ReturnMaxValue(Array, amount_elements) << endl;
*ReturnMaxValue(Array, amount_elements) = 0;

cout << "Modified array: " << endl;
for (int i = 0; i < amount_elements; i++){
	cout << Array[i] << " ";	
}
return 0;
}