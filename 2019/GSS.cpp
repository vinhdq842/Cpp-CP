#include <iostream>

using namespace std;

int sumOfPos(int[], int);

int max1(int[], int);

int arrMax(int[], int);

//8
//1 2 -4 -5 -6 1 2 3
int main() {
    int n;
    bool isAllPositive = 1, isAllNegative = 1;
    cin >> n;
    int a[n];
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
        isAllNegative = isAllNegative && (a[i] <= 0);
        isAllPositive = isAllPositive && (a[i] >= 0);
    }
    if (isAllNegative) {
        int tmp = arrMax(a, n);
        cout << tmp << " " << tmp;
    } else if (isAllPositive) {
        int tmp = sumOfPos(a, n);
        cout << tmp << " " << tmp;
    } else
        cout << max1(sum, n) << " " << sumOfPos(a, n);
    return 0;
}

int arrMax(int a[], int n) {
    int maxTmp = a[0];
    for (int i = 0; i < n; i++)
        maxTmp = max(maxTmp, a[i]);
    return maxTmp;
}

int sumOfPos(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            sum += a[i];
    return sum;
}


int max1(int sum[], int n) {
    int maxSum = 0;
    for (int i = 1; i <= n; i++) {
        int minSumI = 0;
        for (int j = 1; j <= i; j++) {
            minSumI = min(minSumI, sum[j]);
        }
        maxSum = max(sum[i] - minSumI, maxSum);
    }
    return maxSum;
}
