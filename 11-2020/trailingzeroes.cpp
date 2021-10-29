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
	int n, ans = 0;
	cin >> n;

	while (n > 0) {
		ans += n / 5;
		n /= 5;
	}
	cout << ans;
	return 0;
}