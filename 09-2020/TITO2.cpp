//
// Created by admin on 24/09/2020.
//

#include<iostream>

using namespace std;
#define ll long long
const ll MOD = 1000000007;

ll calc(ll x) {
    return (x * (x + 1) / 2 % MOD) * (2 * x + 1) / 3 % MOD;
}

int main() {
    double x, y;
    cin >> x >> y;
    ll a;
    if (int(x) == x) a = int(x);
    else a = int(x) + 1;
    ll b = int(y);
    cout << (calc(b) - calc(a - 1) + MOD) % MOD;
}