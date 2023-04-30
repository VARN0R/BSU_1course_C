/*
TASK CONDITION
-------------------------------------------------------------------------------
Составьте функцию, позволяющую возвести вещественную матрицу произвольного размера в степень n, 
где n - натуральное заданное число.
-------------------------------------------------------------------------------
ENGLISH
Construct a function that allows you to raise a real matrix of arbitrary size to the power of n, 
where n is a natural given number.
-------------------------------------------------------------------------------
*/

#include "header.h"
using namespace std;
int main(){
    int rows;
    cout << "Enter size rows: ";
    cin >> rows;
    int columns;
    cout << "Enter size columns: ";
    cin >> columns;
    if (rows != columns){
        cout << "For exponentation matrix must be square!";
        return 1;
    }
    vector<vector<double>>Matrix(rows, vector<double>(columns));
    
    inputMatrix(Matrix, rows, columns);
    Exponentation(Matrix, rows, columns);
    outputMatrix(Matrix, rows, columns);
    return 0;
}