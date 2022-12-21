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
#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;
enum choice {
	RAND = 'r',
	MANUAL = 'm'
};

int main() {
	int n;
	cout << "Select the number of elements of the array in which we will search for the largest elements" << endl;
	cin >> n;
	
	int k;
	cout << "Select the number of elements of the array in which the largest elements will be stored" << endl;
	cin >> k;
	
	int *Array=new int [n]{};
	int *Maximum=new int [k]{};
	for(int i = 0 ;i <k;i++){
		Maximum[i] = INT_MIN;
	}
	
	char str;
	cout << "Сhoose the way to set the first array (press r/m)" << endl;
	cin >> str;
	switch (str) { 
		case choice::MANUAL:
			for (int i = 0; i < n; i++) {
				cout << "A[" << i <<"] =";
				cin >> Array[i];
			}
			break;
		case choice::RAND:{
			srand(time(0));
			const int rand_min = -20;
			const int rand_max = +20;
			for (int k = 0; k < n; k++){
				Array[k]=rand()%(rand_max-rand_min+1)+rand_min;
				cout << setw(4) << Array[k];
			}
			break;
		}
		default:
			return 1;
	}

	bool IsMax = 0;		
	for (int i = 0; i < n; i++){
		IsMax = false;
		for (int g = 0; g<k; g++) {
			if (Array[i]>Maximum[g]) {
				for (int j =k-1; j>g; j--) {
					Maximum[j]=Maximum[j-1];
				}
				Maximum[g]=Array[i];
				IsMax = true;			
			}
			if (IsMax) {
				break;		
			}	
		}
	}
	
	cout << "\nThe biggest elements:" << endl;
	for (int i = 0; i < k && Maximum[i] != INT_MIN; i++){	
		cout << Maximum[i] << endl;
	}
		
	return 0;	
}