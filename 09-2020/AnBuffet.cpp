//
// Created by admin on 24/09/2020.
//

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

struct data {
    ll w;
    ll v;

    data(ll w, ll v) {
        this->w = w;
        this->v = v;
    }

    data() {
        w = 0;
        v = 0;
    }

};

data dat[33], sum1[65537], sum2[65537];
int seg_tree[4 * 65537];
ll index1 = 0, index2 = 0, w_sum1 = 0, w_sum2 = 0, v_sum1 = 0, v_sum2 = 0;
ll n, u, v;


void quick_sort(ll l, ll r, data *pData) {
    ll s = l, e = r;
    data pivot = pData[l + rand() % (r - l + 1)];

    while (s <= e) {
        while (pData[s].w < pivot.w)++s;
        while (pData[e].w > pivot.w)--e;
        if (s <= e) {
            data tmp = pData[e];
            pData[e] = pData[s];
            pData[s] = tmp;
            ++s;
            --e;
        }
    }

    if (l < e)quick_sort(l, e, pData);
    if (s < r)quick_sort(s, r, pData);
}

void backtrack1(ll i) {
    if (i == (n - 1) / 2 + 1)return;

    for (int j = 0; j <= 1; ++j) {
        if (w_sum1 + dat[i].w * j > v)return;
        w_sum1 += dat[i].w * j;
        v_sum1 += dat[i].v * j;
        backtrack1(i + 1);
        if (i == (n - 1) / 2)sum1[index1++] = {w_sum1, v_sum1};
        w_sum1 -= dat[i].w * j;
        v_sum1 -= dat[i].v * j;
    }

}

void backtrack2(ll i) {
    if (i == n)return;

    for (int j = 0; j <= 1; ++j) {
        if (w_sum2 + dat[i].w * j > v)return;
        w_sum2 += dat[i].w * j;
        v_sum2 += dat[i].v * j;
        backtrack2(i + 1);
        if (i == n - 1)sum2[index2++] = {w_sum2, v_sum2};
        w_sum2 -= dat[i].w * j;
        v_sum2 -= dat[i].v * j;
    }
}

void build_tree(ll l, ll r, ll id = 0) {
    if (l == r) {
        seg_tree[id] = sum2[l].v;
        return;
    }

    ll mid = (l + r) / 2;
    build_tree(l, mid, id * 2 + 1);
    build_tree(mid + 1, r, id * 2 + 2);

    seg_tree[id] = max(seg_tree[2 * id + 1], seg_tree[2 * id + 2]);
}

ll get(ll id, ll l, ll r, ll uu, ll vv) {
    if (vv < l || uu > r)return -1;
    if (uu <= l && r <= vv)return seg_tree[id];

    ll mid = (l + r) / 2;
    return max(get(id * 2 + 1, l, mid, uu, vv), get(id * 2 + 2, mid + 1, r, uu, vv));
}

ll getL(ll l, ll r, ll i) {
    if (sum2[r].w + sum1[i].w < u)return -1;

    while (l <= r) {
        ll mid = (l + r) / 2;
        if (sum2[mid].w + sum1[i].w >= u)r = mid - 1;
        else l = mid + 1;
    }

    return l;
}

ll getR(ll l, ll r, ll i) {
    if (sum2[l].w + sum1[i].w > v)return -1;

    while (l <= r) {
        ll mid = (l + r) / 2;
        if (sum2[mid].w + sum1[i].w <= v)l = mid + 1;
        else r = mid - 1;
    }

    return r;
}

int main() {
    fast_io
    cin >> n >> u >> v;
    for (ll i = 0; i < n; ++i) {
        ll wi, vi;
        cin >> wi >> vi;
        dat[i] = data(wi, vi);
    }

    if (n < 2) {
        if (dat[0].w >= u && dat[0].w <= v)cout << dat[0].v;
        else cout << 0;
        return 0;
    }

    backtrack1(0);
    backtrack2((n - 1) / 2 + 1);

    quick_sort(0, index2 - 1, sum2);
    build_tree(0, index2 - 1);

    ll rs = 0;

    for (ll i = 0; i < index1; ++i) {
        ll l = getL(0, index2 - 1, i);
        ll r = getR(0, index2 - 1, i);

        if (l == -1 || r == -1 || l > r)continue;

        rs = max(rs, sum1[i].v + get(0, 0, index2 - 1, l, r));
    }

    cout << rs;

    return 0;
}