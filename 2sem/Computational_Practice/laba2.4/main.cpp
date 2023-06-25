/*
TASK CONDITION
-------------------------------------------------------------------------------
Выполнить задания, используя связанные динамические структуры данных
«список» в виде связных компонент.  Описать функцию, которая формирует список символов L, включив в него
по одному разу элементы, которые входят одновременно в оба списка L1 и L2.
 -------------------------------------------------------------------------------
ENGLISH
Perform tasks using linked dynamic
"list" data structures in the form of connected components.  
Describe a function that generates a list of characters L by including in it
once the elements that are included simultaneously in both lists L1 and L2.
-------------------------------------------------------------------------------
*/

#include "laba2.4.h"
using namespace std;

int main(){
    Node *head = new Node{};
    Node *L1 = new Node{};
    Node *L2 =new Node{};
    read_list(L1);
    read_list(L2);
    generate(head, L1, L2);
    cout << "L:\n";
    print_list(head);
    cout << "\nL1:\n";
    print_list(L1);
    cout << "\nL2:\n";
    print_list(L2);
    delete_list(head);
    delete_list(L1);
    delete_list(L2);
}