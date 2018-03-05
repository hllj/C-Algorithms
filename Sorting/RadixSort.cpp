#include <iostream>
#include <vector>
#include <queue>
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
    queue <int> q;
    queue <int> bucket[2];
    for (int i = 0; i < N; i++)
        q.push(a[i]);
    for (int k = 0; k < 32; k++) {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int bit = getbit(u, k);
            bucket[bit].push(u);
        }
        while (!bucket[0].empty()) {
            int u = bucket[0].front();
            bucket[0].pop();
            q.push(u);
        }
        while (!bucket[1].empty()) {
            int u = bucket[1].front();
            bucket[1].pop();
            q.push(u);
        }
    }
    for (int i = 0; i < N; i++) {
        a[i] = q.front();
        q.pop();
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