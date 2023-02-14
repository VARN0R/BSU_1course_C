/*
TASK CONDITION
-------------------------------------------------------------------------------
Напишите функцию, возвращающую ссылку на максимальное число, 
встречающееся в заданном массиве произвольного размера (аргумент функции), являющееся числом Фибоначчи. 
Если такого числа нет, то возвратить ссылку на любое из максимальных чисел массива. 
Замените значение этого элемента нулевым значением.

P.S. Я выполнил задачу, используя указатель, а не ссылку.
-------------------------------------------------------------------------------
ENGLISH
Write a function that returns a reference to the maximum number 
found in a given array of arbitrary size (function argument), which is a Fibonacci number. 
If there is no such number, then return a reference to any of the maximum numbers in the array. 
Replace the value of this element with a null value. 

P.S. I completed the task using a pointer, not a link.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
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