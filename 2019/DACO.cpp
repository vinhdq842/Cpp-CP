//
// Created by admin on 20/10/2019.
//
#include <iostream>
#include <memory.h>

using namespace std;

#define  ll long long

int main() {
    ll n;
    cin >> n;
    ll arr[n], result[n];
    fill(result, result + n, 1);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll rs = 0;
    ll rsIndex = 0;
    for (ll i = 0; i < n; i++) {
        ll maxValue = 0;
        for (ll j = i; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                maxValue = max(result[j], maxValue);
            }
        }
        result[i] = maxValue + 1;
        if (result[i] > rs) {
            rsIndex = i;
            rs = result[i];
        }
    }
    string sequence = "";
    for (ll i = rsIndex; i >= 0; i--) {
        if (arr[i] <= arr[rsIndex])sequence = to_string(arr[i]) + " " + sequence;
    }
    cout << rs << "\n" << sequence;
    return 0;
}
