#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

vector<int>g[N];
int n, k, sizes[N], color[N], deep[N];

struct node{
    int v, pos;
}p[N];

bool cmp(node x, node y){
    return x.v > y.v;
}

void dfs(int u, int fa, int dp){

    deep[u] = dp;
    sizes[u] = 1;
    for(int j: g[u]){
        if(j == fa)continue;
        dfs(j, u, dp + 1);
        sizes[u] += sizes[j];
    }
}


int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    for(int i = 1; i <= n; i++){
        p[i].pos = i;
        p[i].v = sizes[i] - deep[i] - 1;
    }
    int c = n - k;
    sort(p + 1, p + n + 1, cmp);
    long long ans = 0;
    for(int i = 1; i <= c; i++){
        ans += p[i].v;
    }
    cout << ans << endl;
   



}


