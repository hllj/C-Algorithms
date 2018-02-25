#include <iostream>
using namespace std;
const int N     =   8;
int count = 0; //Count the result
int column[N]; //Check the Column
int mainDiagonal[2 * N], auxDiagonal[2 * N]; //Check the main Diagonal and aux-Diagonal
int X[N]; //Vector Result, placing each Queen at (i, X[i])
void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            mainDiagonal[i - j + N - 1] = 1; //Mark the main Diagonal
            auxDiagonal[i + j] = 1; //Mark the aux-Diagonal
        }
    for (int i = 0; i < N; i++) {
        X[i] = 0;
        column[i] = 1;//Mark the Column                 
    }
}
void outResult() {
    count++;
    cout << count << ".";
    for (int i = 0; i < N; i++)
        cout << " " << X[i];
    cout << "\n";
}
void Try(int i) { //Choosing a place in row i to put a Queen
    for (int j = 0; j < N; j++)
        if (column[j] && mainDiagonal[i - j + N - 1] && auxDiagonal[i + j]) { //Condition to put a Queen in (i, j)
            X[i] = j;
            column[j] = 0;
            mainDiagonal[i - j + N - 1] = 0;
            auxDiagonal[i + j] = 0;
            if (i == N - 1) outResult();
            else   
                Try(i + 1);
            X[i] = 0;
            column[j] = 1;
            mainDiagonal[i - j + N - 1] = 1;
            auxDiagonal[i + j] = 1;
        } 
}
int main() {
    init();
    Try(0); //Backtracking
    return 0;
}