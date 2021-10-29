#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

bool solve(string a, string b) {
	if (b == "")return true;

	if (a.length() < b.length())return false;
	if (a.length() == b.length() && a != b)return false;
	if (a[a.length() - 1] == b[b.length() - 1])return solve(a.substr(0, a.length() - 1), b.substr(0, b.length() - 1)) || solve(a.substr(0, b.length() - 1), b);

	return solve(a.substr(0, a.length() - 1), b);
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	fast_io
	string s;
	getline(cin, s);
	//transform(s.begin(), s.end(), s.begin(), ::tolower);
	//cout<<s<<endl;
	cout << (solve(s, "hello") ? "YES" : "NO");
	return 0;
}