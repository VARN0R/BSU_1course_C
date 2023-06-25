/*
-------------------------------------------------------------------------------
Написать программу для работы с базой данных, содержащей записи со сведениями
о студентах: ФИО, возраст, пол, курс, успеваемость, в которой должны
выполняться следующие действия: создание файла, просмотр файла
Выполнить задания для бинарного файла. Размер файлов <= 64GiB.

По исходному файлу определить всех отличников. Сформировать файл из
этих студентов.
-------------------------------------------------------------------------------
Write a program to work with a database containing records with information
about students: full name, age, gender, course, academic performance, in which
the following actions should be performed: creating a file, viewing a file
Perform tasks for the binary file. File size <= 64 Gb.

Determine all the excellent students from the source file. Generate a file from
these students.
--------------------------------------------------------------------------------
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

void StudentInFile(int &amount){
    ofstream fout("source.bin", ios_base::binary);
    for(int i = 0; i < amount; i++){
        Students temp_person;
        cout << "Enter name: ";
        cin >> temp_person.name;
        cout << "Enter female: ";
        cin >> temp_person.female;
        cout << "Enter cource: ";
        cin >> temp_person.cource;
        cout << "Enter marks: ";
        cin >> temp_person.marks;
        cout << endl;
        fout.write(reinterpret_cast<char*>(&temp_person), sizeof(Students));
    }
    fout.close();
}

void StudentOutFile(){
    ifstream fin("sorted.bin", ios_base::binary);
    Students temp_person;
    while(fin.read((char*)&temp_person, sizeof(Students))){
        cout << "NAME: "<< temp_person.name << endl;
        cout << "FEMALE: "<< temp_person.female << endl;
        cout << "COURCE: "<< temp_person.cource << endl;
        cout << "MARKS: "<< temp_person.marks << endl;
        cout << endl;
    }
    fin.close();
}

void StudentSort(){
    ifstream fin("source.bin", ios_base::binary);
    ofstream fout("sorted.bin", ios_base::binary);
    Students temp_person;
    cout << "Enter good mark: ";
    int good_mark;
    cin >> good_mark;
    while(fin.read((char*)&temp_person, sizeof(Students))){
        if (temp_person.marks >= good_mark){
            fout.write((char*)&temp_person, sizeof(Students));
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