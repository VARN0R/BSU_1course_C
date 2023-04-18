#include<bits/stdc++.h>
#include "laba1.3.variant2.h"
using namespace std;

int *ReturnMaxValue(int* Array, int amount_elements){
	int *max_element = nullptr;
	int *max_element_array = Array;
	for (int i = 0; i < amount_elements; i++){
		if(Array[i]>*max_element_array){
			max_element_array = Array + i;
		}
		if (Array[i+2]==Array[i]+Array[i+1]){
			if(!max_element || Array[i+2]>*max_element){
			max_element = Array+i+2;
			}
		}
	}

	if (max_element != nullptr){
		static bool hasPrinted = false;//Чтобы при вызове функции сout отображался только один раз
		if (!hasPrinted){
            cout << "The maximum Fibonacci number before changing the array: " << endl;
            hasPrinted = true;
		}
		return max_element;

	}
	else{
		static bool hasPrinted = false;
		if (!hasPrinted){
            cout << "The maximum number of the array before it is changed(No Fibonacci numbers found): " << endl;
            hasPrinted = true;
		}
		return max_element_array;
	}	
}