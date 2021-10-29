//
// Created by admin on 18/10/2020.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAX 10000000
int a[123];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 123; i++)a[i] = MAX;
    string s;
    getline(cin, s);
    int minI = MAX;

    for (int i = 0; i < s.length(); ++i) {
        if (a[s[i]] == MAX)a[s[i]] = 0;
        a[s[i]]++;
    }

    for (int i = 0; i < s.length(); ++i)minI = min(minI, a[s[i]]);

    int rs = 1;
    int j;
    bool continue_e = false;
    for (int i = s.length() / minI; i >= 1; --i) {
        if (s.length() % i != 0)continue;
        for (j = 0; j <= s.length() - 2 * i; j += i) {
            string str1 = s.substr(j, i);
            sort(str1.begin(), str1.begin() + str1.length());
            string str2 = s.substr(j + i, i);
            sort(str2.begin(), str2.begin() + str2.length());
            //cout <<i<<" "<< j << " " << str1 << " " << str2 << "\n";
            if (str1 != str2) {
                continue_e = true;
                break;
            }
        }
        if (continue_e) {
            continue_e = false;
            continue;
        }
        rs = rs < s.length() / i ? s.length() / i : rs;
    }
    cout << rs;
    return 0;
}