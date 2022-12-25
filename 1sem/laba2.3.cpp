/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Сверхпростым называется число, если оно простое, и число, полученное из исходного числа при записи цифр исходного числа в обратном порядке («перевертыш»),
тоже будет простым. Найти все четырехзначные сверхпростые числа.
-------------------------------------------------------------------------------
ENGLISH
A super-simple number is called if it is simple, and the number obtained from the original number when writing the digits of the original number in reverse order ("shifter")
will also be simple. Find all four-digit super-simple numbers.
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

int main() {
    
    int n = 0;
	int m = 0;

	for (int num = 1000; num <= 9999; num++) {

		bool is_prime = true;
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				is_prime = false;
				break;
			}
		}

		if (!is_prime) {
			continue;
		}


		int num_rev = 0;
		for (int i = 0; i < 4; i++) {
			num_rev += (num / (int)pow(10,3-i) % 10) * pow(10, i);
		}

		is_prime = true;
		for (int i = 2; i < num_rev; i++) {
			if (num_rev % i == 0) {
				is_prime = false;
				break;
			}
		}

		if (!is_prime) {
			continue;
		}

		cout << num << "<--->" << num_rev << endl;
		
	}

    cout << "\n";
	return 0;
}