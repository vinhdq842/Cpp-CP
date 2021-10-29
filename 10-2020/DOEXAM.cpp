//
// Created by admin on 11/10/2020.
//

#include<bits/stdc++.h>

using namespace std;
int a[26];

int find_ans(int n, int k) {
    if (n <= 0 || k <= 0)return 0;
    int ans = find_ans(n - 1, k - 1) + a[n];
    if (n >= 2)ans = max(ans, find_ans(n - 2, k - 1) + a[n - 1]);

    return ans;
}

int main() {
    int n, k;
    int f[26][26];

    for (int i = 0; i < 26; ++i) {
        f[0][i] = 0;
        f[i][0] = 0;
    }


    cin >> n >> k;
    for (int i = n; i > 0; --i)cin >> a[i];
    //cout << find_ans(n, k);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            f[i][j] = f[i - 1][j - 1] + a[i];
            if (i >= 2)f[i][j] = max(f[i][j], f[i - 2][j - 1] + a[i - 1]);
        }
    cout << f[n][k];
    /**
     * f[i][j] = f[i-1][k-1]+a[i]; f[i-2][k-1] + a[i-1]
     */

    return 0;
}