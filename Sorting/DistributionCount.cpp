#include <iostream>
#include <algorithm>
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
int getMax(int a[], int N) {
    int res = a[0];
    for (int i = 1; i < N; i++)
        res = max(res, a[i]);
    return res;
}
void DistributionCount(int a[], int N) {
    vector <int> b;
    int maxValue = getMax(a, N);
    b.resize(maxValue + 1);
    for (int i = 0; i <= maxValue; i++)
        b[i] = 0;
    int d[NMAX];
    for (int i = 0; i < N; i++)
        b[a[i]]++;
    for (int i = 1; i <= maxValue; i++)
        b[i] += b[i - 1];
    for (int i = N - 1; i >= 0; i--)
        d[--b[a[i]]] = a[i];
    for (int i = 0; i < N; i++)
        a[i] = d[i];
}
int main() {
    int a[NMAX], N;
    createArray(a, N);
    displayArray(a, N);
    DistributionCount(a, N);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/