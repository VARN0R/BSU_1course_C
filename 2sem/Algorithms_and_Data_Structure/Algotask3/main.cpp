/*
TASK CONDITION
-------------------------------------------------------------------------------
Найти минимальный элемент в левой части и минимальный элемент в правой части  
-------------------------------------------------------------------------------
ENGLISH
Find the min element in the left part and the min element in the right part
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void Found(vector<int>nums){
    int len = nums.size();
    int mid = len / 2 + 1;
    cout << mid << endl;
    stack<int>st;
    stack<int>st2;
    for (int i = 0; i < mid; i++){
        if(st.empty()){
            st.push(nums[i]);
            continue;
        }
        if (nums[i] < st.top()){
            st.pop();
            st.push(nums[i]);
        }
    }	
    int min_left = st.top();
    cout << min_left << endl;
    for(int i = mid; i < len; i++){
         if(st2.empty()){
            st2.push(nums[i]);
            continue;
        }
        if (nums[i] < st2.top()){
            st2.pop();
            st2.push(nums[i]);
        }
    }
    int min_right = st2.top();
    cout << min_right << endl; 
}

int main(){
    vector<int>nums;
    int amount{};
    cout << "amount: " << endl;
    cin >> amount;
    int temp;
    for (int i = 0; i < amount; i++){
        cin >> temp;
        nums.push_back(temp);
    }   
    Found(nums);
    return 0;
}