#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

vector<int> g[N], G[N];
int vis[N];


int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        g[u].push_back(v);
        G[v].push_back(u);
    }
    int now = 1;
   
    
}