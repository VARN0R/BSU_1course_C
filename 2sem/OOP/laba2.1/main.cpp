/*
TASK CONDITION
-------------------------------------------------------------------------------
Разработать класс «вектор», моделирующий математическое понятие «одномерный массив» произвольного размера с 
возможностью изменения числа элементов.
Реализовать конструкторы без параметров и с параметрами, деструктор,
учесть «правило пяти» (конструктор копирования, оператор копирования, 
конструктор перемещения, оператор перемещения, деструктор).
Определить методы:
• задания размерности вектора,
• определения количества элементов заданного вектора;
• заполнения элементов вектора случайными числами.
Реализовать:
• перегрузку операторов индексирования [], возвращающие изменяемое 
значение элемента (L-value) и не изменяемое (R-value) с контролем выхода за 
пределы размерности вектора (для получения элемента вектора по заданному
индексу, занесения значения элемента вектора по заданному индексу),
• перегрузку операторов ввода/вывода значений элементов вектора,
Разместить описание класса в заголовочном файле, а определения методов и
главную функцию программы – в отдельных файлах.
Используя объекты описанного класса «Вектор», реализовать алгоритм своего 
варианта задания 2.1 «Учебной вычислительной практики».

ЗАДАНИЕ LABA2.1:
Выполните задание, используя динамическое распределение памяти для одномерного массива.
Имеется последовательность целых положительных чисел, в которой каждое
<= 10^4. Последовательность генерируется случайным образом или вводится с клавиатуры.
Длина последовательности n <= 10^9.
Получить конечный массив в один просмотр элементов (без хранения всей последовательности),
сформированный из чисел, встречающихся в исходной последовательности более
одного раза, в порядке возрастания (без повторений)
 -------------------------------------------------------------------------------
ENGLISH
To develop a "vector" class that models the mathematical concept of a "one-dimensional array" of arbitrary size with
the possibility of changing the number of elements.
Implement constructors without parameters and with parameters, destructor,
take into account the "rule of five" (copy constructor, copy operator,
move constructor, move operator, destructor).
Define methods:
• vector dimension assignments,
• determining the number of elements of a given vector;
• filling vector elements with random numbers.
Implement:
• overloading of indexing operators [] that return mutable 
the value of the element (L-value) and not changeable (R-value) with the control
of going beyond the dimension of the vector (to get the element of the vector at a given
index, entering the value of the element of the vector at a given index),
• overload of input/output operators of vector element values,
Place the class description in the header file, and the method definitions and
the main function of the program in separate files.
Using objects of the described class "Vector", implement the algorithm of its
version of the task 2.1 "Educational computing practice".

TASK LABA2.1:
Perform the task using dynamic memory allocation for a one-dimensional array.
There is a sequence of positive integers in which each
<= 10^4. The sequence is randomly generated or entered from the keyboard.
The length of the sequence n <= 10^9. Get a final array in one viewing of the elements (without storing the whole sequence),
formed from the numbers that occur in the original sequence more than
once, in ascending order (without repetitions);
-------------------------------------------------------------------------------
*/

#include "laba2.1.h"
using namespace std;

int main() {
    Vector<int>nums(10);
    nums.fillrand();

    for (int i = 0; i < nums.getsize(); i++) {
       cout  << nums[i] << " ";
    }
    
    int temp[200000]{};                             
    Vector<int>res;   
    cout << endl;  
    cout << endl;
    
    for (int i = 0; i < nums.getsize(); i++) {
        temp[nums[i]]++;
    }
    
    for (int i = 0; i < 200; i++) {
        if (temp[i] > 1) {
            res.push_back(i);
        }
    }
    
    for (int i = 0; i < res.getsize(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}