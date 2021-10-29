#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll bit[1001][1001];
ll m, n;

void update(ll x, ll y, ll val) {

	for (ll i = x; i <= m; i += i & (-i)) {
		for (ll j = y; j <= n; j += j & (-j)) {
			bit[i][j] += val;
		}
	}
}


ll get(ll x, ll y) {
	ll rs = 0;
	for (ll i = x; i > 0; i -= i & (-i)) {
		for (ll j = y; j > 0; j -= j & (-j)) {
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
	cin >> m >> n;
	ll tmp;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> tmp;
			update(i, j, tmp);
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << (get(i, j) - get(i, j - 1) - get(i - 1, j) + get(i - 1, j - 1)) << " ";
		}

		cout << endl;
	}

	return 0;
}