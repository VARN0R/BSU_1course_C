/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Дано натуральное  n.  Верно ли, что это число содержит более k одинаковых цифр? 
-------------------------------------------------------------------------------
ENGLISH
Given a natural n. Is it true that this number contains more than k identical digits?
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <iostream> 
#include <algorithm>
using namespace std;

// Äàíî íàòóðàëüíîå  n.  Âåðíî ëè, ÷òî ýòî ÷èñëî ñîäåðæèò áîëåå k îäèíàêîâûõ öèôð? 

int main() {
	setlocale(0, "");
    int n;
	int k;
	
	cout << "Ââåäèòå ÷èñëî n: ";
	cin >> n;

	cout << "Ââåäèòå ÷èñëî k: ";
	cin >> k;


	while (n > 0) {
		int digit = n % 10;

		cout << endl << digit << ":";


		int count = 0;

		int n2 = n / 10;
		while (n2 > 0) {
			int digit2 = n2 % 10;
			cout << digit2 << "   ";

			if (digit2 == digit) {
				count++;
			}

			n2 = n2 / 10;
		}

		if (count > k) {
			cout << "bigger";
			return 0;
		}
		
		n = n / 10;
	}

	cout << "less";
	return 0;
}