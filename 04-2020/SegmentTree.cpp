//
// Created by admin on 26/04/2020.
//

#include <iostream>

using namespace std;

#define  ll long long
#define MAX 100001

ll tree[4 * MAX];

void init_tree(int, int, int, int, int);

ll getMax(int, int, int, int, int);

int main() {
    int n;
    cin >> n;
    int tmp;

    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        init_tree(1, 1, n, i, tmp);
    }
    cout << endl;
    for (int i = 1; i <= n; ++i)
        cout << getMax(1, 1, n, i, i) << " ";
    return 0;
}

void init_tree(int id, int l, int r, int i, int v) {
    if (i < l || i > r)return;
    if (l == r) {
        tree[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    init_tree(id * 2, l, mid, i, v);
    init_tree(id * 2 + 1, mid + 1, r, i, v);
    tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}

ll getMax(int id, int l, int r, int u, int v) {
    if (v < l || u > r)return -MAX;
    if (u <= l && r <= v)return tree[id];
    int mid = (l + r) / 2;
    return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}