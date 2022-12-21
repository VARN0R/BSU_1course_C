/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Получить квадратную матрицу B порядка n, каждый элемент bij которой 
равен максимуму из элементов исходной квадратной матрицы А порядка n, 
расположенных в закрашенной области (включая границы), 
определяемой соответствующими индексами i, j по рисунку. Матрицу A сгенерировать случайно.

Корректность работы алгоритма продемонстировать на матрице 6х6.

Быстродействие продемонстрировать на матрице 10000х10000 без вывода 
матрицы на экран (такой большой массив рекомендуется объявить в глобальной об-
ласти видимости).
__________________________________
|  1 |   2 |  ||*3||   *4 |   *5 |
|  6 |   7 |  ||*8||   *9 |  *10 |
||11||||12||||||*13||||*14|||*15||
| 16 |  17 |  ||18||   19 |   20 |
| 21 |  22 |  ||23||   24 |   25 |
-------------------------------------------------------------------------------
ENGLISH
To obtain a square matrix B of order n, each element bij of which
is equal to the maximum of the elements of the original square matrix A of order n
located in the shaded area (including borders)
defined by the corresponding indices i, j in the figure. Matrix A is generated randomly.

The correctness of the algorithm is demonstrated on a 6x6 matrix.

To demonstrate the performance on a 10000x10000 matrix without displaying
the matrix on the screen (it is recommended to declare such a large array in the global
visibility area).
__________________________________
|  1 |   2 |  ||*3||   *4 |   *5 |
|  6 |   7 |  ||*8||   *9 |  *10 |
||11||||12||||||*13||||*14|||*15||
| 16 |  17 |  ||18||   19 |   20 |
| 21 |  22 |  ||23||   24 |   25 |
-------------------------------------------------------------------------------
*/
#include <iomanip>
#include <time.h>
#include <iostream>
using namespace std;
int main () {
	srand(time (0));
	int n{};
	cout << "Введите n" << endl;
	cin >> n;
	
	int** a= new int* [n];
	int** b= new int* [n];
	for (int i = 0; i < n; i++){
		a[i] = new int [n];
		b[i] = new int [n]{0};
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			a[i][j] = rand()%30;
			cout << setw(4) << a[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < n; i++){
		for (int j = n-1; j >= 0; j--){
			int cell_max = a[i][j];
			if(i>0){
				cell_max = max(cell_max, a[i-1][j]);
			}
			if(j<n-1){
				cell_max = max(cell_max, a[i][j+1]);
			}
			b[i][j] = cell_max;
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << b[i][j] << " ";
		}
		 cout << endl;
	}
	return 0;	
}