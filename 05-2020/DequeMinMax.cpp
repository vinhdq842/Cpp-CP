//
// Created by admin on 01/05/2020.
//

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int l[n], r[n];
    int deque[n];

    deque[0] = -1;
    int top = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        while (top > 0 && arr[deque[top]] >= arr[i])--top;
        l[i] = deque[top] + 1;
        deque[++top] = i;
    }
//2 1 4 6 5
    deque[0] = n;
    top = 0;

    for (int i = n - 1; i >= 0; --i) {
        while (top > 0 && arr[deque[top]] >= arr[i])--top;
        r[i] = deque[top] - 1;
        deque[++top] = i;
    }

    for (int i = 0; i < n; ++i)cout << l[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i)cout << r[i] << " ";


    return 0;
}