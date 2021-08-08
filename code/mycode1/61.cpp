#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;

int head[N], top = 1, fa[N][33],deep[N];




int lca(int x,int y){
    if(deep[x]<deep[y]){
        swap(x, y);
    }
    int d = deep[x] - deep[y];
    for (int i = 0; i < 32;i++){
        if(d&1){
            x = fa[x][i];
        }
        d = d / 2;
    }
    if(x==y){
        return x;
    }
    for (int i = 31; i >= 0;i--){
        int tox = fa[x][i];
        int toy = fa[y][i];
        if(tox==0){
            continue;
        }
        if(tox!=toy){
            x = tox;
            y = toy;
        }
    }
    return fa[x][0];
}

int main(){
    int k; scanf("%d", &k);
    deep[1] = 0;
    while(k--){
        string s;
        int a, b;
        cin >> s;
        scanf("%d %d", &a, &b);
        if(s == "ADD"){
            fa[b][0] = a;
            deep[b] = deep[a] + 1;
            for (int i = 1; i < 32;i++){
                fa[b][i] = fa[fa[b][i - 1]][i - 1];
            }
        }else{
            int ans = lca(a, b);
            printf("%d\n", ans);
        }

    }
}