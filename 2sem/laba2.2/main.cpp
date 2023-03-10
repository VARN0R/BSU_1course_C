/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполните задание, используя динамическое распределение памяти для двумерного массива. 
Описать двумерный массив как одномерный массив с вычислением сдвига элементов по линейной формуле.

Составьте функцию, позволяющую возвести вещественную матрицу произвольного размера в степень n, 
где n - натуральное заданное число.

В папке <laba2.2.v2> эта задача решается по другому способу.
-------------------------------------------------------------------------------
ENGLISH
Perform the task using dynamic memory allocation for a two-dimensional array. 
Describe a two-dimensional array as a one-dimensional array with element shifts calculated using a linear formula. 

Construct a function that allows you to raise a real matrix of arbitrary size to the power of n, 
where n is a natural given number.

In the <laba2.2.v2> folder, this problem is in a different way.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
Compile better in OnlineGDB(https://www.onlinegdb.com)
*/
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
        cout << "For exponentation matrix must be square!";
        return 1;
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