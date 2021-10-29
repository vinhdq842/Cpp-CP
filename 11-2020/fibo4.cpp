#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

const ll  MOD  = 1000007;
ll n, a = 1, b = 1, tmp = 0, i = 3;
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	cin >> n;
	if (n < 3) {
		cout << a;
		return 0;
	}

	while (i <= n) {
		tmp = b;
		b = (a + b) % MOD;
		a = tmp;
		++i;
	}

	cout << b;
	return 0;
}