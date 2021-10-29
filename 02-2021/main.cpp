#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define inf 1000000000

int n, m, w[105], v[105];
map<pair<int,int>,int> trace;

int solve(int i, int j) {
	if (j == 0 || i == 0)return 0;

	if (j >= w[i]) {
		if (trace[{i,j}] == 0) {
			int a = solve(i - 1, j);
			int b = solve(i - 1, j - w[i]) + v[i];
			trace[{i,j}] = max(a, b);
		}
		return trace[{i,j}];
	}
	else {

		if (trace[{i,j}] == 0) {
			trace[{i,j}] = solve(i - 1, j);
		}
		return trace[{i,j}];
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

	while (trace[{n,m}] > 0) {

		if (trace[{n,m}] == trace[{n - 1,m - w[n]}] + v[n]) {
			cout << n << " ";
			m -= w[n];
		}
		--n;
	}

	char *s = 'aa';
	char *t = 'ba';
	cout<<strcmp(s,t)<<endl;
}