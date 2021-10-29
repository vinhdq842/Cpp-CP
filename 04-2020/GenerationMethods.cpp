//
// Created by admin on 07/04/2020.
//

#include <bits/stdc++.h>

using namespace std;

void genBinString(int);

void permute();

void subset(int, int);

int main() {
    queue<int> q;
    subset(3, 5);
    return 0;
}

void genBinString(int n) {
    char a[n];
    //memset(a, '0', n);
    for (int i = 0; i < n; ++i)a[i] = '0';
    int i;
    do {
        for (int j = 0; j < n; ++j)cout << a[j];
        cout << "\n";
        for (i = n - 1; i >= 0; --i) {
            if (a[i] == '0') {
                a[i] = '1';
                for (int j = i + 1; j < n; ++j)a[j] = '0';
                break;
            }
        }
    } while (i >= 0);
}

void permute() {

    string p = "IIIIMPPSSSS";
    int id = 1;
    int i = p.length() - 1;
    int j = p.length() - 1;
    do {
        cout << id++ << ". " << p << "\n";
        for (i = p.length() - 1; i > 0 && p[i] <= p[i - 1]; i--);
        i--;

        for (j = p.length() - 1; p[j] <= p[i]; j--);

        if (i != j) {
            char c = p[i];
            p[i] = p[j];
            p[j] = c;
            int l = p.length() - 1;
            int k = i + 1;
            while (k < l) {
                c = p[k];
                p[k] = p[l];
                p[l] = c;
                k++;
                l--;
            }
        }
    } while (i >= 0);
}

void subset(int k, int n) {
    int curState[k];
    for (int i = 0; i < k; i++)curState[i] = i + 1;

    int j;
    do {
        cout << "{";
        for (int i = 0; i < k - 1; i++)cout << curState[i] << ", ";
        cout << curState[k - 1] << "}\n";

        for (j = k - 1; j >= 0 && curState[j] == n - k + j + 1; j--);
        if (j >= 0) {
            curState[j]++;
            for (int i = j + 1; i < k; i++)curState[i] = curState[i - 1] + 1;
        }
    } while (j >= 0);
}