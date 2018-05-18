#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;
int n, m, s, t;
vector <int> adj[nmax];
bool fre[nmax];
int number[nmax], low[nmax];
stack <int> st;
int cnt = 0;
int Component = 0;
void dfs(int u) {
    number[u] = ++cnt;
    low[u] = cnt;
    st.push(u);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) {
            if (number[v] == 0) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else 
                low[u] = min(low[u], number[v]);
        }
    }
    if (number[u] == low[u]) {
        Component++;
        printf("Component %d : ", Component);
        int v;
        do {
            v = st.top();
            st.pop();
            fre[v] = 0; 
            printf("%d ", v);
        } while (v != u);
        printf("\n");
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        fre[i] = 1;
        number[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        if (number[i] == 0) dfs(i);
    return 0;
}
/*
    11 15
    1 2
    1 8
    2 3
    3 4
    4 2
    4 5 
    5 6
    6 7
    7 5
    8 9
    9 4
    9 10
    10 8
    10 11
    11 8
*/  