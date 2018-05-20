#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
const int NMAX = 1000;
const int base = 1e9;
typedef long long ll;
struct bigInt {
    int len;
    ll d[1000];
};
bigInt f[NMAX];
bigInt operator +(bigInt a, bigInt b) {
    bigInt c;
    c.len = max(a.len, b.len);
    for (int i = 0; i < 1000; i++) c.d[i] = 0;
    ll cur = 0;
    for (int i = 0; i < c.len; i++) {
        if (i < a.len) cur += a.d[i];
        if (i < b.len) cur += b.d[i];
        c.d[i] = cur % base;
        cur /= base;
    }
    if (cur > 0) c.d[c.len++] = cur;
    return c;
}
void print(bigInt a) {
    cout << a.d[a.len - 1];
    for (int i = a.len - 2; i >= 0; i--)
        cout << setfill('0') << setw(8) << a.d[i];
}
int main() {
    //Example for Fibonacci - Nth 
    int N;
    cin >> N;
    f[1].len = 1;
    f[1].d[0] = 1;
    f[2].len = 1;
    f[2].d[0] = 1;
    for (int i = 3; i <= N; i++)
        f[i] = f[i - 1] + f[i - 2];
    print(f[N]);
    return 0;
}