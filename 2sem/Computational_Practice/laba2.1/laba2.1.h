#pragma once

struct element{
    int val{};
    char meet{0};
};

element* binary_search(element *arr, int len, int to_search);
void insert(element *arr, element *pos, element ins, int &len);
void del_el(element *arr, element *pos, int &len);
int read_array(element *arr);
int read_rand_array(element *arr);
void print_array(element *arr, int n);
void clear_array(element *arr, int &len);