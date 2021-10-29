//
// Created by admin on 24/09/2020.
//

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> dat;

void quick_sort(int l, int r) {
    int s = l, e = r;
    pair<ll, ll> pivot = dat[l + rand() % (r - l)];

    while (s <= e) {
        while (dat[s].first < pivot.first)++s;
        while (dat[e].first > pivot.first)--e;
        if (s <= e) {
            pair<ll, ll> tmp = dat[s];
            dat[s] = dat[e];
            dat[e] = tmp;
            ++s;
            --e;
        }
    }

    if (l < e)quick_sort(l, e);
    if (s < r)quick_sort(s, r);
}

int bin_search(int i) {
    int l = i + 1, r = dat.size() - 1;
    pair<ll, ll> s = dat[i];

    while (l <= r) {
        int mid = (l + r) / 2;
        if (s.second <= dat[mid].first)r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main() {

    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll s, t;
        cin >> s >> t;
        dat.push_back({s, t});
    }

    quick_sort(0, dat.size() - 1);

    ll ans = 0;
    for (ll i = 0; i < dat.size() - 1; ++i) {
        int x = bin_search(i);
        ans += x - i - 1;
    }

    cout << ans;
    return 0;
}