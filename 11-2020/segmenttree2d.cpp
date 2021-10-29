#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define inf 1e18
struct node
{
	ll miN, maX;
} a[1003][1003];

ll arr[1003][1003];

ll n, q, x, y, u, v, w;
char opr;
pair<ll, ll> rs;

void update_x(int id, int l, int r, int u, int v, int val) {
	if (v < l || r <= u)return;

	if (u <= l && r <= v) {
		update_y(1,)
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	fast_io

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
			update(i, j, q);
		}
	}

	cin >> q;

	while (q--) {
		cin >> opr;
		if (opr == 'q') {
			cin >> x >> y >> u >> v;
			rs = get()
		} else {
			cin >> x >> y >> w;
			pair<ll> rs
		}
	}
	return 0;
}