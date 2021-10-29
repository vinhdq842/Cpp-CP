//
// Created by admin on 25/09/2020.
//
#include <iostream>

#define fast_io ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;


int main() {
    fast_io
    int m, n, x, y;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)cin >> arr[i];

    for (x = 0, y = 1; x <= y; x++) {
        while (arr[y] - arr[x] < m && y < n)y++;
        if (arr[y] - arr[x] == m) {
            cout << arr[x] << " " << arr[y];
            return 0;
        }
    }
    cout << -1;
    return 0;
}

