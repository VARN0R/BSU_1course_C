/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Верно ли, что первые n цифр дробной части заданного положительного вещественного числа одинаковы? 
-------------------------------------------------------------------------------
ENGLISH
Is it true that the first n digits of the fractional part of a given positive real number are the same?
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
//äðîáíîé ÷àñòè çàäàííîãî ïîëîæèòåëüíîãî âåùåñòâåííîãî ÷èñëà,
//öèôð 9
//Âåðíî ëè, ÷òî ïåðâûå n öèôð äðîáíîé ÷àñòè çàäàííîãî ïîëîæèòåëüíîãî âåùåñòâåííîãî ÷èñëà îäèíàêîâû ?
// áàã íà k=7


int main() {
	setlocale(0, "");
	
	double inputNumber{};
	cout << "ââåäèòå ÷èñëî: ";
	cin >> inputNumber;

	int n;
	cout << "ââåäèòå n: ";
	cin >> n;
	
	inputNumber *= 10;
	int digit = (int)inputNumber % 10;

	bool is_ok = true;
	for (int i = 0; i < n-1; i++) {
		inputNumber = inputNumber - (int)inputNumber;
		inputNumber *= 10;

		int digit2 = (int)inputNumber % 10;
		if (digit != digit2) {
			is_ok = false;
			break;
		}
	}
	
	if (is_ok)
		cout << "âñå ïåðâûå öèôðû äðîáíîé ÷àñòè äî " << n << " âêëþ÷èòåëüíî îäèíàêîâûå" << endl;
	else
		cout << "íå âñå ïåðâûå öèôðû äðîáíîé ÷àñòè îäèíàêîâûå" << endl;
	
	return 0;
}
















