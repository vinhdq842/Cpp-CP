//
// Created by admin on 18/10/2020.
//

#include<iostream>
#include <memory.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, p[200005], rs[200005];
    cin >> t;

    int one_pos = 0;
    for (int i = 0; i < t; ++i) {
        cin >> n;

        memset(rs, 0, sizeof(rs));

        for (int j = 0; j < n; ++j) {
            cin >> p[j];
            if (p[j] == 1)one_pos = j;
        }

        int l[n], r[n], top;
        int deque[n + 1];

        top = 0;
        deque[top] = -1;
        for (int j = 0; j < n; ++j) {
            while (top > 0 && p[deque[top]] < p[j])--top;
            l[j] = deque[top] + 1;
            deque[++top] = j;
        }

        deque[0] = n;
        top = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (top > 0 && p[deque[top]] < p[j])--top;
            r[j] = deque[top] - 1;
            deque[++top] = j;
        }

        for (int j = 0; j < n; ++j) {
            rs[p[j]] = (r[j] - l[j] + 1) == p[j] ? 1 : 0;
        }

        for (int j = 1; j <= n; ++j)cout << rs[j];
        cout << "\n";
    }
    return 0;
}