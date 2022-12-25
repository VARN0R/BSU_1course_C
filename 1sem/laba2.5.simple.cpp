/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Вводится последовательность из n вещественных чисел. 
Определить количество элементов в наиболее длинной подпоследовательности подряд идущих чисел, представляющих собой степени тройки.
-------------------------------------------------------------------------------
ENGLISH
A sequence of n real numbers is introduced. 
Determine the number of elements in the longest subsequence of consecutive numbers representing powers of three.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
//Ââîäèòñÿ ïîñëåäîâàòåëüíîñòü èç n âåùåñòâåííûõ ÷èñåë.Îïðåäåëèòü êîëè÷åñòâî ýëåìåíòîâ â íàèáîëåå äëèííîé ïîäïîñëåäîâàòåëüíîñòè ïîäðÿä èäóùèõ ÷èñåë, ïðåäñòàâëÿþùèõ ñîáîé ñòåïåíè òðîéêè.
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int i = 0, maxlong = 0;
    int pow3long = 0;
    int n = 0;

    int k = 0;
    for (int i = 0; i < 10; i++)

    {
        cin >> n;
        while (!(n % 3)) {
            n /= 3;
        }
        if (n == 1)
            pow3long++;
        else
            pow3long = 0;
        if (pow3long > maxlong)
            maxlong = pow3long;

    }

    cout << endl;
    cout << endl;

    cout << maxlong;
    return 0;
}