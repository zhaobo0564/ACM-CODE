// ISAP 可以达的 o(n^3)
#include<bits/stdc++.h>
using namespace std;
#define int long long
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


int n, a[N], b[N], m;

int32_t main() {
    ios::sync_with_stdio(0); 
     cin >> n;
    int s = n + 1, t = n + 2, sum = 0;
  
    ISAP isap;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        isap.addedge(s, i, a[i]);
        sum += a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        isap.addedge(i, t, b[i]);
        sum += b[i];
    }
    cin >> m;
    int top = t + 1;
    for (int i = 1; i <= m; i++) {
        int c1, c2, k; cin >> k >> c1 >> c2;
        
        sum += c1 + c2;
        isap.addedge(s, top++, c1);
        isap.addedge(top++, t, c2);
        for (int j = 1; j <= k; j++) {
            int u; cin >> u;
            isap.addedge(top - 2, u, 1e14);
            isap.addedge(u, top - 1, 1e14);
        }

    }
    isap.n = top - 1;
    int ans = isap.Maxflow(s, t);
   // cout << ans << endl;
    cout << sum - ans << endl;
    
    
}
 
 