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
int main() {
    int a[NMAX], N;
    createArray(a, N);
    displayArray(a, N);
    Insertionsort(a, N);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/