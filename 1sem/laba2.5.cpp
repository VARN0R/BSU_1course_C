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
#include <iostream>
#include <cmath>
using namespace std;
int main() {

    int num;

    int sequence_len = 0;
    int sequence_len_max = 0;

    while (cin >> num) {

        //check that number is power of 3
        double k = log(num) / log(3);
        double precision = 2 * k * DBL_EPSILON;
        k = k + precision - int(k);

        if (k <= precision) {
            sequence_len++;
        }
        else {
            if (sequence_len > sequence_len_max) {
                sequence_len_max = sequence_len;
            }
            sequence_len = 0;
        }

        cout << k << endl;
    }

    if (sequence_len > sequence_len_max) {
        sequence_len_max = sequence_len;
    }

    cout << "RESULT = " << sequence_len_max;
    return 0;
}
