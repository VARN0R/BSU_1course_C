/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Дано действительное число х (0 < x <= 1). Вычислить заданную сумму с точно-
стью e = 10^(–6) и указать количество слагаемых. Считать, что требуемая точ-
ность достигнута, если очередное слагаемое по абсолютному значению меньше e.

Примечание. В программе не использовать математические функции из библио-
теки math.h.
                                            
Cамое выражение: сумма от k=1 до бесконечности дроби ((-1)^k * x^(k+2))/((k+2)!*(k+1))                                                
-------------------------------------------------------------------------------
ENGLISH
Given a real number x (0 < x <= 1). Calculate the given sum with the precision
e = 10^(-6) and specify the number of terms. Assume that
the required accuracy is achieved if the next term is less than e in absolute value.

Note. The program does not use mathematical functions from bibliotags math.h.
 
                                            
The expression itself is: the sum from k=1 to infinity of a fraction ((-1)^k * x^(k+2))/((k+2)!*(k+1)) 
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

double my_pow(double x, int y) {
	double result = 1;
	for (int i = 0; i < y; i++) {
		result *= x;
	}
	return result;
}

double my_abs(double x) {
	return (x < 0) ? -x : x;
}

double calc(double x, int& k, double eps = 1e-6){

	double sum = 0;

	double a = 1;
	double b = x;
	double c = 1;
	double d = 0;
	double element = 0;

	do {
		k++;
		
		a *= -1;
		b = my_pow(x, (k + 2));
		c *= (k + 2);
		d = k + 1;

		element = a * b / c / d;

		sum += element;


	} while (my_abs(element) >= eps);

	sum -= element;
    return sum;
}


int main() {
	int k = 0;
	const double eps = 1e-6;
	double x;
	cout << "x =  ";
	cin >> x;
	double sum = calc(x, k, eps);
	cout << "sum = " << sum << endl;
	cout << "amount of elements = " << k << endl;
	return 0;
}