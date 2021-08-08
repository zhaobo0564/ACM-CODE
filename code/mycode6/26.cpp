#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 207;
#define pb push_back
#define fi first
#define se second

int n, m, t, vis[N][N];

ll mp[N][N];

char s[N][N];
const ll INF=0x3f3f3f3f;
ll dis[N][N];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

struct node{
    int x, y, d;
};

bool judge(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > m) {
        return false;
    }
    return true;
}
typedef pair<int,int> P;
const int M=(1<<16)+5,X=205;

int d[X][X];

int bfs(P x,P y){
    queue<P>q;
    memset(d,INF,sizeof d);
    d[x.fi][x.se]=0;
    q.push(x);
    while(!q.empty()){
        P t=q.front();q.pop();
        for(int i=0;i<4;++i){
            int nx=t.fi+dx[i],ny=t.se+dy[i];
            if(!(nx>0 && nx<=n && ny>0 && ny<=m && s[nx][ny]!='#'))continue;
            if(d[nx][ny]==INF){
                d[nx][ny]=d[t.fi][t.se]+1;
                P nex=P(nx,ny);
                if(nex==y)return d[nx][ny];
                q.push(nex);
            }
        }
    }
    return INF;
}


vector<pair<int, int> >v;
int cnt;
ll dp[20][1000000];

ll dfs(int p, int sum) {
    if (p == 0) {
        if (sum == (1 << (cnt)) - 1) {
            return 0;
        }
        return 1e7;
    }
    if (dp[p][sum] != -1) return dp[p][sum];
    ll ans = 1e7;
    for (int i = 0; i < cnt; i++) {
        if (sum & (1 << i)) continue;
        ans = min(ans, dfs(i, sum | (1 << i)) + dis[p][i]);
    }
    return  dp[p][sum] = ans;
}


int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
      
        for (int j = 1; j <= m; j++) {
             scanf(" %c", &s[i][j]);
            if (s[i][j] == 'S')  {
                v.push_back({i, j});
            }
        } 
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'T') {
                v.push_back({i, j});
            }
        }
    }
    cnt = v.size();

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
           dis[j][i] = dis[i][j] = bfs(v[i], v[j]);

        }
       
    }

    
    int c = cnt;
    memset(dp, -1, sizeof(dp));
    
    ll ans = 1e7;
  for (int i = 1; i < cnt; i++) {
       ans = min(ans, dfs(i,  (1 << i)) + dis[0][i]);
    }
    if (ans > 10000) {
        cout << "-1\n";
    } else {
         cout << ans + 1ll * t * 1ll  *(cnt - 1) << endl;
    }   
    
    
    
}