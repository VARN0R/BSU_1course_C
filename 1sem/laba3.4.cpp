/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Вывести последовательность dk, dk–1, ..., d0 десятичных цифр числа 3200, т.е.
такую целочисленную последовательность, в которой каждый член di удовлетворяет условию 0 < di < 9 и

dk * 10k + dk–1 * 10k–1 + ... d0 = 3^200
-------------------------------------------------------------------------------
ENGLISH
Output the sequence dk, dk–1, ..., d0 decimal digits of the number 3200, i.e.
an integer sequence in which each member of di satisfies the condition 0 < di < 9 and

dk * 10k + dk–1 * 10k–1 + ... d0 = 3^200
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <iostream>
#include <math.h>
using namespace std;
int main () {    
    const int max = 200000;
	int num = 3;
 	int pownum = 200;
 	while(true){ 		
		int *Array = new int [max]{0};
		Array[0]=num;
	 	for (int k = 1; k < pownum; k++){
			for(int i = 0; i<max; i++){
				Array[i]*=num;
			}
				
			for (int i = 0; i<max; i++ ){
				Array[i+1]+=Array[i]/10;
				Array[i]=Array[i]%10;
			}      		
		} 
      		
		int i = max-1;
		while(Array[i] == 0){
			i--;
		}
      		
		for (; i!=-1; i--){
			cout << Array[i] << endl;
		}
		delete[] Array;			
	}
 	return 0;	
}
