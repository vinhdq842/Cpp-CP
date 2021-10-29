#include<iostream>

using namespace std;

//#define ONLINE_JUDGE 3 101358108033
//#define S 3
long long n, ans = -1000000000, a[100005], f[100005];
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifdef S
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	f[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = f[i - 1] + a[i];
	}


	for (int i = 3; i <= n; ++i) {
		for (int j = i - 3; j >= 0; j -= 3)ans = max(ans, f[i] - f[j]);
	}

	cout << ans;
#else
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 3; i <= n; i++) {
		f[i] = a[i] + a[i - 1] + a[i - 2];
		f[i - 3] > 0 ? f[i] += f[i - 3] : f[i] += 0;
		ans = max(ans, f[i]);
	}

	cout << ans;
#endif
	return 0;
}