
/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Даны вещественные x1, x2, x3, x4 . Поменять значения переменных так, чтобы  x1 <  x2  >  x3  >  x4 .
-------------------------------------------------------------------------------
ENGLISH
The real x1, x2, x3, x4 are given. Change the values of variables so that x1 < x2 > x3 > x4 .
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
	// x1<x2>x3>x4
	double x1, x2, x3, x4;
	cout << "x1, x2, x3, x4:";
	cin >> x1 >> x2 >> x3 >> x4;
	if (x1 > x2) swap(x1, x2);
	if (x2 < x3) swap(x2, x3);
	if (x3 < x4) swap(x3, x4);

	cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
    
    return 0;
}