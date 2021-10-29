//
// Created by admin on 01/11/2020.
//

#include<bits/stdc++.h>

using namespace std;
long long a[36];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    a[0] = 2;

    for (int i = 1; i <= 35; i++) {
        a[i] = a[i - 1];
        for (int m = 1; m <= i; ++m)
            a[i] += m % 2 == 0 ? static_cast<long long>( 9 * powl(10, (m - 2) / 2)) : static_cast<long long>( 90 * powl(10,(m - 3) / 2));
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << a[n] << "\n";
    }
    return 0;
}