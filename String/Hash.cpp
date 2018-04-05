#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int MOD       =   1e9 + 7;
const int MAX      =   1e6 + 10;
ll POW[MAX];
ll hashT[MAX];
ll getHash(int i, int j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD) % MOD;
}
int main() {
    string T, P;
    cin >> T >> P;
    int n = T.length(), m = P.length();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;
    for (int i = 1; i <= n; i++)
        POW[i] = (POW[i - 1] * 26) % MOD;
    ll hashP = 0;
    for (int i = 1; i <= m; i++)
        hashP = (hashP * 26 + P[i] - 'a') % MOD;
    hashT[0] = 0;
    for (int i = 1; i <= n; i++)
        hashT[i] = (hashT[i - 1] * 26 + T[i] - 'a') % MOD;
    for (int i = 1; i <= n - m + 1; i++) 
        if (getHash(i, i + m - 1) == hashP) {
            cout << "String match at : " << i << "\n";
        }
    return 0;
}