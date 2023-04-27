/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Объявить шаблон класса «Линейный список». Определить структуру класса
и его методы. В классе должны быть конструктор без параметров, конструктор
с параметрами, деструктор и всё что необходимо согласно «правилу пяти».
Определить методы:
• инициализация первого элемента структуры;
• добавления в структуру нового элемента;
• удаление элемента;
• поиск элемента по заданному ключу поиска (значению информационного
поля);
• вывод элементов списка на экран;
• удаления списка.
Используя объекты класса «Линейный список», реализовать алгоритмы
своих вариантов заданий 2.4 «Учебной вычислительной практики».
-------------------------------------------------------------------------------
ENGLISH
Declare the template of the "Linear List" class. Define the class structure
and its methods. The class should have a constructor without parameters, a constructor
with parameters, a destructor and everything that is necessary according to the "rule of five".
Define methods:
• initialization of the first element of the structure;
• adding a new element to the structure;
• deleting an item;
• search for an element by the specified search key (value of the information
field);
• display of list items on the screen;
• deleting the list.
Using objects of the "Linear List" class, implement algorithms
their own versions of tasks 2.4 "Educational computing practice".
-------------------------------------------------------------------------------
*/

#include "laba2.2.h"

int main(){
    List<int> lst;
    cout << "----------------- Method push_back -----------------" << endl;
    for (int i = 0; i < 5; i++){
        lst.push_back(i*10+1);
    }
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;
    
    cout << "----------------- Method push_front -----------------" << endl;
    lst.push_front(154);
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;
    
    cout << "----------------- Method pop_front -----------------" << endl;
    lst.pop_front();
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;
    
    cout << "----------------- Method insert -----------------" << endl;
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;
    lst.insert(1111, 3);
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;
    
    cout << "----------------- Method remove -----------------" << endl;
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;
    lst.remove(3);
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;

    cout << "----------------- Method find_data -----------------" << endl;
    lst.print();
    cout << "Size = " << lst.size() << endl;
    cout << endl;
    cout << "Index 41 = " << lst.find_data(41);
    cout << endl;
    
    cout << "----------------- Method clear -----------------" << endl;
    lst.clear();
    cout << "Size = " << lst.size() << endl;

    //Позволяет лавить ошибку, которую мы добавили в методе с перегрузкой []
    try{
        
        //Так мы очистили список, происходит обращение к несуществующему элементу,
        //что и вызывает ошибку
        cout << lst[0];
        cout << lst[1];
        cout << lst[2];
    } catch (out_of_range e) {
        cout << "!!!Error catched!!!" << endl;
    }
    
    //Хоть у нас и ошибка, код дальше продолжает выполняться
    cout << "Hello" << endl;
    cout << endl;
    cout << endl;
    
    cout << "----------------- Operator copy -----------------" << endl;
    List<int> lst2;
    List<int> lst1;
    lst1.push_back(5);
    cout << lst1[0] << " <-------lst1" << endl;
    cout << "Size = " << lst1.size() << endl;
    lst2 = lst1;
    cout << "Loading..." << endl;
    cout << lst2[0] << " <--------lst2" << endl;
    cout << "Size = " << lst2.size() << endl;
    cout << lst1[0] << " <--------lst1" << endl;
    cout << "Size = " << lst1.size() << endl;
    
    cout << "----------------- Constructor copy -----------------" << endl;
    lst1[0] = 10;
    lst1.print();
    cout << "Size = " << lst1.size() << endl;
    cout << endl;
    List<int> lst3(lst1);
    cout << "Loading..." << endl;
    lst3.print();
    cout << "Size = " << lst3.size() << endl;
    cout << endl;
    lst1.print();
    cout << "Size = " << lst1.size() << endl;
    
    
    cout << "----------------- Constructor move -----------------" << endl;
    //move constructors
    List<int> mov_constr_test;
    mov_constr_test.push_back(1);
    mov_constr_test.push_back(2);
    mov_constr_test.push_back(3);
    cout << "Size = " << mov_constr_test.size() << endl;
    List<int> move_constructor(std::move(mov_constr_test));
    cout << "Loading..." << endl;
    move_constructor.print();
    cout << "Size = " << move_constructor.size() << endl;
    cout << "Size = " << mov_constr_test.size() << endl;
    mov_constr_test.print();

    cout << endl;

    cout << "----------------- Operator move -----------------" << endl;
    List<int> mov_op_test;
    mov_op_test.push_back(1);
    mov_op_test.push_back(2);
    mov_op_test.push_back(3);
    cout << "Size = " << mov_op_test.size() << endl;
    List<int> move_operator;
    cout << "Loading..." << endl;
    move_operator = std::move(mov_op_test);
    move_operator.print();
    cout << "Size = " << move_operator.size() << endl;
    cout << "Size = " << mov_op_test.size() << endl;
    mov_op_test.print();


    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    List<int> numbers1;
    List<int> numbers2;
    List<int> res;

    cout << "Enter size numbers1: " << endl;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        numbers1.push_back(i+1);
    }
    cout << "Enter size numbers2: " << endl;
    cin >> N;
    for (int i = 0; i < N; i++){
        numbers2.push_back(i+2);
    }
    numbers1.print();
    cout << endl;
    numbers2.print();
    cout << endl;
    
    for (int i = 0; i < numbers1.size(); i++){
        for (int j = 0; j < numbers2.size(); j++){
            if (numbers1[i] == numbers2[j]){
                bool found = false;
                for (int k = 0; k < res.size(); k++){
                    if (res[k] == numbers1[i]){
                        found = true;
                        break;
                    }
                }
                if (found == false){
                    res.push_back(numbers1[i]);
                    break;
                }
            }
        }
    }
    res.print();

    
    return 0;
}