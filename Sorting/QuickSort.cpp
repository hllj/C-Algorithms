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
void QuickSort(int a[], int left, int right) {
    int i = left, j = right;
    int x = a[left + rand() % (right - left)];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}
int main() {
    int a[NMAX], N;
    createArray(a, N);
    displayArray(a, N);
    QuickSort(a, 0, N - 1);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/