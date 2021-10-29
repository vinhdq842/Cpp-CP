#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, q, u, v, a[100005];
vector<ll> f(100005);
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n >> q;
	f[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	while (q--) {
		cin >> u >> v;
		if (u == v) {
			cout << a[u] << "\n";
			continue;
		}
		vector<ll>::iterator i;
		i = lower_bound(f.begin() + u, f.begin() + v + 1, f[u - 1] + (f[v] - f[u - 1]) / 2);
		cout << min(abs(f[v] - f[(i - f.begin() - 1)] - f[(i - f.begin() - 1)] + f[u - 1]), abs(f[v] - f[(i - f.begin())] - f[(i - f.begin())] + f[u - 1])) << "\n";
	}
}