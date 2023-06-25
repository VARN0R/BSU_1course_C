#pragma once
#include<iostream>
#include<fstream>
#include<string>

struct Node{
	int val=INT16_MAX;
	Node *next = nullptr;
    Node(){}
    Node(int val) {
        this->val = val;
    }
};

Node* node_create();
void node_add(Node *&head, Node *item);
void read_list(Node *&head);
Node *delete_node(Node *&head, Node *to_delete);
void generate(Node *&head, Node *&L1, Node *&L2);
void print_list(Node *head);
void delete_list(Node *&head);