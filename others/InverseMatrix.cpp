#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int MAX       =   1e3;
struct frac {
    int ts, ms;
};
int n;
frac a[MAX][MAX];
frac I[MAX][MAX];
int res[MAX][MAX];
void readMatrix() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        int x;
        cin >> x;
        a[i][j].ts = x;
        a[i][j].ms = 1;
    }
}
frac add(frac x, frac y) { //fraction x + fraction y
    frac res;
    res.ts = x.ts * y.ms + y.ts * x.ms;
    res.ms = x.ms * y.ms;
    return res;
}
frac sub(frac x, frac y) { //fraction x - fraction y
    frac res;
    res.ts = x.ts * y.ms - y.ts * x.ms;
    res.ms = x.ms * y.ms;
    return res;
}
frac mul(frac x, frac y) { //fraction x * fraction y
    frac res;
    res.ts = x.ts * y.ts;
    res.ms = x.ms * y.ms;
    return res;
}
frac div(frac x, frac y) {// fraction x / fraction y
    frac res;
    res.ts = x.ts * y.ms;
    res.ms = x.ms * y.ts;
    return res;
}
int equal(frac x, frac y) {
    if (x.ts * y.ms == y.ts * x.ms) return 1;
    else return 0;
}
void init() {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (i == j) {
        I[i][j].ts = 1;
        I[i][j].ms = 1;
    }
    else {
        I[i][j].ts = 0;
        I[i][j].ms = 1;
    }
}
void swap(frac x, frac y) {
    frac tmp = x;
    x = y;
    y = tmp;
}
int gcd(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}
frac reduce(frac x) {
    frac res;
    if (x.ts == 0) {
        res.ts = 0;
        res.ms = 1;
    }
    else {
        int _gcd = gcd(abs(x.ts), abs(x.ms));
        res.ts = x.ts / _gcd;
        res.ms = x.ms / _gcd;
    }
    return res;
}
void GaussJordan() {
    int x = 1, y = 1;
    while (x <= n && y <= n) {
        if (a[x][y].ts != 0) {
            frac t = a[x][y];
            for (int j = 1; j <= n; j++)
                a[x][j] = reduce(div(a[x][j], t));
            for (int j = 1; j <= n; j++)
                I[x][j] = reduce(div(I[x][j], t));
            for (int k = 1; k <= n; k++)
            if (k != x) {
                frac t = div(a[k][y], a[x][y]);
                for (int j = 1; j <= n; j++)
                    a[k][j] = reduce(sub(a[k][j], mul(a[x][j], t)));
                for (int j = 1; j <= n; j++)
                    I[k][j] = reduce(sub(I[k][j], mul(I[x][j], t)));
            }
            x++;
            y++;
        }
        else {
            bool flag = 0;
            for (int k = x + 1; k <= n; k++)
            if (a[k][y].ts != 0) {
                flag = 1;
                for (int j = 1; j <= n; j++) {
                    swap(a[k][j], a[x][j]);
                    swap(I[k][j], I[x][j]);
                }
                break;
            }
            if (flag == 0) y++;
        }
    }
}
int Condition() {
    int rank = 0;
    frac sum;
    sum.ts = 0;
    sum.ms = 1;
    frac sumDiagon;
    sumDiagon.ts = 0;
    sumDiagon.ms = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        sum = reduce(add(sum, a[i][j]));
        if (i == j && a[i][j].ts == a[i][j].ms) {
            sumDiagon = reduce(add(sumDiagon, a[i][j]));
            rank++;
        }
    }
    if (equal(sum, sumDiagon)&& rank == n) return 1;
    else return 0;
}
void convertMatrix() {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        I[i][j] = reduce(I[i][j]);
    int flcm = 1;
    int fgcd = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        if (I[i][j].ts != 0) {
            fgcd = gcd(fgcd, abs(I[i][j].ms));
            flcm = (flcm * I[i][j].ms) / fgcd;
        }
        else res[i][j] = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (I[i][j].ts != 0) {
        res[i][j] = (flcm * I[i][j].ts) / I[i][j].ms;
    }
}
void printMatrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}
int main() {
    //freopen("inversematrix.inp", "r", stdin);
    //freopen("inversematrix.out", "w", stdout);
    readMatrix();
    init();
    GaussJordan();
    if (Condition()) {
        convertMatrix();
        printMatrix();
    }
    else
        cout << "This Matrix doesn't have Inverse Matrix";
    return 0;
}

