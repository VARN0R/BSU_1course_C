/*
TASK CONDITION
-------------------------------------------------------------------------------
Вычислить следующие интегралы заданным методом (метод средних
прямоугольников), воспользо-
вавшись критерием двойного пересчета, с точностью eps = 10–6 .
Значения параметра s: si принадлежит [s1; s2], si = s1 + i(delta)s, i = 0, 1, … .
Значения параметра t: ti принадлежит [t1; t2], ti = t1 + i(delta)t, i = 0, 1, … .
Вычисление значения функции в точке оформить в виде функции, вычисление
интеграла – в виде функции с параметром функционального типа для задания
функции. Процедуры оформить в виде отдельного файла.
Результаты представить в виде таблицы (s, t – соответствующие значения
параметров, Int – вычисленное значение интеграла, k_iter – количество пересчетов
значений интеграла для получения заданной точности):
-------------------------------------------------------------------------------
ENGLISH
Calculate the following integrals by a given method (the middle
rectangle method),
using the double recalculation criterion, with an accuracy of eps = 10-6.
Parameter values s: si belongs to [s1; s2], si = s1 + i(delta)s, i = 0, 1, ... .
Parameter values t: ti belongs to [t1; t2], ti = t1 + i(delta)t, i = 0, 1, ... .
The calculation of the value of a function at a point should be made in the form of a function, the calculation
of the integral – in the form of a function with a functional type parameter for the task
functions. The procedures should be issued as a separate file.
The results are presented in the form of a table (s, t are the corresponding
parameter values, Int is the calculated value of the integral, k_iter is the number of recalculations
of the integral values to obtain the specified accuracy):
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
Compile better in OnlineGDB(https://www.onlinegdb.com)
*/

#include "laba1.5.h"
int main(){
    ResultIntegral();
    return 0;
}