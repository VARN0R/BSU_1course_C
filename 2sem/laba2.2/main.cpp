#include <iostream>
using namespace std;
#include "laba2.2.h"

int main(){
    int rows;
    cout << "Enter size rows: ";
    cin >> rows;
    int columns;
    cout << "Enter size columns: ";
    cin >> columns;
    if (rows != columns){
        cout << "For exponentation matrix must be square!"
        return;
    }
    double **Matrix = new double* [rows]{};
    for (int i = 0; i < rows; i++){
        Matrix[i] = new double [columns];
    }
    
    inputMatrix(Matrix, rows, columns);
    Exponentation(Matrix, rows, columns);
    outputMatrix(Matrix, rows, columns);
    return 0;
}