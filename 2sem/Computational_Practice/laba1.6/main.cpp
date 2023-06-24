#include "laba1.6.h"
using namespace std;

int main() {
	cout << "Max element: ";
	int N;	
	cin >> N;
	int* Array = new int [N];//char *Array = new char [N]; 
    for (int i = 0; i < N; i++){
        cin >> Array[i];
    }
	mergeSort(Array, 0, N-1);
	OutputArray(Array, N);
	delete [] Array;
	return 0;	
}

