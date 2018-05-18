#include <bits/stdc++.h>
using namespace std;
int extendedeuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedeuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}
int main() {
    int a, m;
    cin >> a >> m;
    int x, y;
    if (extendedeuclid(a, m, x, y) != 1) cout << "Inverse doesn't exist!";
    else {
        cout << "Inverse modulo : " << (x % m + m) % m;
    }
    return 0;
}