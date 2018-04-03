#include <stdio.h>
#include <string.h>
const int MAX   =   1e6 + 10;
char a[MAX], b[MAX];
int next[MAX];
int main() {
    scanf("%s", &a[1]);
    scanf("%s", &b[1]);
    int k = 0;
    next[1] = 0;
    for (int i = 2; b[i]; i++) {
        while (k > 0 && b[k + 1] != b[i]) {
            k = next[k];
        }
        if (b[k + 1] == b[i]) k++;
        next[i] = k;
    }
    k = 0;
    for (int i = 1; a[i]; i++) {
        while (k > 0 && b[k + 1] != a[i]) {
            k = next[k];
        }
        if (b[k + 1] == a[i]) k++;
        if (!b[k + 1]) {
            printf("%d ", i - k + 1);
            k = next[k];
        }
    }
    puts("");
    return 0;
}