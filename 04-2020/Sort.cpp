//
// Created by admin on 28/03/2020.
//

#include<iostream>
#include <list>

using namespace std;

void quickSort(int *, int, int);

void mergeSort(int *, int, int);

void printFirstNBinaryNumbers(int);

int tmp[100];

int main() {
    int aa[] = {4,3};
    quickSort(aa, 0, 1);
    for (int i = 0; i < 2; ++i)cout << aa[i] << " ";

    //printFirstNBinaryNumbers(10);
    return 0;
}

void printFirstNBinaryNumbers(int n) {
    list<string> list;
    list.push_back("0");
    list.push_back("1");
    while (--n >= 0) {
        cout << list.front() << "\n";
        list.pop_front();
        string tmp = list.front();
        list.push_back(tmp + "0");
        list.push_back(tmp + "1");
    }
}

void quickSort(int a[], int left, int right) {

    int pivot = a[(right + left) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < pivot)i++;
        while (a[j] > pivot)j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (j > left) quickSort(a, left, j);
    if (i < right)quickSort(a, i, right);
}


void mergeSort(int *a, int left, int right) {
    if (left == right)return;
    int mid = (left + right) / 2;

    int i = left, j = mid + 1;
    int cur = 0;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    while (i <= mid || j <= right) {
        if (i > mid) {
            tmp[cur++] = a[j++];
        } else if (j > right) {
            tmp[cur++] = a[i++];
        } else if (a[i] > a[j]) {
            tmp[cur++] = a[j++];
        } else {
            tmp[cur++] = a[i++];
        }
    }

    for (int i = 0; i < cur; i++)a[left + i] = tmp[i];
}