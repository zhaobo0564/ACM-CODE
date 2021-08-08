#include<bits/stdc++.h>
using namespace std;
const int N = 107;
int fa[N],n,m;

struct node{
    int u, v, w;
} e[N * N];

bool cmp(node x,node y){
    return x.w < y.w;
}

void init(){
    for (int i = 1;i<=n;i++){
        fa[i] = i;
    }
}

int find(int x){
    if(x!=fa[x]){
        return fa[x]=find(fa[x]);
    }
    return x;
}

bool merge(int x,int y){
    int q = find(x);
    int p = find(y);
    if(p==q){
        return false;
    }
    fa[p] = q;
    return true;
}

int kruskal(){
    int ans = 0;
    init();
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m;i++){
        if(judge(e[i].u,e[i].v)){
            ans += e[i].w;
        }
    }
    return ans;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m;i++){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    printf("%d\n", kruskal());
}
