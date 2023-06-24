#include "laba1.4.h"
using namespace std;

float Func1(float x){
    return pow((x-1), 3)-8;
}

float DerivativeFirst(float x) {
    return 3*pow((x-1),2);
}

float DerivativeSecond(float x){
    return 6*(x-1);
}


float Func2(float x, float s){
    return s*pow(cos(PI*x), 2) - pow(x, 1/2);
}

float DerivativeFirst2(float x, float s){
    return  s*2*cos(PI*x)*(-sin(PI*x))-1/(2*pow(x,1/2));   
}

float DerivativeSecond2(float x, float s){
    return -2*s*(-sin(PI*x))*cos(PI*x)-1/(4*pow(x,3/2));
}

//(х-1)^3-8 
void TangentMethod1(float a, float b, float eps, float Func1(float)){
    cout << "--------------+--------------+--------------+--------------+" << endl;
    cout <<  setw(15) << "S        |" << setw(15) << "X        |" << setw(15) << "F(X)     |" << setw(15) << "n_iter    |" << endl;
    cout << "--------------+--------------+--------------+--------------+" << endl;
    int n_iter{};
    float x_near{};
    if(Func1(a)*DerivativeSecond(a)>0){
        x_near = a;
    }
    if(Func1(b)*DerivativeSecond(b)>0){
        x_near = b;
    }
    
    while(abs(Func1(x_near)/DerivativeFirst(x_near)) > eps){
    
        n_iter++;
        x_near = x_near - Func1(x_near)/DerivativeFirst(x_near);
    }
    
    cout << setw(14) <<  "0" << "|" << setw(14) << x_near << "|" << setw(14)  << Func1(x_near)  << "|" << setw(14) << n_iter << "|" <<  endl;
    cout << "--------------+--------------+--------------+--------------+" << endl;
}

//s*cos^2(pix) − x              
void TangentMethod2(float a, float b, float eps, float s_start, float s_end, float s_eps, float Func2(float, float)){
    cout << "--------------+--------------+--------------+--------------+" << endl;
    cout <<  setw(15) << "S        |" << setw(15) << "X        |" << setw(15) << "F(X)     |" << setw(15) << "n_iter    |" << endl;
    cout << "--------------+--------------+--------------+--------------+" << endl;

    for(float i = s_start; i <= s_end; i+=s_eps){
        int n_iter{};
        float x_near{};
        if(Func2(a,i)*DerivativeSecond2(a,i)>0){
            x_near = a;
        }
        if(Func2(b,i)*DerivativeSecond2(b,i)>0){
            x_near = b;
        }
        float comparison1 = Func2(a,i)*DerivativeSecond2(a,i);
        float comparison2 = Func2(b,i)*DerivativeSecond2(b,i);
        if(comparison1 && comparison2 < 0){
            continue;
        }
    
        while(abs(Func2(x_near,i)/DerivativeFirst2(x_near,i)) > eps){
            n_iter++;
            x_near = x_near - Func2(x_near,i)/DerivativeFirst2(x_near,i);
        }
        
        cout << setw(14) <<  i << "|" << setw(14) << x_near << "|" << setw(14)  << Func2(x_near,i)  << "|" << setw(14) << n_iter << "|" <<  endl;
        cout << "--------------+--------------+--------------+--------------+" << endl;
       
    }
}

