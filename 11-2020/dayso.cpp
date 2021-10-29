#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
//#define BRUTE_FORCES 1
ll n, k;



struct bigint
{
	const int len = 100005;
	int n[100005];
	int cur_idx = len - 1;

	bigint() {
		memset(n, 0, sizeof(n));
	}

	bigint(string s) {
		memset(n, 0, sizeof(n));
		for (int i = s.length() - 1; i >= 0 ; --i)
		{
			n[len - s.length() + i] = s[i] - '0';
			cur_idx--;
		}
		cur_idx++;
	}

};


bigint operator+(bigint a, bigint b) {
	int	remainder = 0;
	bigint rs;

	for (int i = a.len - 1; i >= a.cur_idx || i >= b.cur_idx; --i) {
		rs.n[i] = (a.n[i] + b.n[i] + remainder) % 10;
		remainder = (a.n[i] + b.n[i] + remainder) / 10;
		rs.cur_idx--;
	}
	rs.n[rs.cur_idx] = remainder;
	if (rs.n[rs.cur_idx] == 0)rs.cur_idx++;
	return rs;
}


ostream& operator<<(ostream& out, bigint a) {
	for (int i = a.cur_idx; i <= a.len - 1; ++i)
	{
		out << a.n[i];
	}

	return out;
}


struct Data
{
	string s;
	ll len;
	__int128 whole_len;
};

Data dat[100007];

int solve(ll i, ll k) {
	if (k > dat[i].whole_len)return -1;
	if (k <= dat[i].len)return dat[i].s[k - 1] - '0';
	k = k - dat[i].len > dat[i - 1].whole_len ? k - dat[i].len - dat[i - 1].whole_len : k - dat[i].len;
	return solve(i - 1, k);
}


void check(int i) {

	string path = i < 10 ? "0" + to_string(i) : to_string(i);
#ifndef ONLINE_JUDGE
	path = "../seq/Test" + path;
	//freopen(strcat(path.c_str(),"/seq.inp"), "r", stdin);
	ifstream cin(path + "/seq.inp");
	freopen("output.out", "a+", stdout);
	ifstream rs( path + "/seq.out");
#endif

	fast_io
	cin >> n >> k;

	dat[0].s = "1";
	dat[0].len = 1;
	dat[0].whole_len = 1;


	for (ll i = 1; i < n; ++i)
	{
		dat[i].s = to_string(1 + i);
		dat[i].len = dat[i].s.length();
		dat[i].whole_len = dat[i].len + dat[i - 1].whole_len * 2;
	}

	ll ans;
	rs >> ans;
	//cout << solve(n - 1, k) << " " << ans << " " << dat[n - 1].whole_len << " " << k << endl;
}

int main() {
// 19
	/*
		for (int i = 1; i <= 50; ++i)
		{
			check(i);
		}

	*/

#ifndef ONLINE_JUDGE

	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	bigint a = bigint("7555000");
	bigint b = bigint("7845555");
	cout <<  a + b;
	return 0;
}