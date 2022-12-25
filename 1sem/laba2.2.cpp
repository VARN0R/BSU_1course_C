
/*
TASK CONDITION IN THE MANUAL
*/



/*
!!!WARNING!!!
This code was written in a Linux UBUNTU text editor, 
therefore some libraries may be incompatible with Windows.  

If you have any errors, try to find analogues of the libraries used.
*/
#include<iostream>
#include<cmath>
using namespace std;

pair<double, int> taylor(double x) {
    double out{}, prev{};
    int sign{ 1 };
    int i = 1;
    double x_value = 1;
    const double epsilon = 1e-8;
  
    do {
        prev = out;
        sign = -sign;
        x_value *= x * x;
        out += sign * x_value;
        i++;
    } while (abs(out - prev) > epsilon);

    return { out ,i };
}

int main() {

    float x0{ -0.1 }, xn{ 0.9 }, dx{ 0.2 }, x = x0;
    int i{ 1 };

    for (x = x0; x <= xn;x+=dx) {
        auto [y, n] = taylor(x);

        cout << "x" << x << endl;
        cout << "my func: " << y << "(" << n << ")" << "\n";
        cout << "cpp func: " << 1 / (1 + x * x) - 1 << "\n";
        cout << endl;
    }


    return 0;
}