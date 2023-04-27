/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
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

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(string& func_s){
    map<char, int> func_map;
    for (int i = 0; i < func_s.size(); i++){
        func_map[func_s[i]]++;
    }
    return func_map;
}

int main(){
    string dividers = " .,:;!?-()";
    string input_line;

    getline(cin, input_line);

    bool found = false;
    string temp_word ="";
    vector<string> words;
    string last_word = "";
    
    for (int i = 0; i < input_line.size(); i++){
        if (dividers.contains(input_line[i])){
            words.push_back(temp_word);
            temp_word = "";
            found = true;
        }
        if (!found){
            temp_word += input_line[i];
        }
        found = false;
    }
    
    if (temp_word != ""){
        words.push_back(temp_word);
    }

    last_word = words[words.size() - 1];
    temp_word ="";
    string res = "";

    cout << "Words: " << endl;
    for (int i = 0; i < words.size(); i++){
        cout << words[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < words.size() - 1; i++){
        temp_word = words[i];
        if (BuildCharCounters(temp_word) == BuildCharCounters(last_word)){
            res += temp_word;
            res += " ";
            temp_word = "";
        }
    }
    cout << "res = " <<  res;
    return 0;
}