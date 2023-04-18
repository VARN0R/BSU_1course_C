//coming soon for three files





#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Node{
	int val=INT16_MAX;
	Node *next = nullptr;
};

std::ifstream fin("laba2.4.txt");


Node* node_create(){
    Node* new_node = new Node{};
	fin >> new_node->val;
	return new_node;
}

void node_add(Node *&head, Node *item){
    //head
    if(head->val == INT16_MAX){//будет ли элемент первым элементом в списке head, и удалите head для замены
        auto* tmp = head;
        head=item;
        delete tmp;
        return;
    }
    if(head->val > item->val){//должен ли элемент быть головным
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
                        auto *tmp = delete_node(L1, it);
                        node_add(head, it);
                        it = tmp;                        
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

int main(){
    Node *head = new Node{};
    Node *L1 = new Node{};
    Node *L2 =new Node{};
    read_list(L1);
    read_list(L2);
    generate(head, L1, L2);
    std::cout << "L:\n";
    print_list(head);
    std::cout << "\nL1:\n";
    print_list(L1);
    std::cout << "\nL2:\n";
    print_list(L2);
    delete_list(head);
    delete_list(L1);
    delete_list(L2);
}