#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX       =   1e3;
struct frac {
    int ts, ms;
};
int n, m;
frac a[MAX][MAX];
int res[MAX][MAX];
void readMatrix() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
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
void swaprow(int x, int y) {
    for (int j = 1; j <= m; j++) {
        frac tmp = a[x][j];
        a[x][j] = a[y][j];
        a[y][j] = tmp;
    }
}
void GaussElimination() {
    int x = 1, y = 1;
    while (x <= n && y <= m) {
        if (a[x][y].ts != 0) {
            frac t = a[x][y];
            for (int j = 1; j <= m; j++)
                a[x][j] = div(a[x][j], t);
            for (int k = 1; k <= n; k++)
            if (k != x) {
                frac t = div(a[k][y], a[x][y]);
                for (int j = 1; j <= m; j++)
                    a[k][j] = sub(a[k][j], mul(a[x][j], t));
            }
            x++;
            y++;
        }
        else {
            bool flag = 0;
            for (int k = x + 1; k <= n; k++)
            if (a[k][y].ts != 0) {
                flag = 1;
                swaprow(k, x);
                break;
            }
            if (flag == 0) y++;
        }
    }
}
int gcd(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}
void convertMatrix() {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (a[i][j].ts != 0) {
        int _gcd = (a[i][j].ts, a[i][j].ms);
        a[i][j].ts /= _gcd;
        a[i][j].ms /= _gcd;
    }
    int flcm = 1;
    int fgcd = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (a[i][j].ts != 0) {
            fgcd = gcd(fgcd, a[i][j].ms);
            flcm = flcm * a[i][j].ms / fgcd;
        }
        else res[i][j] = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (a[i][j].ts != 0) {
        res[i][j] = (flcm * a[i][j].ts) / a[i][j].ms;
    }
}
void printMatrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}
int main() {
    //freopen("gaussjord.inp", "r", stdin);
    //freopen("gaussjord.out", "w", stdout);
    readMatrix();
    GaussElimination();
    convertMatrix();
    printMatrix();
    return 0;
}
/*
4 5
1 7 1 3 0
1 7 -1 -2 -2
2 14 2 7 0
6 42 3 13 -3
*/
/*
    Similar to Gaussian Elimination, we adding 2 step when we found an upper triangular :
    - divide each elements in row x by the value of a[x][y]
    - Subtract each row that is not row x.
*/