#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define inf 1000000000

int n, m, w[105], v[105], cur_state[105], opt_state[105];

int opt = 0, tmp_w = 0, tmp_v = 0;


void gen(int i) {
	if (i == n + 1) {
		if (tmp_w <= m && tmp_v > opt) {
			for (int k = 1; k <= n; ++k)opt_state[k] = cur_state[k];
			opt = tmp_v;
		}
	}
	else {
		tmp_w += w[i];
		tmp_v += v[i];
		cur_state[i] = 1;
		if (tmp_w <= m) gen(i + 1);
		tmp_w -= w[i];
		tmp_v -= v[i];
		cur_state[i] = 0;
		gen(i + 1);
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

	gen(1);

	cout << opt << endl;

	for (int i = n; i > 0; --i) {
		if (opt_state[i])cout << i << " ";
	}

	return 0;
}
