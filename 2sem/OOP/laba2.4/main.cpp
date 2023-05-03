/*
TASK CONDITION
-------------------------------------------------------------------------------
RUSSIAN
Объявить класс для решения задачи и определить его методы.
Реализовать:
• конструкторы без параметров, с параметрами,
• деструктор,
• другие методы согласно «правилу пяти»,
• перегрузить операции ввода/вывода данных,
• указанные в задании операции реализовать посредством перегрузки операций.
Объявление класса разместить в заголовочном файле, определения методов –
во втором файле, определение главной функций программы – в третьем файле.
Продемонстрировать корректную работу всех операций и методов реализован-
ного класса.
Определить класс для работы с объектом «строка символов». Реализовать:
вставку в строку указанного символа в заданную позицию, удаление ведущих про-
белов. Добавить в заданную строку отсутствующие символы из второй заданной
строки, на позиции с такими же номерами.
-------------------------------------------------------------------------------
ENGLISH
Declare a class to solve the problem and define its methods.
Implement:
• constructors without parameters, with parameters,
• destructor,
• other methods according to the "rule of five",
• overload data input/output operations,
• implement the operations specified in the task by overloading operations.
Place the class declaration in the header file, method definitions
in the second file, and the definition of the main program functions in the third file.
Demonstrate the correct operation of all operations and methods of the implemented
class.
Define a class for working with the "string of characters" object. Implement:
inserting the specified character into the string at the specified position, removing the leading
characters. Add missing characters from the second specified
string to the specified line, in positions with the same numbers.
-------------------------------------------------------------------------------
*/
#include "laba2.4.h"

int main(){
    MyString my("   hello  ");
    my.deleteLeadSpaces();
    std::cout << my << std::endl;
    MyString test1("  Rundsa  ");
    MyString test2("wd   wddwdwd");
    test1.addChar(test2);
    std::cout << test1;
    return 0;
}