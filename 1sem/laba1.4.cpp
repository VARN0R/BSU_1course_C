/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Поле  шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит 8: 
первое – номер вертикали, второе – номер горизонтали. 
Заданы натуральные числа k, l, m, n. 

Определить, бьет ли одна фигура другую. 
Если же фигуры не угрожают друг другу, выяснить, возможен ли ход какой-либо фигуры, после которого одна из фигур бьет другую.
На поле (k, l) стоит слон, на поле (m, n) – конь. 

-------------------------------------------------------------------------------
ENGLISH
The field of the chessboard is determined by a pair of natural numbers, each of which does not exceed 8:
the first is the vertical number, the second is the horizontal number. 
The natural numbers k, l, m, n are given. 

Determine whether one piece beats another. 
If the pieces do not threaten each other, find out if a move of any piece is possible, after which one of the pieces beats the other.
There is a bishop on the field (k, l), and a knight on the field (m, n).
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include <iostream>
#include <bitset>
using namespace std;

//шахматы
int main() {

	setlocale(0, "");

	int slon_X, slon_Y, kon_X, kon_Y;

	cout << "координаты слона\n";
	cin >> slon_X >> slon_Y;
	cout << "координаты коня\n";
	cin >> kon_X >> kon_Y;

	if (slon_X > 8 || slon_Y > 8 || kon_X > 8 || kon_Y > 8 || slon_X < 1 || slon_Y < 1 || kon_X < 1 || kon_Y < 1) {
		cout << "вы вышли за рамки всего возможного, вы почти управляете миром" << endl;
		return 0;
	}

	if (slon_X == kon_X && slon_Y == kon_Y) {
		cout << "не может быть" << endl;
		return 0;
	}
	
	if (abs(slon_X - kon_X) == abs(slon_Y - kon_Y)) {		
		cout << "слон бьет коня" << endl;
		return 0;
	}

	if (abs(slon_X - kon_X) - abs(slon_Y - kon_Y) == 1) {
		cout << "конь бьёт слона" << endl;
		return 0;

	}

	cout << "Фигуры не бьют друг друга" << endl;
	return 0;
}






	
	








