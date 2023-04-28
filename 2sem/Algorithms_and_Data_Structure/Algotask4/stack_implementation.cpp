#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void Sort(vector<int>&nums){
    stack<int>st;
    int len = nums.size();
    for (int i = 0; i < len-1; i++){
        if (nums[i] < nums[i+1]){
            nums[i] = nums[i+1];
            while(!st.empty() and nums[st.top()] < nums[i+1]){
                nums[st.top()] = nums[i+1];  
                st.pop();
            }
        }
        
        else {
            st.push(i);
        }
    }
    nums[len-1] = 0;
    while(!st.empty()){
        nums[st.top()] = 0;
        st.pop();
    }
}

int main(){
    vector<int>nums;
    int amount;
    cout << "amount: ";
    cin >> amount;
    int temp{};
    for (int i = 0; i < amount; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    Sort(nums);
    for (int i = 0; i < amount; i++){
        cout << nums[i] << " ";
    }
    return 0;
}