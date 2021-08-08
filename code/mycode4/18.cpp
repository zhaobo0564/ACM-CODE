#include<bits/stdc++.h>
using namespace std;
const int N = 1007;
int fa[N];

int find(int x){
    if(x != fa[x]){
        return fa[x] = find(fa[x]);
    }
    return x;
}


int main(){
    int t, n, m;
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= n; i++)fa[i] = i;
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        int fx = find(u);
        int fy = find(v);
        if(fx != fy){
            fa[fx] = fa[fy];
        }
    }
    while(t--){
        int u, v;
        scanf("%d %d", &u, &v);
        int fx = find(u);
        int fy = find(v);
        if(fx == fy){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}