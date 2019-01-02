#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
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
void heapify(int a[], int n, int i) {
    int m = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (a[l] > a[m] && l < n) {
        m = l;
    }
    if (a[r] > a[m] && r < n) {
        m = r;
    }
    cout << i << " " << m << "\n";
    if (m != i) {
        swap(a[m], a[i]);
        heapify(a, n, m);
    }
}
void HeapSort(int a[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(a, N, i);
    }
    for (int i = N - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }

}
int main() {
    int a[NMAX], N;
    createArray(a, N);
    HeapSort(a, N);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/