/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Дан массив целых чисел, содержащий n элементов. Для тестирования преду-
смотреть возможность задавать элементы массива различным образом: при
описании с инициализацией, присвоением значений (в том числе случайных), или
вводом необходимых значений. Выбор способа инициализации массива сделать че-
рез меню с использованием перечисления (enum).

Найти в целочисленном массиве за один просмотр 5 наибольших элементов.
-------------------------------------------------------------------------------
ENGLISH
An array of integers containing n elements is given. For testing, I will come
to see the ability to set array elements in various ways: when
describing with initialization, assigning values (including random ones), or
entering the necessary values. The choice of the array initialization method should be made
via the menu using enum.

Find the 5 largest elements in an integer array in one view.
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
int n;
int k;
char str;
enum choice {
	RAND = 'r',
	MANUAL = 'm'
};
int main () {
	
	cout << "Select the number of elements of the array in which we will search for the largest elements:" << endl;
	cin >> n;
	int *Array=new int [n];	
	cout << "Select the number of elements of the array in which the largest elements will be stored:" << endl;
	cin >> k;
	int *Maximum=new int [k]{};
	cout << "Сhoose the way to set the first array (press r/m)" << endl;
	cin >> str;
	switch (str) { 
		case choice::MANUAL:
			for (int i = 0; i < n; i++) {
				cin >> Array[i];
			}
			break;
		case choice::RAND:{
		srand(time(0));
			for (int k = 0; k < n; k++){
				Array[k]=rand()%30;
				cout << Array[k] << " ";
			}		
		}
	}
		
	for (int i = 0; i < n; i++){
	
		if (Array[i]>Maximum[0]) {
				Maximum[4]=Maximum[3];
				Maximum[3]=Maximum[2];
				Maximum[2]=Maximum[1];
				Maximum[1]=Maximum[0];
				Maximum[0]=Array[i];
				}
				
		else if (Array[i]>Maximum[1]) {
				Maximum[4]=Maximum[3];
				Maximum[3]=Maximum[2];
				Maximum[2]=Maximum[1];
				Maximum[1]=Array[i];
				}
		
		else if (Array[i]>Maximum[2]) {
				Maximum[4]=Maximum[3];
				Maximum[3]=Maximum[2];
				Maximum[2]=Array[i];
				}
				
		else if (Array[i]>Maximum[3]) {
				Maximum[4]=Maximum[3];
				Maximum[3]=Array[i];
				}
		
		else if (Array[i]>Maximum[4]) {
				Maximum[4]=Array[i];
				}
	}
	cout << "The biggest elements:" << endl;
	for (int i = 0; i < 5; i++){
		cout << Maximum[i] << endl;
	}	
	return 0;	
}