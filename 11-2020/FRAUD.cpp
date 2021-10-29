#include<bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long


int n, d, e[200005], ans = 0;

priority_queue<int> pq;
queue<int> q;


double getmed() {
	int i = 1;
	int tmp;

	priority_queue<int> pq;
	for (int i = 0; i < d; ++i) {
		pq.push(q.front());
//		cout << q.front() << " ";
		q.pop();
	}
//	cout << endl;
	while (i <= d / 2) {
		tmp = pq.top(); pq.pop();
		++i;
	}
	//cout<<pq.top()<<endl;
	if (d & 1)return pq.top();
	return (tmp + pq.top()) / 2.0;
}

int main() {


#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	fast_io
	cin >> n >> d;

	for (int i = 0; i < n; ++i) {
		cin >> e[i];
	}

	for (int i = d; i < n; ++i) {

		for (int j = 1; j <= d; ++j) {
			q.push(e[i - j]);
		}
//		cout << getmed() << " ";
		if (2 * getmed() <= e[i])++ans;
	}

	cout << ans;

	return 0;
}