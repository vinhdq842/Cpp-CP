#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int n, q, x, y, u, v;
ll bit[1001][1001];

void update(int x, int y, int w) {
	for (int i = x; i <= n; i += i & (-i)) {
		for (int j = y; j <= n; j += j & (-j)) {
			bit[i][j] += w;
		}
	}
}

ll get(int x, int y) {
	ll rs = 0;

	for (int i = x; i > 0; i -= i & (-i)) {
		for (int j = y; j > 0; j -= j & (-j)) {
			rs += bit[i][j];
		}
	}

	return rs;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	memset(bit, 0, sizeof(bit));

	cin >> n;
	ll tmp;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> tmp;
			update(i, j, tmp);
		}
	}

	cin >> q;

	while (q--) {
		cin >> tmp;

		if (tmp == 1) {
			cin >> x >> y >> u;
			update(x, y, u);
		} else {
			cin >> x >> y >> u >> v;
			cout << (get(u, v) - get(x - 1, v) - get(u, y - 1) + get(x - 1, y - 1)) << "\n";
		}
	}

	return 0;
}