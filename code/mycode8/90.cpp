#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
vector<int>g[N];
int w[N],deep[N],id[N],fa[N],top[N],size[N],son[N],va[N],cnt=1,n,mm,q;
int tree[4*N][30],add[4*N];
char s[N];
void dfs1(int u,int f,int dp){
    fa[u]=f;
    deep[u]=dp;
    size[u]=1;
    for(int it:g[u]){
        if(it!=f){
            dfs1(it,u,dp+1);
            size[u]+=size[it];
            if(size[it]>size[son[u]]){
                son[u]=it;
            }
        }
    }
}

void dfs2(int u,int up){
    va[cnt]=u;
    id[u]=cnt++;
    top[u]=up;
    if(son[u])dfs2(son[u],up);
    for(auto it:g[u]){
        if(it!=son[u]&&fa[u]!=it)dfs2(it,it);
    }
}

#define m (l+r)/2
#define lson 2*node
#define rson 2*node+1

void push_up(int node) {
    for (int i = 0; i <= 26; i++) {
        tree[node][i] = tree[lson][i] + tree[rson][i];
    }
}

void build(int l,int r,int node){
    if(l==r){
        tree[node][s[va[l]] - 'a']++;
        return;
    }
    build(l,m,lson);
    build(m+1,r,rson);
    push_up(node);

}


int ans[30];

void query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        for (int i = 0; i <= 26; i++) {
            ans[i] += tree[node][i];
        }
        return;
    }
    if (ql <= m) query(ql, qr, l, m, lson);
    if (qr > m) query(ql, qr, m + 1, r, rson);
}

int qu(int x, int y) {
    for (int i = 0; i <= 26; i++) {
        ans[i] = 0;
    }
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        query(id[top[x]],id[x],1,n,1);
        x = fa[top[x]];
    }
    if(deep[x]<deep[y])swap(x,y);
    query(id[y],id[x],1,n,1);
    int res = 0, f = 0;
    for (int i = 0; i <= 26; i++) {
        if (ans[i] % 2 == 0) {
            res += ans[i];
        } else if (ans[i] > 1){
            f = 1;
            res += ans[i] - 1;
        } else if (ans[i] == 1) {
            f = 1;
        }
    }
    return res + f;
}

int main(){
    scanf("%d", &n);
    cnt=1;
    int u,v;
    for(int i=1;i< n;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%s", s + 1);

    dfs1(1,0,1);
    dfs2(1,1);
    fa[1]=1;
    build(1,n,1);
    scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", qu(l, r));
    }
    

}