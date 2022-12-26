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
	cout << "введите число: ";
	cin >> inputNumber;

	int n;
	cout << "введите n: ";
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
		cout << "все первые цифры дробной части до " << n << " включительно одинаковые" << endl;
	else
		cout << "не все первые цифры дробной части одинаковые" << endl;
	
	return 0;
}
















