//
// Created by admin on 28/04/2020.
//

#include <iostream>

#define ll long long
#define MAX 1000001
using namespace std;

struct Node {
    int optimal;
    int open;
    int close;

    Node(int optimal, int open, int close) {
        this->optimal = optimal;
        this->open = open;
        this->close = close;
    }

    Node() {
        Node(0, 0, 0);
    }
};

Node tree[4 * MAX];
string inp;

void init_tree(int, int, int, int, char);

Node answer(int, int, int, int, int);

void build(int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, inp);
    for (int i = 1; i <= inp.length(); ++i)init_tree(1, 1, inp.length(), i, inp[i - 1]);
    //build(1, 0, inp.length() - 1);
    int n;
    cin >> n;
    int l[n], r[n];
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    for (int i = 0; i < n; ++i) {
        Node tmp = answer(1, 1, inp.length(), l[i], r[i]);
        cout << tmp.optimal * 2 << "\n";
    }
    return 0;
}

Node operator+(const Node &left, const Node &right) {
    int tmp = min(left.open, right.close);
    int optimal = left.optimal + right.optimal + tmp;
    int open = left.open + right.open - tmp;
    int close = left.close + right.close - tmp;

    return Node(optimal, open, close);
}

void init_tree(int id, int l, int r, int i, char v) {
    if (i < l || i > r)return;
    if (l == r) {
        if (v == '(')tree[id] = Node(0, 1, 0);
        else tree[id] = Node(0, 0, 1);
        return;
    }
    int mid = (l + r) / 2;
    init_tree(id * 2, l, mid, i, v);
    init_tree(id * 2 + 1, mid + 1, r, i, v);
    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void build(int id, int l, int r) {
    if (l == r) {
        if (inp[l] == '(')tree[id] = Node(0, 1, 0);
        else tree[id] = Node(0, 0, 1);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

Node answer(int id, int l, int r, int u, int v) {
    if (v < l || u > r)return Node(0, 0, 0);
    if (u <= l && r <= v)return tree[id];
    int mid = (l + r) / 2;
    return answer(id * 2, l, mid, u, v) + answer(id * 2 + 1, mid + 1, r, u, v);
}