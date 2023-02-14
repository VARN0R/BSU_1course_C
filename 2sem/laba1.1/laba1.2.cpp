/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполнить следующее задание для заданного текста. Оформить задание в виде набора функций: 
функция создания массива слов, функция получения результирующей строки.

Текст – непустая последовательность символов.
Слово – непустая последовательность любых символов, кроме символов-разделителей.
Предложение – последовательность слов, разделенных одним или несколькими символами-разделителями.
Символы-разделители: «пробел», «.», «,», «:», «;», «!», «?», «-», «(», «)».

Получить текст, в котором слова исходного текста упорядочены по длине слов.  
Дополнительно: написать функцию, которая преобразует все полученные слова в нижний регистр.
-------------------------------------------------------------------------------
ENGLISH
Perform the following task for the specified text. Formalize the task as a set of functions: 
the function of creating an array of words, the function of obtaining the resulting string.

Text is a non–empty sequence of characters.
A word is a non–empty sequence of any characters except delimiter characters.
A sentence is a sequence of words separated by one or more delimiter characters.
Delimiter characters: "space", ".", ",", ":", ";", "!", "?", "-", "(", ")".

Get a text in which the words of the source text are ordered by word length.  
Additionally: write a function that converts all received words to lowercase.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include<bits/stdc++.h> 
#include "laba1.2.func.h"
using namespace std;

int main(){
    int counter_words = 0;
    const int MAX = 500;
    char str[MAX]{};//Переменная, которая хранит word[i] в функции low_registr
    int length_word = 0;//Переменная, которая определяет длину слова в функции low_registr
    char** words = new char*[MAX];
    for (int i = 0; i < MAX; i++){
        words[i] = new char[MAX];
    }
    char sentence[MAX]{};

    get_words(words, MAX, sentence, counter_words);
    low_registr(words, counter_words, str, length_word);
    sort_words(words, counter_words);
    cout << "Text consists of " << counter_words << " words." << endl;
    cout << "The words of the text are displayed in ascending order depending on the number of letters." << endl;
    for (int i = 0; i < counter_words; i++){
        cout << words[i] << endl;
    }
    return 0;
}