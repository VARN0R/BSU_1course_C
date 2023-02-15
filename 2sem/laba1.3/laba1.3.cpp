#include<bits/stdc++.h>
#include "laba1.3.h"
using namespace std;

int &ReturnMaxValue(int* Array, int amount_elements){
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
        cout << "The maximum Fibonacci number before changing the array: " << endl;
        cout << *max_element << endl;
		return *max_element;
	}
	else{
		cout << "The maximum number of the array before it is changed(No Fibonacci numbers found): " << endl;
    	cout << *max_element_array << endl;
		return *max_element_array;
	}	
}