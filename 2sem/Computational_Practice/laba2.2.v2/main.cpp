/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполните задание, используя динамическое распределение памяти для двумерного массива. 
Описать двумерный массив как указатель на массив указателей.

Составьте функцию, позволяющую возвести вещественную матрицу произвольного размера в степень n, 
где n - натуральное заданное число.

В папке <laba2.2> эта задача решается по другому способу.
 -------------------------------------------------------------------------------
ENGLISH
Perform the task using dynamic memory allocation for a two-dimensional array. 
Describe a two-dimensional array as a pointer to an array of pointers.

Construct a function that allows you to raise a real matrix of arbitrary size to the power of n, 
where n is a natural given number.

In the <laba2.2> folder, this problem is in a different way.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
Compile better in OnlineGDB(https://www.onlinegdb.com)
*/

#include "laba2.2.v2.h"
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
    double* Matrix = new double[rows * columns];
    
    inputMatrix(Matrix, rows, columns);
    Exponentation(Matrix, rows, columns);
    outputMatrix(Matrix, rows, columns);
    
    return 0;
}