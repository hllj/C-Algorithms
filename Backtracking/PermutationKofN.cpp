#include <iostream>
using namespace std;
const int NMAX      =   20;
int N, K;
int count = 0;
int X[NMAX];
int mark[NMAX];
void init() {
    for (int i = 1; i <= N; i++)
        mark[i] = 1;
    for (int i = 1; i <= K; i++)
        X[i] = 0;
}
void outPermutation() {
    count++;
    cout << count << ".";
    for (int i = 1; i <= K; i++)
        cout << " " << X[i];
    cout << "\n";
}
void Permutation(int i) {
    for (int j = 1; j <= N; j++)
        if (mark[j]) {
            X[i] = j;
            mark[j] = 0;
            if (i == K) outPermutation(); 
            else 
                Permutation(i + 1);
            X[i] = 0;
            mark[j] = 1;
        }
}
int main() {
    cin >> N >> K;
    init();
    Permutation(1);
    return 0;
}