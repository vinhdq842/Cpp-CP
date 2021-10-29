//
// Created by admin on 01/10/2020.
//

#include<iostream>
#include <memory.h>

#define ll long long
using namespace std;


int main() {

    ll n, m, p, t, b;
    cin >> n >> m >> p >> t >> b;
    ll f[n + 1];

    memset(f, 0, n + 1);

    for (ll i = 1; i <= m; ++i) {
        ll home;
        cin >> home;
        f[home] = 3;
    }

    for (ll i = 1; i <= p; ++i) {
        ll bus;
        cin >> bus;
        f[bus] = 2;
    }


    return 0;
}