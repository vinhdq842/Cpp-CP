//
// Created by admin on 20/10/2020.
//

#include<iostream>
#include <algorithm>

using namespace std;

int n, k, a[200005];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)cin >> a[i];
    sort(a, a + n);

    int index = n / 2;
    int rs = a[index];
    a[n] = a[n - 1] + k;

    for (int i = index + 1; i <= n; ++i) {
        while (rs < a[i] && k - (i - index) >= 0) {
            rs++;
            k -= i - index;
        }
    }
    cout << rs;
    return 0;
}