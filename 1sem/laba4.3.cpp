/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Выполнить задание, используя C-строки для представления данных.

Текст – непустая последовательность символов.
Слово – непустая последовательность любых символов, кроме символов-раз-
делителей.
Предложение – последовательность слов, разделенных одним или несколь-
кими символами-разделителями.
Символы-разделители: «пробел», «.», «,», «:», «;», «!», «?», «-», «(», «)».

Записать в новую строку слова, которые состоят из тех же букв, что и последнее
слово заданной строки символов.
-------------------------------------------------------------------------------
ENGLISH
Perform a task using C-strings to represent data.

Text is a non–empty sequence of characters.
A word is a non–empty sequence of any symbols, except
for the divisor symbols.
A sentence is a sequence of words separated by one or
more delimiter characters.
Delimiter characters: "space", ".", ",", ":", ";", "!", "?", "-", "(", ")".

Write to a new line words that consist of the same letters as the last
word of the specified string of characters.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include<bits/stdc++.h> 
using namespace std;


int main(){
	const int MAX = 500;
    const char* dividers = " .,:;!?-()";

    char sentence[MAX]{};

	cout << "Enter sentence: ";
	cin.getline(sentence,sizeof(sentence));

	char* sentence_copy = strdup(sentence);//копирует sentence тк strtok меняет строку при его использованнии
    char* word = strtok(sentence_copy, dividers);//смотрим первое слово, тем самым говорим strtok в какой строке искать слово
    char* word_last = word;
	while(word){
		word_last = word;//присваиваем last'у word тем самым после конца вайла это будет ласит ворд		
		word = strtok(nullptr, dividers);//проходим по строке, путем передици нулевого указателя говорим strtok'у что работа производится над той же строкой
		                                                                                                           
	}
		
	cout << "Last word:\n";
	cout << "-----" <<endl;
	cout << word_last << endl; 
	cout << "-----" <<endl << endl;
		
		
	sentence_copy = strdup(sentence);
	word = strtok(sentence_copy, dividers);
	while(word){
		int i = 0;
		bool correct = true;

		while(word[i]!='\0'){//чекаем буквы в слове
			if(!strchr(word_last, word[i])){//если буква в текущем слове не встречается в последнем слове то correct = false
				correct = false;
				break;
			}
			i++;
		}
		
		if(correct)//проверка как было описано выше
			cout << word << endl;
		
		word = strtok(nullptr, dividers);// идем дальше по строке
	}
    
    return 0;
   } 