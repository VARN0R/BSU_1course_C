/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполнить задания, используя двусвязные динамические структуры данных в
виде связных компонент. Оценить асимптотическую сложность алгоритма.  
Даны натуральное число n, действительные числа a1, a2, ... a2n. Получить (an - an+1) * (an-1 - an+2) * 
*(an-2 - an+3) *  ... * (a1 - a2 n)
 -------------------------------------------------------------------------------
ENGLISH
Perform tasks using two-connected dynamic data structures in
the form of connected components. Evaluate the asymptotic complexity of the algorithm.  
Given a natural number n, the real numbers a1, a2, ... a2n. Get (an - an+1) * (an-1 - an+2) * 
*(an-2 - an+3) *  ... * (a1 - a2 n)
-------------------------------------------------------------------------------
*/
#include "laba2.6.h"
using namespace std;

int main(){
    Tree head;
    int len = head.read_list();
    cout << "Your input:\n";
    head.print_list();
    head.generate(len);
    head.delete_list();
    return 0;
}