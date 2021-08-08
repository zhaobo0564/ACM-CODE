
#include<bits/stdc++.h>
using namespace std;
 
#define N 5000
#define INF 100000000
struct Edge {
    int from,to,cap,flow;
};
 
struct ISAP {
    int n,m,s,t;   // n个点 m条边, s起点，t源点。
    vector<Edge>edges;
    vector<int>G[N];
    bool vis[N];
    int d[N],cur[N];
    int p[N],num[N];//比Dinic算法多了这两个数组，p数组标记父亲结点，num数组标记距离d[i]存在几个
    void addedge(int from,int to,int cap) {
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
 
    int Augumemt() {
        int x=t,a=INF;
        while(x!=s) {
            Edge&e=edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=edges[p[x]].from;
        }
        x=t;
        while(x!=s) {
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;
            x=edges[p[x]].from;
        }
        return a;
    }
    void bfs() {
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(t);
        d[t]=0;
        vis[t]=1;
        while(!q.empty()) {
            int x=q.front();q.pop();
            int len=G[x].size();
            for(int i=0;i<len;i++) {
                Edge&e=edges[G[x][i]];
                if(!vis[e.from]&&e.cap>e.flow) {
                    vis[e.from]=1;
                    d[e.from]=d[x]+1;
                    q.push(e.from);
                }
            }
        }
    }
 
    int Maxflow(int s,int t) {
        this->s=s;
        this->t=t;
        int flow=0;
        bfs();
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
            num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n) {
            if(x==t) {
                flow+=Augumemt();
                x=s;//增广后回到源点
            }
            int ok=0;
            for(int i=cur[x];i<G[x].size();i++) {
                Edge&e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1) {
                    ok=1;
                    p[e.to]=G[x][i];
                    cur[x]=i;
                    x=e.to;
                    break;
                }
            }
            if(!ok) {
                int m=n-1;
                for(int i=0;i<G[x].size();i++) {
                    Edge&e=edges[G[x][i]];
                    if(e.cap>e.flow)
                        m=min(m,d[e.to]);
                }
                if(--num[d[x]]==0)break;
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s)
                    x=edges[p[x]].from;
            }
        }
        return flow;
    }
};
int main() {
    ISAP isap;
    cin >> isap.n >> isap.m;

    int s, t;
    cin >> s >> t;
    for (int i = 1; i <= isap.n; i++) {
        isap.addedge(i, isap.n + i, 1);
    }
    for (int i = 1; i <= isap.m; i++) {
        int u, v;
        cin >> u >> v;
      //  isap.addedge(u, u + isap.n, 1);
        isap.addedge(u + isap.n, v, 1e9);
        //isap.addedge(v, v + isap.n, 1);
        isap.addedge(v + isap.n, u, 1e9);


    }
    isap.n += isap.n;

    int ans = isap.Maxflow(s, t);
    cout << ans << endl;
    
}