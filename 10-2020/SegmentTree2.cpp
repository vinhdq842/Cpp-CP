//
// Created by admin on 22/10/2020.
//

#include <iostream>

using namespace std;
const int N = 50000;
int tree[N * 2];
int n;

void build_tree() {
    for (int i = n - 1; i > 0; --i)tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

int get(int l, int r) {
    int ans = 0;
    for (l = l + n, r = r + n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)ans += tree[l++];
        if (r & 1)ans += tree[--r];
    }
    return ans;
}

void inc(int pos, int val) {
    for (tree[pos += n] += val; pos > 1; pos >>= 1)tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> tree[n + i];
    }

    build_tree();

    int l, r;
    cin >> l >> r;
    cout << get(l, r) << endl;
    inc(5, 5);
    cout << get(l, r) << endl;
    return 0;
}