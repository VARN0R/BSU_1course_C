//coming soon 3 files



#include <iostream>
#include <cstring>
using namespace std;


template<typename T>
void inputArray(T*array, int n){
     for (int i = 0; i < n; i++){
        cin >> array[i];
    }
}


//void inputArray(char*array, int n){
//     cin.getline(array, n);
//}



void OutputArray(int*array, int n){
     for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}

void OutputArray(double*array, int n){
     for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}

void OutputArray(float*array, int n){
     for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}

void OutputArray(char*array, int n){
     for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}

//перегрузка для с строк
template<typename T>
bool comp(T left, T right){
	return left <= right;
}

bool comp(char* left, char* right){
	return strcmp(left,right) <= 0;
}


template<typename T>
void mergeSort(T *array, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    T *temp = new T [right - left + 1];

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (comp(array[i], array[j])) {//применение функции сompare
            temp[k] = array[i];
            i++;
        } else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (int p = 0; p < k; p++) {
        array[left + p] = temp[p];
    }
    delete[]temp;
}

int main() {
	cout << "Max element: ";
	int N;	
	cin >> N;
	char* Array = new char [N]{};//char *Array = new char [N]; 
	inputArray(Array, N);	
	mergeSort(Array, 0, N-1);
	OutputArray(Array, N);
	delete [] Array;
	return 0;	
}

