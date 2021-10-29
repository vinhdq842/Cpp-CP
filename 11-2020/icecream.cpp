#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll t, m, n, c[10004];
map<ll, ll> mp;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	cin >> t;
	while (t--) {
		cin >> m >> n;
		mp.clear();
		for (int i = 1; i <= n; ++i)
		{
			cin >> c[i];
		}

		for (int i = 1; i <= n; ++i)
		{
			map<ll, ll>::iterator it;
			if ((it = mp.find(c[i])) != mp.end()) {
				cout << (*it).second << " " << i << "\n" ;
				break;
			}
			mp.insert({m - c[i], i});
		}
	}
	return 0;
}