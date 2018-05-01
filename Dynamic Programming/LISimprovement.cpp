#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX = 1e6;
int n; 
int a[NMAX];
int f[NMAX];
int res;
int bsearch(int i) {
    int left = 1, right = res;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (a[i] > a[f[mid]]) left = mid + 1;
        else right = mid;
    }
    return left;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    res = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) 
        if (a[i] > a[f[res]]) f[++res] = i;
        else f[bsearch(i)] = i;
    printf("%d", res);
    return 0;
}
/*
    6
    3 1 2 5 1 6
*/
/*
    We will have an improvement for LIS algorithm. 
    We define f[i] = k, it means the LIS with length i has the last element is k.
    we will see that, if element i-th is greater than the last f[], we will increase the length by f[++res] = i.
    If element i-th is not greater than the last of f[], we will see that f[1] < f[2] < ... < f[res].
    So that, we can use binary search to find the place for element i-th.
*/