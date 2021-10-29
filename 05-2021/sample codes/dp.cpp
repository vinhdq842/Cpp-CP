#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int n, m, w[105], v[105], f[105][105];

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> w[i] >> v[i];

	memset(f, 0, sizeof(f));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			f[i][j] = f[i - 1][j];
			if (j >= w[i])f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
		}
	}

	cout << f[n][m] << "\n";

	while (f[n][m] > 0) {
		
	 if (f[n][m] == f[n - 1][m - w[n]] + v[n]) {
			cout << n << " ";
			m -= w[n];
		}
		--n;
	}
    return 0;
}