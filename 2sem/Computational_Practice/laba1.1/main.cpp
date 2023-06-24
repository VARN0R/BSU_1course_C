/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполнить задание, оформив его через функции (ввода, вывода, заполнение). 
Передачу массива в функции организовать через указатели.
Получить квадратную матрицу порядка n, элементами которой являются заданные числа а1, …, an, 
расположенные в ней по спирали (см. схему на рисунке).
Перебор строк/столбцов матрицы осуществить с использованием указателей.
_______________________________
|  13 |  12 |  11 |  10 |  9  |
|  14 |  23 |  22 |  21 |  8  |
|  15 |  24 |  25 |  20 |  7  |
|  16 |  17 |  18 |  19 |  6  |
|  1  |  2  |  3  |  4  |  5  |
-------------------------------------------------------------------------------
ENGLISH
Complete the task by completing it through the functions (input, output, filling). 
To organize the transfer of an array to a function through pointers.
Get a square matrix of order n, the elements of which are the given numbers a1, ..., an, 
arranged in a spiral in it (see the diagram in the figure).
Iterate through the rows / columns of the matrix using pointers.
_______________________________
|  13 |  12 |  11 |  10 |  9  |
|  14 |  23 |  22 |  21 |  8  |
|  15 |  24 |  25 |  20 |  7  |
|  16 |  17 |  18 |  19 |  6  |
|  1  |  2  |  3  |  4  |  5  |
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/

#include "laba1.1.h"
using namespace std;

int main() {
	int size_matrix{};
	cout << "Enter size matrix: " << endl;
	cin >> size_matrix;
	int** a = new int* [size_matrix] {0};
	for (int i = 0; i < size_matrix; i++){
		a[i] = new int[size_matrix] {0};
	}
	
	input(a, size_matrix);
	output(a, size_matrix);
	
	delete[]a;
	return 0;
}