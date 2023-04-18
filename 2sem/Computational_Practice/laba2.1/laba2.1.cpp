#include <iostream>
using namespace std;
#include "laba2.1.h"

struct element;


element* binary_search(element *arr, int len, int to_search){
    int l = 0, r = len, m;
    while(l!=r){
        if(r-l == 1 and arr[r].val != to_search and arr[l].val != to_search){
            if(l != 0){
                return &arr[l];
            }
            else if(to_search > arr[l].val)
                return arr;
            else
                return nullptr;
        }
        m = (r+l)/2;
        if(arr[m].val == to_search)
            return &arr[m];
        else{
            if(arr[m].val < to_search)
                l = m;
            else
                r = m;
        }
    }
    return &arr[l];
}

void insert(element *arr, element *pos, element ins, int &len){
    if(pos == nullptr){
        for(int i = len-1; i!=-1;i--){
            arr[i+1] = arr[i];
        }
        arr[0] = ins;
        return;
    }
    if(pos->val == ins.val){
        pos->meet++;
        if(pos->meet > 1)//do it for preventing overflow of char
            pos->meet = 2;
        len--;
        return;
    }
    for(int i = len-1; arr[i].val != pos->val;i--){
        arr[i+1] = arr[i];
    }
    *(pos+1) = ins;
}


void del_el(element *arr, element *pos, int &len){
    bool was_found = false;
    for(int i = 0; i<len-1;i++){
        if(arr[i].val == (*pos).val){
            was_found = true;
        }
        if(was_found){
            arr[i] = arr[i+1];
        }
    }
    len--;
}

int read_array(element *arr){
    cout << "Enter length of array: ";
    int n, tmp, counter{};
    cin >> n;
    cin >> tmp;
    arr[0] = {tmp, 1};
    counter++;
    for(int i =1; i<n;i++){
        cin >> tmp;
        insert(arr, binary_search(arr, counter, tmp), {tmp, 1}, counter);
        counter++;
    }
    clear_array(arr, counter);
    return counter;
}

int read_rand_array(element *arr){
    srand(time(NULL));
    cout << "Enter length of array: ";
    int n, tmp, counter{};
    cin >> n;
    tmp = rand()%10+1;
    cout << tmp << " ";
    arr[0] = {tmp, 1};
    counter++;
    for(int i =1; i<n;i++){
        tmp = rand()%10+1;
        cout << tmp << " ";
        insert(arr, binary_search(arr, counter, tmp), {tmp, 1}, counter);
        counter++;
    }
    cout << endl;
    print_array(arr, counter);
    cout << endl;
    clear_array(arr, counter);
    return counter;
}



void print_array(element *arr, int n){
    cout << endl;
    for(int i=0;i<n;i++){
        cout << arr[i].val << " ";
    }
}

void clear_array(element *arr, int &len){
    int c{}, i{}, len_cpy{len};
    while(c!=len_cpy){
        if(arr[i].meet = 1){
            del_el(arr, &arr[i], len);
        }
        else
            i++;
        c++;
    }
}