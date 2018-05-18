#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;
int n, m, s, t;
vector <int> adj[nmax];
bool fre[nmax];
int trace[nmax];
void dfs(int u) {
    fre[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fre[v]) {
            trace[v] = u;
            dfs(v);
        }
    }
}
int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        fre[i] = 1;
        trace[i] = -1;
    }
    dfs(s);
    if (trace[t] == -1) printf("There is no path from s to t");
    else {
        printf("Path from %d to %d :", s, t);
        vector <int> path;
        while (s != t) {
            path.push_back(t);
            t = trace[t];
        }
        printf("%d ");
        for (int i = path.size() - 1; i >= 0; i--)
            printf("-> %d", path[i]);
    }
    return 0;
}
/*
8 7 1 6
1 2 
1 3 
2 3
2 4 
4 6
3 5 
7 8
*/