/*
TASK CONDITION
-------------------------------------------------------------------------------
Записать слова в первый файл с консоли, а потом записать их же во второй файл, 
но в другом порядке.
-------------------------------------------------------------------------------
ENGLISH
Write the words to the first file from the console, and then write them to the second file, 
but in a different order.
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <fstream>
using namespace std;
int main(){
    stack<string>st;
    
    ofstream fout;
    fout.open("file1.txt");
    int amount{};
    cout << "Amount words: ";
    cin >> amount;
    string temp;
    for (int i = 0; i < amount; i++){
        cin >> temp;
        fout << temp << " ";
    }
    fout.close();
    
    ifstream fin;
    fin.open("file1.txt");
    cout << "STACK: " << endl;
    while(fin >> temp){
        st.push(temp);
        cout << st.top() << " ";
    }
    fin.close();

    ofstream fout2("file2.txt");
    while(!st.empty()){
        fout2 << st.top() << " ";
        st.pop();
    }

    return 0;
}