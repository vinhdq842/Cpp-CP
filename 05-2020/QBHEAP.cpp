//
// Created by admin on 04/05/2020.
//

#include<iostream>
#include <vector>

using namespace std;

#define fast_in_out ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define  ll long long


class PriorityQueue {
private:
    int n = 0;
    ll arr[15000]{};
public:
    bool empty() const {
        return n == 0;
    }

    void push(ll val) {
        if (n == 15000)return;
        arr[n++] = val;
        int index = n - 1;
        while (index != 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
    }

    ll pop() {
        if (empty())return 0;
        ll rs = arr[0];
        arr[0] = arr[--n];
        int index = 0;
        while (index * 2 + 1 < n) {
            if (index * 2 + 2 < n && arr[index * 2 + 1] < arr[index * 2 + 2])index = index * 2 + 2;
            else index = index * 2 + 1;
            if (arr[index] < arr[(index - 1) / 2])return rs;
            swap(arr[index], arr[(index - 1) / 2]);
        }
        return rs;
    }

    ll top() {
        return arr[0];
    }

private:
    static void swap(ll &a, ll &b) {
        ll tmp = a;
        a = b;
        b = tmp;
    }
};

int main() {
    fast_in_out

    PriorityQueue queue;
    char operation;

    while (cin >> operation) {
        if (operation == '+') {
            ll n;
            cin >> n;
            queue.push(n);
        } else if (!queue.empty()) {
            ll rm = queue.top();
            while (!queue.empty() && queue.top() == rm)queue.pop();
        }
    }

    vector<ll> rs;

    while (!queue.empty()) {
        ll n = queue.top();
        rs.push_back(n);
        while (!queue.empty() && queue.top() == n)queue.pop();
    }

    cout << rs.size() << "\n";
    for (ll &a:rs)cout << a << " ";

    return 0;
}
