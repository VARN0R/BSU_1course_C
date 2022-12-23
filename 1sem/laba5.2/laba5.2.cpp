/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Дан массив чисел произвольной длины. Отсортировать массив сортировкой выбором и вставками;

P.S. Для тестирования программы заполнять массив значениями тремя спосо-
бами: по возрастанию, по убыванию, случайным образом.
Каждый метод сортировки, каждый способ заполнения массивов оформить
отдельными функциями. Функции оформить в виде отдельного файла.
Для каждого метода сортировки определить число сравнений и перемеще-
ний (перестановок с одного места на другое) элементов в процессе выполнения
программы.
Сравнить экспериментальные результаты с известными теоретиче-
скими оценками этих показателей для заданных методов сортировки.
Обеспечить перегрузку и шаблоны необходимых функций для выполнения за-
дания с типами элементов массивов char, int, float, double.
-------------------------------------------------------------------------------
ENGLISH
An array of numbers of arbitrary length is given. Sort the array by sorting selecting and inserting;

P.S. To test the program, fill the array with values in three ways: ascending, descending, randomly.
Each sorting method, each method of filling arrays should be decorated
with separate functions. The functions should be arranged as a separate file.
For each sorting method, determine the number of comparisons and displacements
(permutations from one place to another) of elements during the execution
of the program.
Compare experimental results with known theoretical-
estimates of these indicators for the specified sorting methods.
Provide overloading and templates of the necessary functions to perform
tasks with the types of array elements char, int, float, double.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#define OUT   //обозначение изменений внутри функции

#include <iostream>
#include "func_for_laba5.2.h"
using namespace std;

template <typename T>
int main_template(){

	char valuable;
	int const N = 10;

	T *Array = new T [N];
	T *a = new T [N];

	cout << " Enter n/m " << endl;
	cin >> valuable;
	switch (CHOICE(valuable)) {
		case CHOICE::MANUAL: {
		manualArray(Array, a, N);
		break;
		}
		case CHOICE::RAND: {
		randArray(Array, a, N);
		break;
		}
	}
	
	
	int number_of_comparisons = 0;//число сравнений
	int number_of_permutations = 0; // число перестановок
	choiceSort(Array, N, OUT number_of_permutations, OUT number_of_comparisons);
	cout << "-------" << endl;
	cout << "sorting by choice" << endl;
	cout << "number of comparisons: " << number_of_comparisons << endl;
	cout << "number of permutations: " << number_of_permutations << endl;
	for (int i = 0; i < N; i++){
		cout << "[" << i << "]= " << Array[i] << endl;
	}
	
	number_of_comparisons = 0;
	number_of_permutations = 0;
	choicePaste(a,N, OUT number_of_permutations, OUT number_of_comparisons);
	cout << "-------" << endl;
	cout << "sorting by insertion" << endl;
	cout << "number of comparisons: " << number_of_comparisons << endl;
	cout << "number of permutations: " << number_of_permutations << endl;

	for (int i = 0; i < N; i++){ 
		cout << "[" << i << "]= " << Array[i] <<  endl;
	
	}
	return 0;
}

int main () {
	char valuable_array;
	cout << "Enter i/d/f" << endl;
	cin >> valuable_array;

	switch (CHOICEARRAY(valuable_array)) {
		case CHOICEARRAY::FLOAT: {
			return main_template<float>();
		}
		case CHOICEARRAY::DOUBLE: {
			return main_template<double>();
		}
		case CHOICEARRAY::INT: {
			return main_template<int>();
		}
		default:
			return 1;
	}
	
	return 0;	
}