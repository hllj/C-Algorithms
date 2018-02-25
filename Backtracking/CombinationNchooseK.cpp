#include <iostream>
using namespace std;
const int NMAX      =   25; 
int N, K;
int count = 0; // Count the number of K-Combination
int X[NMAX]; //Vector X saving the selected number of each step
void outCombination() { //Print the Vector of each Combination
    count++;
    cout << count << ".";
    for (int j = 1; j <= K; j++)
        cout << " " << X[j];
    cout << "\n";
}
void Combination(int i) { //Backtracking
    for (int j = X[i - 1] + 1; j <= N - K + i; j++) {
        X[i] = j;
        if (i == K) outCombination(); 
        else Combination(i + 1);
    }
}
int main() {
    cin >> N >> K;
    X[0] = 0;
    Combination(1); //Starting at choosing the first number
    return 0;
}