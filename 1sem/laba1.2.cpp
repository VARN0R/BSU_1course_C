/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
рисунок в мануале
-------------------------------------------------------------------------------
ENGLISH
drawing in the manual
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

using namespace std;

int main()
{
	using namespace std;

	double x, y;
    cout << "Coordinates x,y:\n";
	cin >> x >> y;

	bool x_right = x >= 0;
	bool below_line = (y <= x && y >= 0) || (x <= y && y < 0);
	bool higner_paraboly = y > (pow(x - 2, 2) - 3);
	
	if (x_right && below_line && higner_paraboly)
		cout << "True" << endl;
	else
		cout << "False" << endl;


	return 0;
}


