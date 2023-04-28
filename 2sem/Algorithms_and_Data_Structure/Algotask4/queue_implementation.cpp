#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Sort(vector<int>&nums){
    queue<int>q;
    bool stop = false;
    int len = nums.size();
    for (int i = 0; i < len; i++){
        q.push(nums[i]);
    }
    int counter{};
    int len_q = len;
    
    for (int i = 0; i < len; i++){
        while(stop == false){
            q.push(q.front());
            q.pop(); 
            counter++;                 
            if (q.front() > nums[i]){
                nums[i] = q.front();
                counter = 0;
                stop = true;
                break;
            }
            if (counter == len_q){
                nums[i] = 0;
                counter = 0;
                stop = true;
                break;
            }
        }
        stop = false;
        
        while(counter < len-1){
            counter++;
            q.push(q.front());       
            q.pop();
        }
        len_q--;
        counter = 0;
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