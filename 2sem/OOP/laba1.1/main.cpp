/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполнить задания для текстового файла. Задания выполнить через функции. 
Размер файлов <= 64GiB.
Компоненты файла f – целые числа, причем положительных чисел столько же,
сколько отрицательных. Получить файл g из чисел исходного файла, в котором 
записаны 2 положительных числа, затем 2 отрицательных и т. д.
 -------------------------------------------------------------------------------
ENGLISH
Perform tasks for a text file. Tasks are performed via functions. 
File size <= 64 Gb.
The components of the file f are integers, and there are as many positive numbers
as there are negative ones. Get the g file from the numbers of the source file, in which
2 positive numbers are written, then 2 negative numbers, etc.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
Compile better in OnlineGDB(https://www.onlinegdb.com)
*/

#include <iostream>
#include <fstream>

using namespace std;

void InputData(int &amount) {
    ofstream fout("source.txt");
    cout << "Amount of numbers: ";
    cin >> amount;
    int temp{};
    for (int i = 0; i < amount; i++) {
        cin >> temp;
        fout << temp << " ";
    }
}

void Processing(int &amount) {
    ifstream fin("source.txt");
    ofstream foutPositive("positive.txt");
    ofstream foutNegative("negative.txt");
    
    int temp{};
    while (fin >> temp) {
        if (temp > 0) {
            cout << temp << endl;
            foutPositive << temp << " ";
        }
        else {
            cout << temp << endl;
            foutNegative << temp << " ";
        }
    }
    fin.close();
    foutPositive.close();
    foutNegative.close();

    ifstream finPositive("positive.txt");
    ifstream finNegative("negative.txt");
    ofstream foutFinal("final.txt");
    
    //cout << amount << endl;
    while (amount>0) {
        if (finPositive >> temp) {
            foutFinal << temp << " ";
            amount--;
        }
        if (finPositive >> temp) {
            foutFinal << temp << " ";
            amount--;
        }

        if (finNegative >> temp) {
            foutFinal << temp << " ";
            amount--;
        }

        if (finNegative >> temp) {
            foutFinal << temp << " ";
            amount--;
        }
    }

    finPositive.close();
    finNegative.close();
    foutFinal.close();

}

int main() {
    int amount{};
    InputData(amount);
    Processing(amount);
    return 0;
}
