#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int m, n;
struct vw
{
	float v, w;
	int idx;
};

vw a[105];

set<int> res;

bool cmp(vw a, vw b) {
	return (a.v / a.w) > (b.v / b.w);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> a[i].w >> a[i].v;
		a[i].idx = i + 1;
	}


	int ans = 0;

	sort(a, a + n, cmp);

	for (int i = 0; i < n; ++i) {
		if (m >= a[i].w) {
			m -= a[i].w;
			ans += a[i].v;
			res.insert(a[i].idx);
		}
	}


	cout << ans << endl;

	for (set<int>::reverse_iterator it = res.rbegin(); it != res.rend(); ++it) {
		cout << *it << " ";
	}

	return 0;

}