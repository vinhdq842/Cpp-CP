#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define inf 1000000000

int n, m, w[105], v[105];
int trace[105][105] = {0};

int solve(int i, int j) {
	if (j == 0 || i == 0)return 0;

	if (j >= w[i]) {
		int a = solve(i - 1, j);
		int b = solve(i - 1, j - w[i]) + v[i];
		trace[i][j] = max(a, b);
		return trace[i][j];
	}
	else {
		trace[i][j] = solve(i - 1, j);
		return trace[i][j];
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> w[i] >> v[i];

	cout << solve(n, m);

	cout << endl;

	while (trace[n][m] > 0) {

		if (trace[n][m] == trace[n - 1][m - w[n]] + v[n]) {
			cout << n << " ";
			m -= w[n];
		}
		--n;
	}
	
    return 0;
}