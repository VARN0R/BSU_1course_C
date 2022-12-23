/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Один из вариантов определения сверхпростых чисел гласит:
сверхпростым называется число, если оно простое, и число, полученное из исход-
ного числа при записи цифр исходного числа в обратном порядке («перевертыш»),
тоже будет простым. Написать программу, которая выводит все сверхпростые
числа в диапазоне от k до g, используя алгоритм "решето Эратосфена"                          
-------------------------------------------------------------------------------
ENGLISH
One of the variants of the definition of super-simple numbers says:
a super-simple number is called if it is simple, and the number obtained from the
original number when writing the digits of the original number in reverse order ("shifter")
will also be simple. Write a program that outputs all super
-simple numbers in the range from k to g using the "sieve of Eratosthenes" algorithm
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <math.h>
#include <iostream>           
#include<algorithm>
using namespace std;

int main()
{
	int k;
	int g;
	
	cout << "Enter k (first constraint): " << endl;
	cin >> k;	
	cout << "Enter g (second constraint): " << endl;
	cin >> g;
	
	const int N = g*10;
	
	bool* a = new bool[N]{0};
	for (int i = 2; i < N; i++)
		a[i] = true;

	unsigned int n = sqrt(double(N));
	for (unsigned int i = 2; i <= n; i++)
		if (a[i]) 
			for (int j = i *2; j < N; j += i)
				a[j] = false;
	
	for ( int i = k; i < g; i++){
		if (!a[i]) 
			continue;
		
		int m = 0;
		int clone_i = i;
		while(clone_i){
    		m = (m*10+(clone_i%10));
    		clone_i /= 10;
		}
		
		if(a[m])
  			cout << i << "<--->" << m << " ";	
	}
	return 0;
}


