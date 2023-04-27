/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Заданное натуральное число от 1 до 1999 вывести римскими цифрами.
-------------------------------------------------------------------------------
ENGLISH
The given natural number from 1 to 1999 is output in Roman numerals.
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main () {
	cout << "Enter Integer num: ";
	int num;
	cin >> num;
	string res = "";
	vector<pair<int, string>> Int_and_Roman = {{1000, "M"}, {900, "CM"}, 
	{500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
	{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
	for (int i = 0; i < Int_and_Roman.size(); i++){
		while (num >= Int_and_Roman[i].first){
			res += Int_and_Roman[i].second;
			num -= Int_and_Roman[i].first;
		}
	}
	cout << res;
	return 0;	
}