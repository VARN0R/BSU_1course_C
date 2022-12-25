/*
TASK CONDITION
-------------------------------------------------------------------------------
Даны x1, x2, …x4, y1, y2, … y4 – вещественные числа. 
Точки с координатами (x1, y1), (x2, y2) рассматриваются как две противоположные вершины первого прямоугольника, 
стороны которого параллельны осям координат. 
Точки с координатами (x3, y3), (x4 y4) – рассматриваются как две противоположные вершины второго прямоугольника, 
стороны которого параллельны осям координат. Выяснить,  верно ли, что первый прямоугольник целиком содержится во втором. 
-------------------------------------------------------------------------------
ENGLISH
Given x1, x2, ...x4, y1, y2, ... y4 are real numbers. 
Points with coordinates (x1, y1), (x2, y2) are considered as two opposite vertices of the first rectangle whose
sides are parallel to the coordinate axes. 
Points with coordinates (x3, y3), (x4 y4) are considered as two opposite vertices of the second rectangle,
whose sides are parallel to the coordinate axes. Find out if it is true that the first rectangle is entirely contained in the second.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
﻿#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");

	float x1, x2, x3, x4, y1, y2, y3, y4 = 0;
	cout << "Введите данные ";

	cout << "x1= "; cin >> x1;
	cout << "x2= "; cin >> x2;
	cout << "x3= "; cin >> x3;
	cout << "x4= "; cin >> x4;
	cout << "y1= "; cin >> y1;
	cout << "y2= "; cin >> y2;
	cout << "y3= "; cin >> y3;
	cout << "y4= "; cin >> y4;

	if (x3 > x4) {
		float t = x3;
		x3 = x4;
		x4 = t;
    }

	if (y3 > y4) {
		float t = y3;
		y3 = y4;
		y4 = t;
	}

	bool x1_inside = x3 < x1&& x1 < x4;
	bool x2_inside = x3 < x2&& x2 < x4;
	bool y1_inside = y3 < y1&& y1 < y4;
	bool y2_inside = y3 < y2&& y2 < y4;

	cout << "Прямоугольник 1 в прямоугольнике 2: " << ((x1_inside && x2_inside && y1_inside && y2_inside) ? "ДА" : "НЕТ") << endl;
    return 0;
}