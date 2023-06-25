#include "laba2.4.h"
using namespace std;

ifstream fin("laba2.4.txt");

Node* node_create(){
    Node* new_node = new Node{};
	fin >> new_node->val;
	return new_node;
}

void node_add(Node *&head, Node *item){
    //head
    if(head->val == INT16_MAX){// будет ли элемент первым элементом в списке head, и удалите head для замены
        auto* tmp = head;
        head=item;
        delete tmp;
        return;
    }
    if(head->val > item->val){// должен ли элемент быть головным
        item->next = head;
        head=item;
        return;
    }

    //iterating
    auto *it = head;
    while(it->next and item->val > it->next->val)
        it = it->next;
    item->next = it->next;
    it->next = item;
}

void read_list(Node *&head){
    int n;
    fin >> n;
    while(n--){
        auto* item = node_create();
        node_add(head, item);
    }
}

Node *delete_node(Node *&head, Node *to_delete){
    auto *it = head;    
    if(it == to_delete){
        head = head->next;
        it->next = nullptr;
        return head;
    }
    while(it->next != to_delete){
        it = it->next;
    }
    it->next = to_delete->next;
    to_delete->next = nullptr;
    return it->next;
}

void generate(Node *&head, Node *&L1, Node *&L2){
    auto *it = L1;
    while(it){
        auto *it2 = L2;
        bool found = false;                        
        while(it2){
            if(it->val == it2->val){
                found = true;
                break;
            }
            else{
                it2 = it2->next;
            }
        }
        if(found){
            auto *check = head;
            while(true){                       //   проверьте, было ли это значение уже добавлено в head
                if(check->val == it->val){
                    it = it->next;
                    break;
                }
                else{
                    //если мы дошли до конца head и не нашли повторяющихся значений, мы добавляем их в head
                    if(!check->next){
                        
                        node_add(head, new Node(it->val));
                        it = it->next;                        
                        break;
                    }
                    else
                        check = check->next;
                }
            }
        }
        else
            it = it->next;
    }
}

void print_list(Node *head){
    auto *it = head;
    while(it){
        std::cout << it->val << std::endl;
        it = it->next;
    }
}

void delete_list(Node *&head){
    auto *it = head;
    while(it){
        auto* del = it;
        it = it->next;
        delete del;
    }
    delete it;
}