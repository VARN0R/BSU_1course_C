/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Написать программу для создания массива записей со сведениями о студен-
тах (имя, возраст, курс, пол, успеваемость). Оформить заполнение и ввод, вывод
массива отдельными функциями. Написать функцию, которая по заданному мас-
сиву определяет имя самого младшего студента n курса.                            
-------------------------------------------------------------------------------
ENGLISH
Write a program to create an array of records with information about students
(name, age, course, gender, academic performance). Arrange the filling and input, output
of the array by separate functions. Write
a function that determines the name of the youngest student of the n course.
-------------------------------------------------------------------------------
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;



struct Student{
    string name;
    int age;
    int course;
};

bool comp (const Student& left, const Student& right) {
	return left.age<right.age; 
}

vector<Student> input(){
	vector<Student> a;

    int counter_students = 0;
    cout << "Enter the number of students: ";
    cin >> counter_students;
    cin.ignore();
        
    for(int i=0;i<counter_students;i++){
    	Student stud;
    	
        cout << "Enter name: ";
        getline(cin, stud.name);
        
        cout << "Enter age: ";
        cin >> stud.age;
        
        cout << "Enter course: ";
        cin >> stud.course;
        cin.ignore();
        
        cout << "\n";
        a.push_back(stud);
    }
    
    return a;
}

void output(const vector<Student> &a){
    cout << "-----------------------------------";
    for(auto& stud : a){
        cout << "name: " << stud.name << "\n";
        cout << "age: " << stud.age << "\n";
        cout << "course: " << stud.course << "\n\n";
    }
}



void junior(vector<Student> &a, int course){
    sort(a.begin(), a.end(), comp);
    for(const auto& student : a){
        if(student.course == course){
            cout << "the youngest student in the course " << course << ": " << student.name;
            return;
        }
     }
     cout << "null";
}


int main(){
    int n;
    auto a = input();
    cout << "Which course to choose?";
    cin >> n;
    junior(a, n);
    return 0;
}

