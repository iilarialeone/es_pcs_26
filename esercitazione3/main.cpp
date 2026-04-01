#include <iostream>
#include "rational.hpp"

#define N 5

using namespace std;
int main() {
    Rational<int> v[N] = {
        Rational<int>(1, 0),
        Rational<int>(0, 0),
        Rational<int>(-1, 0),
        Rational<int>(1, 2),
        Rational<int>(-1, 2),
    };
    
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //cout << v[i] << " + " << v[j] << " = " << v[i] + v[j] << endl;
            // cout << v[i] << " - " << v[j] << " = " << v[i] - v[j] << endl;
            cout << v[i] << " * " << v[j] << " = " << v[i] * v[j] << endl;
            // cout << v[i] << " / " << v[j] << " = " << v[i] / v[j] << endl;
        }
    }    


    return 0;
}