/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Задано число n в формате unsigned long. 
Вывести на экран значения 0-го, 1-го  и 15-го битов представления в ЭВМ  этого числа. 
Объяснить результат. Инвертировать биты 1,10. Вывести и  объяснить результат.
-------------------------------------------------------------------------------
ENGLISH
The number n is set in the unsigned long format. 
Display the values of the 0th, 1st and 15th bits of the representation in the computer of this number. 
Explain the result. Invert bits 1.10. Output and explain the result.
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


int main()
{
	setlocale(0, "");
	
	int unsigned long n = 0; 
	int b0 = 0;
	int b1 = 0;
	int b15 = 0;
	int b2 = 0;
	cout << "Ââåäèòå ÷èñëî = ";
	cin >> n;
	b0 = (n >> 0) & 1;
	cout << b0 << " - b0\n";

	b1 = (n >> 1) & 1;
	cout << b1 << " - b1\n";


	b2 = (n >> 2) & 1;
	cout << b2 << " - b2\n";

	b15 = (n >> 15) & 1;
	cout << b15 << " - b15\n";
	
	int perev = n ^ ((1 << 1) | (1 << 15));

	return 0;
}