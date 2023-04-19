#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Node{
	int val;
	Node *next = nullptr;
    Node *prev = nullptr;
};

std::ifstream fin("input2.6.txt");

class Tree{
    private:
    
    Node* node_create(){
        Node* new_node = new Node{};
        fin >> new_node->val;
        return new_node;
    }

    void node_add(Node *&head, Node *item){
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
    public:
    Node *list;
    int read_list(Node *&head){
        int n, len;
        fin >> n;
        len = n;
        n = 2*n;
        while(n--){
            auto* item = node_create();
            node_add(head, item);
        }
        return len;
    }


    void generate(Node *&head, int n){
        int res = 0;
        auto *l = head;
        auto *r = head;
        while(r->next)
            r = r->next;
        for(int i = 0;i<n;i++){
            res += l->val * r->val;
            l = l->next;
            r = r->prev;
        }
        std::cout << std::endl << res;
    }

    void print_list(Node *head){
        auto *it = head;
        while(it){
            std::cout << it->val << " ";
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

};
