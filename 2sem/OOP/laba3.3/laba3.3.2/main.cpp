#include <iostream>
#include <list>
using namespace std;

int main(){
    cout << "Enter number: " << endl;
    int N;
    cin >> N;
    int left = N - 1;
    int right = N;
    int num = 1;
    int res = 1;
    list<int> numbers;
    for (int i = 0; i < 2*N; i++){
        numbers.push_back(num++);
    }
    cout << "numbers: ";
    for (auto i = numbers.begin(); i != numbers.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    while(left >= 0 && right < 2*N){
        res *= (numbers.front() - numbers.back());
        numbers.pop_front();
        numbers.pop_back();
        left--;
        right++; 
    }
    cout << "res = " << res;
    return 0;
}
