/**
 *
 * @authors SOE (quangvinh0842@gmail.com)
 * @date    2021-02-28 21:02:56
 * @version $Id$
 */
#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define pii pair<int,int>
#define MOD 1000007

void mul(ll a[2][2], ll b[2][2]) {
	ll x = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	ll y = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	ll z = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	ll t = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;

	a[0][0] = x, a[0][1] = y, a[1][0] = z, a[1][1] = t;
}

void pow(ll matrix[2][2], ll n) {
	if (n == 0 || n == 1)return;
	ll p[2][2] = {{1, 1}, {1, 0}};
	pow(matrix, n / 2);
	mul(matrix, matrix);
	if (n & 1)mul(matrix, p);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	ll f[2][2] = {{1, 1}, {1, 0}};
	ll n;
	cin >> n;
	if (n > 1)	pow(f, n - 1);
	cout << f[0][0];
	return 0;
}
