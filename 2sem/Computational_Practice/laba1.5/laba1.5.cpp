#include "laba1.5.h"
using namespace std;

float ResultFunc(float x, float t, float s){
    return (1+pow(x,t)+pow(x,2))/
    (pow((pow(x,3)+1),(1/2)))*(1-sin(s*x));         
}

float Integral(float ResultFunc(float, float, float), float t, float s, float a, float b, int n){
    float H = (b - a)/n;
    float res = 0;
    for(float i = a; i <b; i+=H)
    res += H * ResultFunc(i+H/2, t, s);
    return res;
}

void ResultIntegral(float s1, float s2, float eps_s, float t1, float t2, float eps_t, int a, int b, float eps){
    cout << "--------------+--------------+--------------+--------------+" << endl;
    cout <<  setw(15) << "s        |" << setw(15) << "t        |" << setw(15) << "Integral     |" << setw(15) << "k_iter    |" << endl;
    cout << "--------------+--------------+--------------+--------------+" << endl;
    for (float i = s1; i<=s2;i+=eps_s) {
        for(float j = t1; j<=t2; j+=eps_t){
            int k_iter{};
            int n = 1;
            float prev = Integral(ResultFunc,j,i,a,b,n++);
            float current = Integral(ResultFunc,j,i,a,b,n);
            while(abs(prev - current) > eps){
                prev = current;
                n++;
                k_iter++;
                current = Integral(ResultFunc,j,i,a,b,n);
            }
            
            cout << setw(14) <<  i << "|" << setw(14) << j << "|" << setw(14)  << current  << "|" << setw(14) << k_iter << "|" <<  endl;
            cout << "--------------+--------------+--------------+--------------+" << endl;
        }
    }

} 