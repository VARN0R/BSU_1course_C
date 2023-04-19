#include <iostream>

using namespace std;

//Cоздаём класс лист с шаблоном для разных типов данных
template <typename T>
class List{
public: 
    //Прототипы конструкторов и деструктура
    List();
    List(T val);
    List(const List<T> &other);
    List(List<T> &&other);
    ~List();
    
    //Прототип метода push_back
    //Позволяет добавить элемент в конец списка
    void push_back(T data);
    
    //Реализуем получение Size через гетр GetSize, так как это инкапсуляция.
    int size(); 
    
    //Прототип метода pop_front
    //Позволяет удалить первый элемент списка
    void pop_front();
    
    //Прототип метода clear
    //Позволяет очистить список
    void clear();

    //Прототип метода push_front
    //Позволяет добавить элемент в начало списка.
    void push_front(T data);

    //Прототип метода insert
    //Позволяет вставить элемент в список.
    void insert(T value, int index);

    //Прототип метода remove
    //Позволяет удалить элемент по заданному индексу
    void remove(int index);

    //Прототип метода print
    //Позволяет вывести все элементы списка
    void print();
    
    //Прототип метода find_data
    //Позволяет найти индекс элемента по значению
    int find_data(T value);
    
    //перегрузка оператора индексирования
    T& operator[](const int index);

    void operator=(const List<T>& other);

    void operator=(List<T>&& other);

private:
    //Создаём узел односвязного списка
    class Node{
    public:
        //Указатель pNext типа Node, который должен указывать на следующий элемент
        Node *pNext;
       
        //Указатель pPrev типа Node, который должен указывать на предыдущий элемент
        Node *pPrev;
        
        //Данные, которые будут храниться в нашем узле списка
        T data;
        
        //Реализуем конструктор по умолчанию для класса Node и сразу же 
        //присваиваем T() и nullptr чтобы избежать мусора в памяти
        Node(T data = T(), Node* pNext = nullptr, Node *pPrev = nullptr){
            
            //Присваиваем входящие данные соответствующим полям класса Node
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };
    
    //Создаём указатель типа Node на начало списка
    Node *head;
    
    //Создаём указатель типа Node на конец списка
    Node *tail;

    //Чтобы не считать каждый раз количество элементов списка, 
    //проходя по нему, создаём переменную, которая отвечает за размер нашего списка
    int Size;
};

template<typename T>
List<T>::List(){
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
List<T>::List(T val){
    Size = 1;
    head = new Node(val);
    tail = new Node(val);
}

template<typename T>
List<T>::~List(){
    clear();
}

template <typename T>
List<T>::List(const List<T> &other){
    
    //Так как это С++, нам надо обнулить head, чтобы всё работало
    head = nullptr;
    tail = nullptr;
    Size = 0;
    Node *current = other.head;
    while(current!=nullptr){
        push_back(current->data);
        current = current->pNext;
        
    }
}

template <typename T>
List<T>::List(List<T> &&other){

    //Теперь наша голова и размер ссылаюся на такие же параметры другого списка
    tail = other.tail;
    head = other.head;
    Size = other.Size;

    //Так как это конструктор перемещения, очищаем список
    other.head = nullptr;
    other.tail = nullptr;
    other.Size = 0;
} 

template<typename T>
void List<T>::operator=(const List<T>& other){
    
    //Проверяем на то, является ли этот список тем же самым.
    if (this != &other) {
        
        // Очищаем текущий список
        clear();
        
        // Копируем элементы из другого списка в этот
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->pNext;
        }
    }
}

template<typename T>
void List<T>::operator=(List<T>&& other){
    
    //Проверяем на то, чтобы этот список не был тем же самым
    if (this != &other) {
                
        //Очищаем текущий список
        clear();
        
        //Копируем указатель на начало списка и размер списка
        head = other.head;
        tail = other.tail;
        Size = other.Size;
        
        // Обнуляем указатель на начало списка и размер списка в other
        other.head = nullptr;
        other.tail = nullptr;
        other.Size = 0;
    }
}

template <typename T>
int List<T>::find_data(T value){
    
    //Указатель на "голову" списка
    Node* current = head;
    int index = 0;
    
    //Проход по списку
    while(current != nullptr){
        if (current->data == value){
            return index;        
        }
        current = current->pNext;
        index++;
    }

    //Если такого числа нет, возвращаем -1
    return -1;
}

template <typename T>
int List<T>::size(){
    return Size;
}

template <typename T>
void List<T>::print(){
    
    //Указатель на "голову" списка создаём
    Node *current = head;
    int index = 0;
    
    //Проход по всему списку
    while(current != nullptr){
        cout << current->data << "[" << index << "]" << " ";
        current = current->pNext;
        index++;
    }    
}

template<typename T>
void List<T>::push_back(T data){
    
    //Если элементов в списке нет ( т.е. "голова" указывает вникуда), 
    //то мы создаём новый узел и присваем его адрес указателю (нашей "голове")
    if (head == nullptr){
        head = new Node(data);
        tail = head;
    }
    
    //Если же элементы в списке есть, то мы создаём указатель типа Node, 
    //которому сразу же присваем значение головы
    else {
        Node *current = new Node(data);
        
        Node *temp = tail;
        
        tail = current;
        tail->pPrev = temp;
        temp->pNext = tail;
    }
    
    //увеличиваем размер списка
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index){
    int counter = 0;
    
    //Если мы хотим обратиться к несуществующему элементу, то выводим ошибку
    if (index > Size-1){
        throw  out_of_range("List index out of range"); 
    }
    //Создаём указатель current типа Node, который хранит адрес head
    Node *current = head;
    while(counter != index){
        
        //Присваиваем current адрес поля pNext
        current = current->pNext;
        counter++;
    }
    
    //Возвращаем данные current
    return current->data;
}

template<typename T>
void List<T>::pop_front(){

    //if the head is the last element in the list
    if(!head->pNext) {
        delete head;
        Size--;
        return;
    }
    
    //Cоздаём временный указатель на адрес "головы" cписка
    Node *temp = head;

    //присваиваем голове адрес на следующий элемент
    head = head->pNext;
    head->pPrev = nullptr;
    
    //удаляем temp, так как он хранит адрес бывшего первого элемента списка
    delete temp;
    
    //уменьшаем Size, так как размер списка уменьшается
    Size--;
}

template<typename T>
void List<T>::clear(){
    
    //Пока Size больше нуля, мы удаляем каждый элемент списка. 
    //Size изменяется в методе pop_front
    while(Size > 0){
        pop_front();
    }
}

template <typename T>
void List<T>::push_front(T data){
    //Мы создаём новый узел current и присваиваем туда входящие значения
    if (Size == 0){
        push_back(data);
    }
    else { 
        Node *current = new Node(data);

        //Создаём временный указатель temp, чтобы сохранить "голову"
        //Важно, что когда мы присваиваем head, то нам не надо присваивать
        //отдельно данные (например temp->data = head->data). 
        Node *temp = head;

        //Теперь мы нашей "голове" говорим, что она будет current
        head = current;


        //Ну а также мы "голове" говорим указывать на следующий элемент
        head->pNext = temp;
        temp->pPrev = head;
        //Так как мы сохранили current в head, нам больше не нужен current


        //Так как список увеличился на один элемент, увеличиваем его размер соответственно

        Size++;
    }
}

template <typename T>
void List<T>::insert(T value, int index){
    if (index == 0){
        push_front(value);
    }
    else {
        int counter = 0;
        //Новый узел, который мы хатим вставить
        Node *newNode = new Node(value);

        //Указатель на "голову" списка
        Node *prev = head;
        
        //Ищем узел, предшествующий узлу с индексом index. 
        //В условии index-1, так как нам нужен именно указатель на предыдущий элемент.
        //Мы с самого начала инициализируем prev и говорим указывать на head.
        //Если бы проверка была до index, то в последней итерации цикла мы бы присвоили
        //prev указатель на элемент с индексом index, а не предыдущий.  
        while(counter < index - 1){
            prev = prev->pNext;
            counter++;
        }
        
        //Присваиваем указателю нашего узла, который мы хотим вставить, указатель 
        //элемента, который находился перед элементом замены 
     
        newNode->pNext = prev->pNext;
        newNode->pPrev = prev;
    
        prev->pNext = newNode;  
        newNode->pNext->pPrev = newNode;

        //Указателю элемента, который находился перед элементом замены,
        //присваиваем значение узла, который надо вставить. 
            
        //Увеличиваем размер списка
        Size++;    
    }
    
}

template <typename T>
void List<T>::remove(int index){
    if (index == 0){
        pop_front();
    }
    else {
        int counter = 0;
        
        //Указатель на предыдущий элемент, который пока указывает на head
        Node *prev = head;
        //Ищем элемент, который находится перед тем, который нужно удалить
        while(counter < index - 1){
            prev = prev->pNext;
            counter++;
        }
        
        //Создаём указатель на элемент, который нам надо удалить
        Node *toDelete = prev->pNext;
        
        //Говорим указывать элементу, который стоит перед удаляемым элементом, указывать на элемент,
        //который идёт после удаляемого
        prev->pNext = toDelete->pNext;
        toDelete->pNext->pPrev = prev;
        delete toDelete;  
        
        Size--;
    }
}

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
    return 0;
}