/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Написать программу перевода вещественных чисел из шестнадцатеричной
системы счисления в двоичную.
-------------------------------------------------------------------------------
ENGLISH
Write a program for converting real numbers from
hexadecimal to binary.
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

string hexToBin(string hex)
{
    string bin = "";
    for (int i = 0; i < hex.size(); i++) {
        switch (hex[i]) {
            case '0': bin += "0000"; break;
            case '1': bin += "0001"; break;
            case '2': bin += "0010"; break;
            case '3': bin += "0011"; break;
            case '4': bin += "0100"; break;
            case '5': bin += "0101"; break;
            case '6': bin += "0110"; break;
            case '7': bin += "0111"; break;
            case '8': bin += "1000"; break;
            case '9': bin += "1001"; break;
            case 'A': bin += "1010"; break;
            case 'B': bin += "1011"; break;
            case 'C': bin += "1100"; break;
            case 'D': bin += "1101"; break;
            case 'E': bin += "1110"; break;
            case 'F': bin += "1111"; break;
            default: cout << "Incorrect character in the string\n"; return "";
        }
    }
    return bin;
}

int main()
{
    string hex;
    cout << "Enter number in hex system: ";
    cin >> hex;

    string bin = hexToBin(hex);
    if (bin != "") {
        cout << "Number in binary system: " << bin << endl;
    }

    return 0;
}

