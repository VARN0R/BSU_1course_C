/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполните задание, используя динамическое распределение памяти для двумерного массива. 
Описать двумерный массив как указатель на массив указателей.

Составьте функцию, позволяющую возвести вещественную матрицу произвольного размера в степень n, 
где n - натуральное заданное число.

В папке <laba2.2> эта задача решается по другому способу.

P.S. Данная вариант программы требует доработок, так как некорректно возводит матрицу в степень. 
В папке <laba2.2> программа работает корректно.  
 -------------------------------------------------------------------------------
ENGLISH
Perform the task using dynamic memory allocation for a two-dimensional array. 
Describe a two-dimensional array as a pointer to an array of pointers.

Construct a function that allows you to raise a real matrix of arbitrary size to the power of n, 
where n is a natural given number.

In the <laba2.2> folder, this problem is in a different way.

P.S. This version of the program requires modification, because it does not correctly exponentiate the matrix. 
In the <laba2.2> folder the program works correctly.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
Compile better in OnlineGDB(https://www.onlinegdb.com)
*/
#include <iostream>
using namespace std;
#include "laba2.2.v2.h"
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
    double* Matrix = new double[rows * columns];
    
    inputMatrix(Matrix, rows, columns);
    Exponentation(Matrix, rows, columns);
    outputMatrix(Matrix, rows, columns);
    
    return 0;
}