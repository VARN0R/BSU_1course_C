/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Выполнить задание, используя C-строки для представления данных.

Заданное натуральное число от 1 до 1999 вывести римскими цифрами.
-------------------------------------------------------------------------------
ENGLISH
Perform a task using C-strings to represent data.

The given natural number from 1 to 1999 is output in Roman numerals.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <iostream>
using namespace std;
int main () {
	int valueuser = 0;
	while (valueuser<1||valueuser>1999){
		cout << "Enter a valid value(1to1999)" << endl;
		cin >> valueuser;
	}
	char String1[][3]{"M",     "CM",   "D",    "CD",   "C",    "XC",  "L",   "XL",  "X",   "IX", "V",  "IV", "I"};
	int Array[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	int Result[100]{};
	int i = 0;
	int j = 0;
	while(valueuser){
		valueuser=valueuser-Array[i];
		
		if(valueuser<0){
			valueuser=valueuser+Array[i];
			i++;
		}	
		else{
			Result[j]=i;
			j++;
		}
		
		
	}
	for (int i = 0; i < j; i++){
		cout << String1[Result[i]];
	}
	return 0;	
}