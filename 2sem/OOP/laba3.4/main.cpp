/*
TASK CONDITION
-------------------------------------------------------------------------------
Написать программу, которая по заданному алгебраическому выражению
(операнды – целые и вещественные числа; операции: – + * / и скобки ( )) вычисляет результат. 
WARNING: Если число отрицательное, то его надо взять в фигурные скобки, а не в обычные
 -------------------------------------------------------------------------------
ENGLISH
Write a program that, according to a given algebraic expression
(operands are integers and real numbers; operations: – + * / and parentheses ( ))
, calculates the result. 
WARNING: If the number is negative, then it should be taken in curly brackets, and not in the usual ones
-------------------------------------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//является ли символ оператором
bool isOperator(char c){
    return c == '+' || c == '*' || c == '/' || c == '-';
}

//определяем приоритет операторов
int getPrioritet(char c){
    if (c == '*' || c == '/'){
        return 2;
    }
    if (c == '+' || c == '-'){
        return 1;
    }
    return 0;
}

//считаем два числа каких-то числа
double calculateNum(double num1, double num2, char op){
    double res;
    switch(op){
        case '-': res = num1 - num2; break;
        case '+': res = num1 + num2; break;
        case '*': res = num1 * num2; break;
        case '/': res = num1 / num2; break;
        default: cout << "Error" << endl; break;
    }
    return res;
}

//считаем результат
double calculateRes(string input_line){
    stack<double> nums;
    stack<char> operators;
    
    //строка для временного хранения числа
    string temp_num = "";

    for (int i = 0; i < input_line.size(); i++){
        
        if (input_line[i] == ' '){
            continue;
        }
        
        else if(input_line[i] == '('){
            operators.push(input_line[i]);
        }
        
        //если символ ), то вычисляем значение внутри скобок и помещаем в стек
        else if(input_line[i] == ')'){
            while( !operators.empty() && operators.top() != '('){
                double num2 = nums.top();
                nums.pop();
                double num1 = nums.top();
                nums.pop();
                char op = operators.top();
                operators.pop();
                nums.push(calculateNum(num1, num2, op));
            }
            
            if (!operators.empty()){
                operators.pop();
            }
        }

        //если этот символ цифра, то считываем все цифры идущие за ней подряд
        //затем конвертируем их в число типа double, которое заносим в стек чисел 
        else if(isdigit(input_line[i])){
            double val;
            while(i < input_line.size() && (isdigit(input_line[i]) || input_line[i] == '.')){
                temp_num += input_line[i];
                i++;
            }
            
            //декрементируем, так как без этого цикл может скипнуть один символ
            i--;
            
            val = stod(temp_num);
            nums.push(val);
            temp_num = "";
        }

        //фигурными скобками обозначаю отрицательные числа в строке
        //принцип алгоритма такой же, как и с цифрой
        else if(input_line[i] == '{'){
            i++;
            double val;
            while(input_line[i] != '}'){
                temp_num += input_line[i];
                i++;
            }
            val = stod(temp_num);
            nums.push(val);
            temp_num = "";
        }
        
        else if(isOperator(input_line[i])){
            while(!operators.empty() && getPrioritet(operators.top()) > getPrioritet(input_line[i])){
                double num2 = nums.top();
                nums.pop();
                double num1 = nums.top();
                nums.pop();
                double op = operators.top();
                operators.pop();
                nums.push(calculateNum(num1, num2, op));
            }
            
            //добавляем текущий оператор  в стек
            operators.push(input_line[i]);
        } 
        
        else {
            cout << "Error symbol: " << input_line[i] << endl;
        }
           
    }

    //проверяем, есть ли ещё что-то в стеке
    while(!operators.empty()){
        double num2 = nums.top();
        nums.pop();
        double num1 = nums.top();
        nums.pop();
        char op = operators.top();
        operators.pop();
        nums.push(calculateNum(num1, num2, op));
    }
    return nums.top();
}

int main() {
    string s1 = "{-5.2} + 2 * 3 - 4 / 2";
    double res = calculateRes(s1);
    cout << s1 << " = " << res;
    return 0;
}