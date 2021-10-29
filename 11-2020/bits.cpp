#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	int a, b, c, ans = 0;
	cin >> a >> b;
	c = a ^ b;

	while (c > 0) {
		ans += c & 1;
		c >>= 1;
	}

	cout << ans;
	return 0;
}