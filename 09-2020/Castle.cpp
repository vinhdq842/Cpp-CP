//
// Created by admin on 27/09/2020.
//
// prob("xep viec")

#include<bits/stdc++.h>

#define fast_io ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    fast_io
    int m, n;
    cin >> n >> m;
    int data[n + 1][m + 1], ans[n + 1][m + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)cin >> data[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)ans[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m - n + i; j++) {
            ans[i][j] = max(ans[i][j - 1], ans[i - 1][j - 1] + data[i][j]);
        }
    }

    cout << ans[n][m];
    return 0;
}