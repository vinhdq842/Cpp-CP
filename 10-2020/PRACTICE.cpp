//
// Created by admin on 20/10/2020.
//

#include<iostream>
#include<vector>
#include <algorithm>

#define pii pair<int,int>

using namespace std;

int n, rs, c;

vector<pii > p;


bool cmp(pii &a, pii &b) {
    if (a.first != b.first)return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> c;

    rs = 0;

    for (int i = 0; i < n; ++i) {
        int f, s;
        cin >> f >> s;
        p.emplace_back(f, s);
    }

      sort(p.begin(), p.end(), cmp);


    for (int i = 0; i < n; ++i) {
        // cout << p[i].first << " " << p[i].second << "\n";
        if (c >= p[i].first) {
            rs++;
            c += p[i].second;
        }
    }

    cout << rs;
    return 0;
}