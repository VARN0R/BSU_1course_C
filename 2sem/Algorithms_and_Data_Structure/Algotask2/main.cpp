/*
TASK CONDITION
-------------------------------------------------------------------------------
Дана строка строки, содержащая только символы '(', ')', '{', '}', '[' и ']', определите, является ли
входная строка допустимой.

Входная строка допустима, если:

Открытые скобки должны быть закрыты скобками того же типа.
Открытые скобки должны быть закрыты в правильном порядке.
Каждая закрывающая скобка имеет соответствующую открытую скобку того же типа.
-------------------------------------------------------------------------------
ENGLISH
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the 
input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isOpen(char ch){
    return ch =='(' || ch == '[' || ch == '{';
}

bool isPair (char open, char close){
    return ('(' == open && ')' == close) || ('[' == open && ']' == close) || ('{' == open && '}' == close);
}   

bool isValid (string s, int len){
     stack <char> st;
     for (int i = 0; i < len; i++){
        if (isOpen(s[i])){
            st.push(s[i]);
        }
        else 
            if (!st.empty() && isPair(st.top(),s[i])){
                st.pop();
            } 
            else {
                return false;
            }
    }
    return st.empty();
}
int main(){
    string s = "([{}])"; 
    int len = s.size();
    cout << isValid(s, len);
    return 0;
}