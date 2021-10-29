//
// Created by admin on 02/05/2020.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], fenwick[n + 1];

    for (int i = 0; i <= n; ++i)fenwick[i] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        for (unsigned int j = i + 1; j >=1; j -= j & (-j))fenwick[j] += arr[i];
    }


    for (int i = 1; i <= n; ++i)
        cout << fenwick[i] << " ";

    return 0;
}
