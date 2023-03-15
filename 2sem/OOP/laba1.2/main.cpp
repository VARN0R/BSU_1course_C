/*
TASK CONDITION
-------------------------------------------------------------------------------
Решение задачи из laba1.1 только через бинарный файл
 -------------------------------------------------------------------------------
ENGLISH
Solving the problem from laba1.1 only through a binary file
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
    ofstream fout("source.bin", ios_base::binary);
    cout << "Amount of numbers: ";
    cin >> amount;
    int temp{};
    for (int i = 0; i < amount; i++) {
        cin >> temp;
        //reinterpret_cast<char*>(&temp) == (char*)&temp
        // первое используют в С++, второе пришло из С, но также работает в С++
        fout.write(reinterpret_cast<char*>(&temp), sizeof(int));
    }
    fout.close();
}

void Processing(int amount) {
    ifstream fin("source.bin", ios_base::binary);
    ofstream foutPositive("positive.bin", ios_base::binary);
    ofstream foutNegative("negative.bin", ios_base::binary);
    
    int temp{};
    while (fin.read((char*)&temp, sizeof(int))) {
        if (temp > 0) {
            cout << temp << endl;
            foutPositive.write((char*)&temp, sizeof(int));
        }
        else {
            cout << temp << endl;
            foutNegative.write((char*)&temp, sizeof(int));
        }
    }
    fin.close();
    foutPositive.close();
    foutNegative.close();

    ifstream finPositive("positive.bin", ios_base::binary);
    ifstream finNegative("negative.bin", ios_base::binary);
    ofstream foutFinal("final.bin", ios_base::binary);
    
    //cout << amount << endl;
    while (amount>0) {
        if (finPositive.read((char*)&temp, sizeof(int))) {
            foutFinal.write((char*)&temp, sizeof(int));
            amount--;
        }
        if (finPositive.read((char*)&temp, sizeof(int))) {
            foutFinal.write((char*)&temp, sizeof(int));
            amount--;
        }

        if (finNegative.read((char*)&temp, sizeof(int))) {
            foutFinal.write((char*)&temp, sizeof(int));
            amount--;
        }

        if (finNegative.read((char*)&temp, sizeof(int))) {
            foutFinal.write((char*)&temp, sizeof(int));
            amount--;
        }
    }

    finPositive.close();
    finNegative.close();
    foutFinal.close();

}

void BinToTxt(int amount){
    int temp{};
    ifstream finBin("final.bin", ios_base::binary);
    ofstream foutTxt("final.txt");
     while (amount>0) {
        if (finBin.read((char*)&temp, sizeof(int))) {
            foutTxt << temp << " ";
            amount--;
        }
     }
     finBin.close();
     foutTxt.close();
}

int main() {
    int amount{};
    InputData(amount);
    Processing(amount);
    BinToTxt(amount);
    return 0;
}
