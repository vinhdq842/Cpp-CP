#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll y, rs = 0, t;

ll reversed(ll num) {
	ll ans = 0;
	while (num > 0) {
		ans = ans * 10 + num % 10;
		num /= 10;
	}

	return ans;
}

int main() {

	fast_io
	int g = 1;
	printf("%d %d %d\n",g,++g,g++);
	return 0;
}