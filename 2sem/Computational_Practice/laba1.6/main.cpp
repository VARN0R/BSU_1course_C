/*
TASK CONDITION
-------------------------------------------------------------------------------
Дан массив чисел произвольной длины. Отсортировать массив, используя сортировку слияниями.
Создать шаблоны и перегрузки функций для сортировки, вывода результатов, заполнения массивов.
Выполнить сортировки массивов для данных разных типов: целых, вещественных, символьных, С- строк, 
используя написанные функции.
-------------------------------------------------------------------------------
ENGLISH
An array of numbers of arbitrary length is given. Sort the array using merge sorting.
Create templates and function overloads for sorting, output results, and filling arrays.
Perform array sorting for data of different types: integer, real, character, C-strings, 
using written functions.
-------------------------------------------------------------------------------
*/
#include "laba1.6.h"
using namespace std;
int main() {
	cout << "Max element: ";
	int N;	
	cin >> N;
	int* Array = new int [N];//char *Array = new char [N]; 

	inputArray(Array, N);
	mergeSort(Array, 0, N-1);
	OutputArray(Array, N);
	delete [] Array;
	return 0;	
}



