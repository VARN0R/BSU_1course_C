#include <iostream>
#include <forward_list>
using namespace std;
int main() {
    forward_list<int> numbers1;
    forward_list<int> numbers2;
    forward_list<int> res;

    cout << "Enter size numbers1: " << std::endl;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        numbers1.push_front(i+1);
    }
    cout << "Enter size numbers2: " << std::endl;
    cin >> N;
    for (int i = 0; i < N; i++){
        numbers2.push_front(i+2);
    }
    
    // вывод списков на экран
    cout << "numbers1: ";
    for (auto it = numbers1.begin(); it != numbers1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "numbers2: ";
    for (auto it = numbers2.begin(); it != numbers2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // поиск общих элементов и добавление их в список res
    for (auto it1 = numbers1.begin(); it1 != numbers1.end(); ++it1){
        for (auto it2 = numbers2.begin(); it2 != numbers2.end(); ++it2){
            if (*it1 == *it2){
                bool found = false;
                for (auto it3 = res.begin(); it3 != res.end(); ++it3){
                    if (*it3 == *it1){
                        found = true;
                        break;
                    }
                }
                if (found == false){
                    res.push_front(*it1);
                    break;
                }
            }
        }
    }
    
    // вывод результата на экран
    cout << "res: ";
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
