//
// Created by admin on 19/04/2020.
//

#include <iostream>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100000000

ll arr[101], f[1000010];

ll numberStepsDP(ll, ll, ll);

ll numberStepsBFS(ll, ll, ll);

struct vertex {
    ll data;
    ll steps;

    vertex(ll data, ll steps) {
        this->data = data;
        this->steps = steps;
    }
};

int main() {
    ll n, arr_length, m;
    cin >> n;
    cin >> arr_length;
    for (ll i = 0; i < arr_length; ++i)cin >> arr[i];
    cin >> m;

    cout << numberStepsBFS(n, arr_length, m);
    return 0;
}


ll numberStepsBFS(ll n, ll arr_length, ll m) {
    queue<vertex> q;
    q.push(vertex(n, 0));


    while (!q.empty()) {
        vertex v = q.front();
        q.pop();
        if (v.data == m) {
            return v.steps;
        }

        for (ll i = 0; i < arr_length; ++i) {
            if (v.data * arr[i] <= m && arr[i] != 1)q.push(vertex(v.data * arr[i], v.steps + 1));
            if (v.data + arr[i] <= m && arr[i] != 0)q.push(vertex(v.data + arr[i], v.steps + 1));
        }
    }

    return -1;
}

/**
 * for (ll i = 0; i < n; ++i)f[i] = -1;
 * f[n] = 0;
 * cout << numberStepsDP(n, arr_length, m);
 */

ll numberStepsDP(ll n, ll arr_length, ll m) {

    for (ll i = n + 1; i <= m; ++i) {
        f[i] = MAX;
        for (ll j = 0; j < arr_length; ++j) {
            if (i >= arr[j] && f[i - arr[j]] != -1)f[i] = min(f[i], f[i - arr[j]]);
            if (i % arr[j] == 0 && f[i / arr[j]] != -1)f[i] = min(f[i], f[i / arr[j]]);
        }
        f[i] = f[i] == MAX ? -1 : f[i] + 1;
    }

    return f[m];
}