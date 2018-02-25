#include <iostream>
using namespace std;
const int NMAX      =   20;
const int oo        =   1e6;
int N;
int C[NMAX][NMAX];
int mark[NMAX];
int X[NMAX], bestPath[NMAX];
int bestCost, Cost;
void readInp() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            cin >> C[i][j];
}
void init() {
    for (int i = 0; i < N; i++)
        mark[i] = 1;
    mark[0] = 0;
    X[0] = 0;
    bestCost = oo;
    Cost = 0;
}
void update() {
    if (Cost + C[X[N - 1]][0] < bestCost) {
        bestCost = Cost + C[X[N - 1]][0];
        for (int i = 0; i < N; i++)
            bestPath[i] = X[i];
    }
}
void BranchBound(int i) {
    if (Cost >= bestCost) return;
    for (int j = 0; j < N; j++)
        if (mark[j]) {
            mark[j] = 0;
            X[i] = j;
            Cost += C[X[i - 1]][j];
            if (i == N - 1) update(); 
            else 
                BranchBound(i + 1);
            Cost -= C[X[i - 1]][j];
            mark[j] = 1;
        }
}
void printOut() {
    cout << bestCost << "\n";
    cout << "Path : ";
    for (int i = 0; i < N; i++)
        cout << bestPath[i] << "->";
    cout << "0";
}
int main() {
    readInp();
    init();
    BranchBound(1);
    printOut();
    return 0;
}
/*
4
0 20 35 42
20 0 34 30
35 34 0 12
42 30 12 0
*/