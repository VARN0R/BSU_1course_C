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
struct Tree{
public:    
    int read_list(){
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

    void generate(int n){
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

    void print_list(){
        auto *it = head;
        while(it){
            std::cout << it->val << " ";
            it = it->next;
        }
    }

    void delete_list(){
        auto *it = head;
        while(it){
            auto* del = it;
            it = it->next;
            delete del;
        }
        delete it;
    }

private:

    Node *head = nullptr;

    Node* node_create(){
        Node* new_node = new Node{};
        fin >> new_node->val;
        return new_node;
    }

    void node_add(Node *item){
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

};

int main(){
    Tree head;
    int len = head.read_list();
    std::cout << "Your input:\n";
    head.print_list();
    head.generate(len);
    head.delete_list();
    fin.close();
}