#pragma once
#include<iostream>
#include<fstream>
#include<string>

struct Node{
	int val;
	Node *next = nullptr;
    Node *prev = nullptr;
};

struct Tree{
public:    
    int read_list();
    void generate(int n);
    void print_list();
    void delete_list();
private:
    Node *head = nullptr;
    Node* node_create();
    void node_add(Node *item);
};

