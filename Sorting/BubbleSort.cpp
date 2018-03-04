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
void Bubblesort(int a[], int N) {
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i] > a[j]) swap(a[i], a[j]);
}
int main() {
    int a[NMAX], N;
    createArray(a, N);
    displayArray(a, N);
    Bubblesort(a, N);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/