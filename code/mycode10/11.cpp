#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
const int maxn=1e3+10,MAXN=1e6+10;
int dfn[maxn],scc[maxn],scc_cnt,dfs_clock,low[maxn],inque[maxn];
int res[MAXN],x[MAXN],y[MAXN];
inline void read(int& x) {
    x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) {
        x=x*10+ch-'0';
        ch=getchar();
    }
}
vector<int> G[maxn],Edge[maxn];
bool vis[maxn][maxn],ans[maxn][maxn],v[maxn][maxn];
int n,m1,m2,q;
stack<int> S;
// void dfs(int u) {
//     S.push(u);
//     inque[u]=1;
//     low[u]=dfn[u]=++dfs_clock;
//     for (int i=0; i<G[u].size(); i++) {
//         int v=G[u][i];
//         if (!dfn[v]) {
//             dfs(v);
//             low[u]=min(low[u],low[v]);
//         } else if (inque[v]) low[u]=min(low[u],dfn[v]);
//     }
//     if (dfn[u]==low[u]) {
//         scc_cnt++;
//         while (true) {
//             int x=S.top();
//             S.pop();
//             scc[x]=scc_cnt;
//             inque[x]=0;
//             if (u==x) break;
//         }
//     }
// }
void find_scc() {
    dfs_clock=scc_cnt=0;
    memset(scc,0,sizeof(scc));
    memset(inque,0,sizeof(inque));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    while (!S.empty()) S.pop();
    for (int i=1; i<=n; i++) {
        if (!dfn[i]) dfs(i);
    }
}
void bfs(int x) {
    queue<int> Q;
    Q.push(x);
    ans[x][x]=true;
    while (!Q.empty()) {
        int u=Q.front();
        Q.pop();
        for (int i=0; i<Edge[u].size(); i++) {
            int v=Edge[u][i];
            if (ans[x][v]) continue;
            Q.push(v);
            ans[x][v]=true;
        }
    }
}
void solve() {
    find_scc();
    memset(vis,false,sizeof(vis));
    memset(ans,false,sizeof(ans));
    for (int i=1; i<=n; i++) Edge[i].clear();
    for (int i=1; i<=n; i++) {
        for (int j=0; j<G[i].size(); j++) {
            int u=scc[i],v=scc[G[i][j]];
            if (u==v) continue;
            if (vis[u][v]) continue;
            vis[u][v]=true;
            Edge[u].push_back(v);
        }
    }
    for (int i=1; i<=scc_cnt; i++) {
        bfs(i);
    }
}
int main() {
    read(n),read(m1),read(m2),read(q);
    for (int i=1; i<=m1; i++) {
        int a,b;
        read(a);
        read(b);
        v[a][b]=true;
        G[a].push_back(b);
    }
    for (int i=1; i<=m2; i++) {
        int a,b;
        read(a);
        read(b);
        v[a][b]=true;
    }
    solve();
    for (int i=1; i<=q; i++) {
        read(x[i]);
        read(y[i]);
        if (ans[scc[x[i]]][scc[y[i]]]) res[i]=true;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j||v[i][j]) continue;
            G[i].push_back(j);
        }
    }
    solve();
    for (int i=1; i<=q; i++) {
        if (res[i]) printf("Yes ");
        else printf("No ");
        if (ans[scc[x[i]]][scc[y[i]]]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
