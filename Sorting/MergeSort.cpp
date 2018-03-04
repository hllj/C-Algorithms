#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
const int NMAX      =   1000;
void createArray(int a[], int& N) {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
}
void displayArray(int a[], int N) {
    cout << "Array :";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << "\n";
}
void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}
void Insertionsort(int a[], int N) {
    for (int i = 0; i < N; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[i]) j--;
        int tmp = a[i];
        for (int k = i; k > j; k--) 
            a[k] = a[k - 1];
        a[j] = tmp;
    }
}
void Merge(int a[], int left, int mid, int right) {
    int b[NMAX];
    int cnt = 0;
    int p1 = left, p2 = mid + 1;
    while (p1 <= mid && p2 <= right) {
        if (a[p1] < a[p2]) {
            b[cnt] = a[p1];
            cnt++;
            p1++;
        }
        else {
            b[cnt] = a[p2];
            cnt++;
            p2++;
        }
    }
    if (p1 <= mid)
        for (int i = p1; i <= mid; i++) {
            b[cnt] = a[i];
            cnt++;
        }
    if (p2 <= right) 
        for (int i = p2; i <= right; i++) {
            b[cnt] = a[i];
            cnt++;
        }
    for (int i = 0; i < cnt; i++)
        a[left + i] = b[i];
}

void MergeSort(int a[], int left, int right) {
    if (right - left + 1 == 1) return;
    int mid = (left + right) >> 1;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}
int main() {
    int a[NMAX], N;
    createArray(a, N);
    displayArray(a, N);
    MergeSort(a, 0, N - 1);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/