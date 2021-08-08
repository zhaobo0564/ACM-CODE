#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

inline int input(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return f? -x:x;
}

int vis[N], n, q, sizes[N], fa[N];

vector<int>g[N];
int Q[N];

inline int find(int x){
    int tx=x,top=0;
    while (x!=fa[x]){
        Q[++top]=x;
        x=fa[x];
    }

    for(int i=1;i<=top;i++) fa[Q[i]]=x;
    return x;
}

inline void merge(int x,int y){
    x=find(x),y=find(y);

    if(sizes[x]<=sizes[y]) fa[x]=y,sizes[y]+=sizes[x];
    else fa[y]=x,sizes[x]+=sizes[y];
}

int main () {
    // scanf("%d %d", &n, &q);
    n=input(),q=input();
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sizes[i] = 1;
        vis[i] = 0;
    }
    int ans = 0;
    while (q--) {
        int op=input();
        int x, y;
        // scanf("%d", &op);
        if (op == 1) {
            // scanf("%d", &x);
            x=input();
            int fx = find(x);
            if (vis[fx]) {

            } else {
                vis[fx] = 1;
                ans += sizes[fx];
            }
            printf("%d\n", ans);
            // print(ans);
        } else {
            // scanf("%d %d", &x, &y);
            x=input(),y=input();
            int fx = find(x);
            int fy = find(y);
            if (vis[fx] && vis[fy]) {

            } else if (vis[fx] == 0 && vis[fy]) {
                ans += sizes[fx];
                vis[fx] = 1;
            } else if (vis[fy] == 0 && vis[fx]) {
                ans += sizes[fy];
                vis[fy] = 1;
            } else {
                if (fx != fy) {
                    merge(fx,fy);
                }
            }
            printf("%d\n", ans);
            // print(ans);

            

        }
    }
}