#include<bits/stdc++.h>
using namespace std;
 
#define N 5000
#define INF 100000000
struct Edge {
    int from,to,cap,flow;
};
 
struct ISAP {
    int n,m,s,t;   // n���� m����, s��㣬tԴ�㡣
    vector<Edge>edges;
    vector<int>G[N];
    bool vis[N];
    int d[N],cur[N];
    int p[N],num[N];//��Dinic�㷨�������������飬p�����Ǹ��׽�㣬num�����Ǿ���d[i]���ڼ���
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
                x=s;//�����ص�Դ��
            }
            int ok=0;
            for(int i=cur[x];i<G[x].size();i++) {
                Edge&e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1) {
                    ok=1;
                    p[e.to]=G[x][i];//��¼����ʱ���ߵıߣ�������
                    cur[x]=i;
                    x=e.to;//ǰ��
                    break;
                }
            }
            if(!ok) {
                int m=n-1;//���û�л�����ôm+1����n����d[i]=n
                for(int i=0;i<G[x].size();i++) {
                    Edge&e=edges[G[x][i]];
                    if(e.cap>e.flow)
                        m=min(m,d[e.to]);
                }
                if(--num[d[x]]==0)break;//����߲����ˣ����������ֵԭ��ֻ��һ������ôs-t����ͨ���������ν�ġ�gap�Ż���
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s)
                    x=edges[p[x]].from;//��һ�������Ÿ��߷���
            }
        }
        return flow;
    }
};
int main() {
    ISAP isap;
    int x;
    cin >> isap.n >> isap.m >> x;
    for (int i = 1; i <= isap.m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        isap.addedge(u, v, w);
    }
    int ans = isap.Maxflow(1, isap.n);
    if (ans > 0) {
        cout << ans <<" " << x / ans + (x % ans == 0? 0 : 1)<< endl;
    } else {
        cout << "Orz Ni Jinan Saint Cow!\n";
    }
    
    
}
 
 