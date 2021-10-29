#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

struct Node {
    int open;
    int close;
    bool valid = false;

    Node(int open, int close, bool valid) : open(open), close(close), valid(valid) {

    }

    Node() : open(0), close(0), valid(false) {

    }
};

Node seg_tree[200010];
ll n, m, p, r;

string s;

Node operator+(Node &left, Node &right) {
    return left.open == right.close && left.close == 0 && right.open == 0 && left.valid && right.valid ? Node(0, 0,
                                                                                                              true)
                                                                                                       : Node(
                    left.open + right.open - min(left.open, right.close),
                    left.close + right.close - min(left.open, right.close), false);
}

void build_tree() {
    for (int i = 0; i < s.length(); ++i) {
        seg_tree[n + i] = s[i] == ')' ? Node(0, 1, false) : Node(1, 0, false);
    }

    for (int i = n - 1; i > 0; --i) {
        seg_tree[i] = seg_tree[i << 1] + seg_tree[i << 1 | 1];
    }
}


bool query(int p, int r) {
    Node rans = Node(0, 0, true), lans = Node(0, 0, true);

    for (p += n, r += n; p < r; p >> 1, r >> 1) {
        if (p & 1)lans = lans + seg_tree[++p];
        if (p & 1)rans = seg_tree[r--] + rans;
    }

    Node anss = lans + rans;
    return anss.valid;
}

int main() {

#ifdef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

//    fast_io

    cin >> n >> m;
    cin >> s;
    //cout<<s;
    build_tree();

    while (m--) {
        cin >> p >> r;

        cout << (query(p, r + 1) ? "YES" : "NO") << "\n";
    }
    cout<<"a";
    return 0;
}