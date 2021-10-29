#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

struct Node
{
	int open;
	int close;

	Node(int open, int close): open(open), close(close)  {

	}

	Node(): open(0), close(0) {

	}
};

Node seg_tree[200010];
ll n, m, p, r;

string s;

Node operator+(const Node &left, const Node &right) {
	int valid = min(left.open, right.close);
	return Node(left.open + right.open - valid, left.close + right.close - valid);
}

void build_tree() {
	for (int i = 0; i < s.length(); ++i) {
		seg_tree[n + i] = s[i] == ')' ? Node(0, 1) : Node(1, 0);
	}

	for (int i = n - 1; i > 0; --i) {
		seg_tree[i] = seg_tree[i << 1] + seg_tree[i << 1 | 1];
	}
}


bool query(int p, int r) {
	Node rans = Node(), lans = Node();

	for (p += n, r += n; p < r; p >>= 1, r >>= 1) {
		if (p & 1)lans = lans + seg_tree[p++];
		if (r & 1)rans = seg_tree[--r] + rans;
	}

	Node anss = lans + rans;
	
	return anss.open + anss.close == 0;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	cin >> n >> m;
	cin >> s;
	build_tree();

	while (m--) {
		cin >> p >> r;
		cout << (query(p - 1, r ) ? "YES" : "NO") << "\n";
	}

	return 0;
}