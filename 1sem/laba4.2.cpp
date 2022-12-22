/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Выполнить задание, используя C-строки для представления данных.

Написать программу перевода вещественных чисел из шестнадцатеричной
системы счисления в двоичную.
-------------------------------------------------------------------------------
ENGLISH
Perform a task using C-strings to represent data.

Write a program for converting real numbers from
hexadecimal to binary.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int main () {
	int valueuser = 0;
	char Result[100]{};
	
	cout <<"enter hexnum: ";
	cin >> Result;
	
	int k = strlen(Result);
	for (int j = k-1; j >= 0; j--) {
		if (Result[j]>='A')
		valueuser+=((Result[j]-'A'+10) * pow(16, k-j-1));
		else
		valueuser+=((Result[j]-'0') * pow(16, k-j-1));
	}
	
	
	int i = 0;
	do {
		Result[i] = (valueuser % 2) ? '1' : '0';
		valueuser=valueuser/2;
		i++;
	} while(valueuser);
	Result[i] = '\0';
	
	for(int i = strlen(Result); i>0; i--) {
		cout << Result[i - 1]; 
	}
	cout<<endl;
	
	return 0;	
}