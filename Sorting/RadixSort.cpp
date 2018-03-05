#include <iostream>
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
int getbit(int x, int i) {
    return (x >> i) & 1; 
}
void RadixSort(int a[], int N) {
    int d[NMAX];
    for (int k = 0; k < 32; k++) {
        int b[2] = {0};
        for (int i = 0; i < N; i++) 
            b[getbit(a[i], k)]++;
        b[1] += b[0];
        for (int i = N - 1; i >= 0; i--) 
            d[--b[getbit(a[i], k)]] = a[i];
        for (int i = 0; i < N; i++)
            a[i] = d[i];
    }
}
int main() {
    int a[NMAX], N;
    createArray(a, N);
    displayArray(a, N);
    RadixSort(a, N);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/