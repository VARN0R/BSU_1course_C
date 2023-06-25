/*
TASK CONDITION
-------------------------------------------------------------------------------
Решение задачи из laba1.3 только через текстовый файл
 -------------------------------------------------------------------------------
ENGLISH
Solving the problem from laba1.3 only through a text file
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct Students {
    char name[20];
    int age;
    char female;
    int cource;
    int marks;
};

void StudentInFile(int &amount){//функция для ввода студентов в файл
    ofstream fout("source.txt"); 
    for(int i = 0; i < amount; i++){
        Students temp_person; // временная перемена в которую мы будем класть данные текущего студента
        cout << "Enter name: ";
        cin >> temp_person.name;
        fout << temp_person.name << " ";
        cout << "Enter female: ";
        cin >> temp_person.female;
        fout << temp_person.female << " ";
        cout << "Enter cource: ";
        cin >> temp_person.cource;
        fout << temp_person.cource << " ";
        cout << "Enter marks: ";
        cin >> temp_person.marks;
        fout << temp_person.marks << " ";
        cout << endl;
    }
    fout.close();
}

void StudentOutFile(){ // функция для вывода студентов из файла на экран
    ifstream fin("sorted.txt");
    Students temp_person;// опять же временная переменная для хранения данных о текущем студенте
    while(fin >> temp_person.name >> temp_person.female >> temp_person.cource >> temp_person.marks){ //считываем данные с файла в эту переменную
        //выводим все что считали на экран
        cout << "NAME: "<< temp_person.name << endl;
        cout << "FEMALE: "<< temp_person.female << endl;
        cout << "COURCE: "<< temp_person.cource << endl;
        cout << "MARKS: "<< temp_person.marks << endl;
        cout << endl;
    }
    fin.close();
}

void StudentSort(){//функция для сортировки студентов в зависимости от их оценки
    ifstream fin("source.txt");
    ofstream fout("sorted.txt");
    Students temp_person;
    cout << "Enter good mark: ";
    int good_mark;
    cin >> good_mark;
    while(fin >> temp_person.name >> temp_person.female >> temp_person.cource >> temp_person.marks){ 
        if (temp_person.marks >= good_mark){
            fout << temp_person.name << " ";
            fout << temp_person.female << " ";
            fout << temp_person.cource << " ";
            fout << temp_person.marks << " ";
        }
        else {
            continue;
        }
    }
    fin.close();
    fout.close();
}

int main(){
    int amount{};
    cout << "Enter amount students: ";
    cin >> amount;
    StudentInFile(amount);
    StudentSort();
    StudentOutFile();
    return 0;
}