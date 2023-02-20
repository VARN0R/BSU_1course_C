/*
TASK CONDITION
-------------------------------------------------------------------------------
Вычислить корень уравнения f ( x) = 0  на отрезке [a; b] с точностью eps = 10^(–6),
используя  метод касательных для заданных функций. Вычисление корня уравнения оформить 
в виде функции с функциональным параметром, параметры a, b, eps, s – в виде аргументов по умолчанию.
Результат представить в виде таблицы (s – значение параметра, х – вычисленный корень уравнения, 
f(x) – значение функции в найденной точке х, 
n_iter – количество итераций цикла для получения корня с заданной точностью):
-------------------------------------------------------------------------------
ENGLISH
Calculate the root of the equation f (x) = 0 on the segment [a; b] with an accuracy of eps = 10^(-6)
using the tangent method for the given functions. The calculation of the root
of the equation should be made in the form of a function with a functional parameter, parameters a, b,
eps, s - in the form of default arguments.
The result is presented in the form of a table (s is the value of the parameter, x is the calculated root 
of the equation, f(x) is the value of the function at the found point x, 
n_iter is the number of iterations of the cycle to obtain the root with a given accuracy):
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
Compile better in OnlineGDB(https://www.onlinegdb.com)
*/
#include <iostream>
#include "laba1.4.h"
using namespace std;
int main(){
    cout << "First method:" << endl;
    TangentMethod1();
    cout << "Second method:" << endl;
    TangentMethod2();
    return 0;   
}