//
// Created by admin on 20/10/2019.
//

#include <iostream>

using namespace std;

long long pow(long long, long long);

int main() {
    long long x, n;
    cin >> x >> n;
    cout << pow(x, n);
    return 0;
}

long long pow(long long x, long long n) {
    if (x == 1)return x;
    if (n == 1)return x;
    if (n == 2)return x * x;
    int a = pow(x, n / 2);
    if (n % 2 == 0) {
        return a * a % 10000;
    } else {
        return a * a * x % 10000;
    }
}