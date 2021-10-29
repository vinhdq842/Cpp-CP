#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int n;;
string a, b;
int f[1001][1001];

int solve() {
	memset(f, 0, sizeof(f));
	int l1 = a.length();
	int l2 = b.length();
	int ans = 0;
	for (int i = 1; i <= l1; ++i) {
		for (int j = 1; j <= l2; ++j) {
			if (a[i - 1] == b[j - 1])f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = 0;
			ans = max(ans, f[i][j]);
		}
	}

	return ans;
}


int main() {


	fast_io

	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, a);
		getline(cin, b);
		cout << solve() << "\n";
	}
	return 0;
}