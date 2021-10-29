//
// Created by admin on 15/08/2020.
//

#include<iostream>
#include <memory.h>

using namespace std;

void analyzeNum(int);

int n;
int *state;
int *sum;

int main() {
    cin >> n;
    state = new int[n + 1];
    sum = new int[n + 1];
    state[0] = 1;
    sum[0] = 0;
    analyzeNum(1);
    return 0;
}

void analyzeNum(int i) {
    for (int j = state[i - 1]; j <= (n - sum[i - 1]) / 2; j++) {
        state[i] = j;
        sum[i] = sum[i - 1] + j;
        analyzeNum(i + 1);
    }
    state[i] = n - sum[i - 1];
    cout << n << " = ";
    for (int k = 1; k < i; k++)cout << state[k] << " + ";
    cout << state[i] << "\n";
}