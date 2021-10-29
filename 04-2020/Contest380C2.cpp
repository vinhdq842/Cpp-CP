//
// Created by admin on 23/10/2020.
//

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int optimal = 0;
    int open = 0;
    int close = 0;

    Node() {
        Node(0, 0, 0);
    }

    Node(int opt, int op, int cl) {
        this->optimal = opt;
        this->open = op;
        this->close = cl;
    }
};

Node tree[2000005];
string s;
int n;

Node operator+(const Node &a, const Node &b) {
    int tmp = min(a.open, b.close);
    int open = a.open + b.open - tmp;
    int close = a.close + b.close - tmp;

    return {tmp + a.optimal + b.optimal, open, close};
}

void build_tree() {
    for (int i = 0; i < s.length(); ++i)tree[i + s.length()] = (s[i] == '(' ? Node(0, 1, 0) : Node(0, 0, 1));
    for (int i = s.length() - 1; i > 0; --i)tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

Node query(int l, int r) {
    Node ansr = Node();
    Node ansl = Node();
    for (l += s.length(), r += s.length(); l < r; l >>= 1, r >>= 1) {
        if (l & 1)ansl = ansl + tree[l++];
        if (r & 1)ansr = tree[--r] + ansr;
    }

    return ansl + ansr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, s);
    build_tree();
    cin >> n;
    int l, r;
    while (n--) {
        cin >> l >> r;
        cout << query(l - 1, r).optimal * 2 << "\n";
    }
    return 0;
}