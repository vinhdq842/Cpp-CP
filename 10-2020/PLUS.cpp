//
// Created by admin on 06/10/2020.
//

#include<bits/stdc++.h>
#include <io.h>

using ll = long long;
using namespace std;
ll n, k, ans = 0;
ll arr[100005];

bool cmp(int a, int b) {
    return a > b;
}

void solve(int i) {
    string dir = "TEST" + to_string(i);

    ifstream inp(dir + "/PLUS.INP");
    ofstream out(dir + "/PLUS.OUT");

    inp >> n >> k;
    for (ll i = 0; i < n; ++i)inp >> arr[i];

    sort(arr + 1, arr + n, cmp);
    ans = arr[0];
    for (ll i = 1; i <= k; ++i)ans += arr[i];
    for (ll i = k + 1; i < n; ++i)ans -= arr[i];

    out << ans;
    inp.close();
    out.close();
}

void generate_test(int i, int n, int k) {
    string dir = "TEST" + to_string(i);
    mkdir(dir.c_str());
    string o = "TEST" + to_string(i) + "/PLUS.INP";
    ofstream out(o);
    out << n << " " << k << "\n";
    for (int i = 0; i < n; i++)out << rand() % 10000 << " ";
    out.close();
}

int main() {
    srand(time(0));
    for (int i = 1; i <= 5; i++) {
        if (i < 3) {
            int n = rand() %100;
            int k = rand() % (n * 2 / 3);
            generate_test(i, n, k);
        } else {
            int n = rand() % 100000;
            int k = rand() % (n * 2 / 3);
            generate_test(i, n, k);
        }
        solve(i);
    }
}