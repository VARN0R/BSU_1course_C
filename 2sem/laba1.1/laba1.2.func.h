#include<bits/stdc++.h>
using namespace std;

void get_words(char** words, const int MAX, char* sentence, int &counter_words){
	const char* dividers = " .,:;!?-()<<>>";//Набор разделителей, с помощью которых делится текст на слова.
	//Создание исходной строки:
	cout << "Enter text: ";
	cin.getline(sentence,MAX);
	char *istr;//Переменная, в которую будут заноситься начальные адреса частей строки sentence   
	istr = strtok (sentence,dividers);//Выделение первой части строки
	//Выделение последующих частей:
	while (istr != NULL){
		words[counter_words]=istr;//Вывод очередной выделенной части
		counter_words++;
		istr = strtok (NULL,dividers);//Выделение очередной части строки
	}
}

void low_registr(char** words, int counter_words, char* str, int length_word){
	 for (int i = 0; i < counter_words; i++) {
        str = words[i];
        length_word = strlen(str);
        for (int j = 0; j < length_word; j++){
        str[j] = tolower(str[j]);
        }
     }
}

void sort_words(char** words, int counter_words){
	for (int i = 0; i < counter_words; i++){
			for (int j= i + 1; j < counter_words; j++){
				if (strlen(words[i]) > strlen(words[j])){
					swap(words[i],words[j]);
				}
			}
		}
}