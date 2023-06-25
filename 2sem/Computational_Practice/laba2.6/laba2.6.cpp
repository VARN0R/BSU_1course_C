#include "laba2.6.h"
using namespace std;

ifstream fin("input2.6.txt");

int Tree::read_list(){
    int n, len;
    fin >> n;
    len = n;
    n = 2*n;
    while(n--){
        auto* item = node_create();
        node_add(item);
    }
    return len;
}

void Tree::generate(int n){
    int res = 1;
    auto *l = head;
    auto *r = head;
    while(r->next)
        r = r->next;
    for(int i = 0;i<n;i++){
        res *= (l->val - r->val);
        l = l->next;
        r = r->prev;
    }
    std::cout << std::endl << res;
}

void Tree::print_list(){
    auto *it = head;
    while(it){
        std::cout << it->val << " ";
        it = it->next;
    }
}

void Tree::delete_list(){
    auto *it = head;
    while(it){
        auto* del = it;
        it = it->next;
        delete del;
    }
    delete it;
    fin.close();
}

Node* Tree::node_create(){
    Node* new_node = new Node{};
    fin >> new_node->val;
    return new_node;
}

void Tree::node_add(Node *item){
    //head
    if(!head){
        head=item;
        return;
    }

    //iterating
    auto *it = head;
    while(it->next)
        it = it->next;
    it->next = item;
    item->prev = it;

}



