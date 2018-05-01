#include <stdio.h>
#include <algorithm>
using namespace std;
const int NMAX = 1e6;
int n; 
int a[NMAX];
int f[NMAX];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1); 
    }
    printf("%d", f[n]);
    return 0;
}
/*
    6
    3 1 2 5 1 6
*/
/*
    Longest Increasing Subsequence
    F[i] : the longest increasing subsequence with the last element is a[i]
    for every f[i], f[i] = 1. For every j < i, if a[j] < a[i] and f[i] < f[j] + 1 then we can update f[i] = f[j] + 1
    Complexity : O(N^2) We can reduce the complexity by using 
    Complexity for space : O(N)
*/