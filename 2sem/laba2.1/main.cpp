/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполните задание, используя динамическое распределение памяти для одномерного массива. 
Имеется последовательность целых положительных чисел, в которой каждое
<= 10^4. Последовательность генерируется случайным образом или вводится с клавиатуры. 
Длина последовательности n <= 10^9. 
Получить конечный массив в один просмотр элементов (без хранения всей последовательности), 
сформированный из чисел, встречающихся в исходной последовательности более
одного раза, в порядке возрастания (без повторений)
 -------------------------------------------------------------------------------
ENGLISH
Perform the task using dynamic memory allocation for a one-dimensional array. 
There is a sequence of positive integers in which each
<= 10^4. The sequence is randomly generated or entered from the keyboard. 
The length of the sequence n <= 10^9. Get a final array in one viewing of the elements (without storing the whole sequence), 
formed from the numbers that occur in the original sequence more than
once, in ascending order (without repetitions);
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
Compile better in OnlineGDB(https://www.onlinegdb.com)
*/
#define N 10000000
#include <iostream>
using namespace std;
#include "laba2.1.h"

int main(){
    element *arr = new element[N];
    int len = read_rand_array(arr);
    print_array(arr, len);
    delete[] arr;
    return 0;
}