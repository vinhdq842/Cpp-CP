#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
//#define SOL 3

ll n, v, a[1000006], ans = 0, res;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

#ifndef SOL
	cin >> n >> v;

	a[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll tmp, l = 1, r = i, mid;
		cin >> tmp;
		a[i] = a[i - 1] + tmp;

		while (l <= r) {
			mid = (l + r) >> 1;
			if (v <= a[i] - a[mid - 1])l = mid + 1;
			else r = mid - 1;
		}
		ans += r;
	}

	cout << ans;
#else
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		int l = i, r = n, idx = n + 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (a[m] - a[i - 1] >= v) {
				idx = m;
				r = m - 1;
			} else l = m + 1;
		}
		res += n - idx + 1;
	}
	cout << res;
#endif
	return 0;
}