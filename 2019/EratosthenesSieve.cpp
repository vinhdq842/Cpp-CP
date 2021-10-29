//
// Created by admin on 05/10/2019.
//
#include <iostream>
#include <memory.h>
#include <fstream>

using namespace std;

int main() {
    ifstream in("../PIE.INP");
    ofstream out("../PIE.OUT");

    long long r, l;
    in >> l >> r;
    bool isPrime[r - l + 1];//filled by true
    memset(isPrime, true, r - l + 1);

    for (long long i = 2; i * i <= r; ++i) {
        for (long long j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
            isPrime[j - l] = false;
        }
    }
    int rs = 0;
    for (long long i = max(l, 2ll); i <= r; ++i) {
        if (isPrime[i - l]) {
            //then i is prime
            ++rs;
        }
    }
    out << rs;
    return 0;
}