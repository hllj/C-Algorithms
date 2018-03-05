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
void HeapSort(int a[], int N) {
    priority_queue <int, vector <int>, greater <int> > q;
    for (int i = 0; i < N; i++) 
        q.push(a[i]);
    for (int i = 0; i < N; i++) {
        a[i] = q.top();
        q.pop();
    }
}
int main() {
    int a[NMAX], N;
    createArray(a, N);
    displayArray(a, N);
    HeapSort(a, N);
    displayArray(a, N);
    return 0;
}
/*
    10
    8 5 1 3 4 8 6 4 12 6
*/