/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Выполнить задание, используя C-строки для представления данных.

Написать функцию замены подстроки S1 (задаваемую позицией первого сим-
вола и количеством символов) на подстроку S2 в строке S.

Используя эту функцию, выполнить сжатие заданной строки, т. е. заменить вся-
кую серию подряд идущих символов на (k)s, где s – повторяемый символ, a k – ко-
личество его повторений.                                             
-------------------------------------------------------------------------------
ENGLISH
Perform a task using C-strings to represent data.

Write a function to replace substring S1 (set by the position of the first
symbol and the number of characters) with substring S2 in string S.

Using this function, compress a given string, i.e. replace the entire
series of consecutive characters with (k)s, where s is the repeated character, and k is the
number of its repetitions.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <cstring>
#include <iostream>
using namespace std;

int main () {
	
	int const N = 100;
	char st[N]{};
	char st_2[N]{};
		
	cout << "Введите предложение: " << endl;
	cin.getline(st,N);
	
	int len = 1;
	for(unsigned int i=1; i <= strlen(st); i++) {
    	if(st[i] == st[i-1]){
    		len++;
    		continue;
		}
		
		char temp[10]{};
		int temp_last = 0;
		if(len > 1){
		    temp_last = sprintf(temp, "(%d)", len);   
		}
		temp[temp_last] = st[i-1];
		
		strcat(st_2, temp);
		
		len = 1;
	}
	
	std::cout << st_2;	
	return 0;	
}