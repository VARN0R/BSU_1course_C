/*
TASK CONDITION
-------------------------------------------------------------------------------
Имеется последовательность целых положительных чисел, в которой каждое
<= 10^4. Последовательность генерируется случайным образом или вводится с клавиатуры.
Длина последовательности n <= 10^9.
Получить конечный массив в один просмотр элементов (без хранения всей последовательности),
сформированный из чисел, встречающихся в исходной последовательности более
одного раза, в порядке возрастания (без повторений)
 -------------------------------------------------------------------------------
ENGLISH
There is a sequence of positive integers in which each
<= 10^4. The sequence is randomly generated or entered from the keyboard.
The length of the sequence n <= 10^9. Get a final array in one viewing of the elements (without storing the whole sequence),
formed from the numbers that occur in the original sequence more than
once, in ascending order (without repetitions);
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>nums;
    
    cout << "Enter amount numbers: " << endl;
    int amount = 0;
    cin >> amount;
    int temp;
    cout << "Enter numbers: " << endl;
    for (int i = 0; i < amount; i++) {
       cin >> temp;
       nums.push_back(temp);
    }
    
    int amount_nums[200000]{};                             
    vector<int>res;   
    cout << endl;  
    
    for (int i = 0; i < nums.size(); i++) {
        amount_nums[nums[i]]++;
    }
    
    for (int i = 0; i < 200; i++){
        if (amount_nums[i] > 1) {
            res.push_back(i);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}