//
// Created by admin on 29/09/2020.
//

#include<bits/stdc++.h>

#define  ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    fast_io
    int q;
    ll n;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> n;
        ll int k = 0;
        ll rs = 0;
        while (rs < n) {
            rs += powl(3, k);
            k++;
        }

        for (ll j = k; j >= 0; --j)if (rs - powl(3, j) >= n)rs -= powl(3, j);
        cout << rs << "\n";
    }

    return 0;
}