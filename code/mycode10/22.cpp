#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int mp[N][N], n, m;
typedef long long ll;
int vis[N][N];
queue<pair<int, int> > q;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

const ll mod = 1e9 + 7;

#define pb push_back

const int maxsz=3e5+7;
const ll mood=1e9+7;

template<typename key,typename val>
class hash_map{
public:
  struct node{key u;val v;int next;};
  vector<node> e;
  int head[maxsz],nume,numk,id[maxsz];
  int geths(pair<ll,ll> &u){
    int x=(1ll*u.first*mood+u.second)%maxsz;
    if(x<0) return x+maxsz;
    return x;
  }
  val& operator[](key u){
    int hs=geths(u);
    for(int i=head[hs];i;i=e[i].next)if(e[i].u==u) return e[i].v;
    if(!head[hs])id[++numk]=hs;
    if(++nume>=e.size())e.resize(nume<<1);
    return e[nume]=(node){u,0,head[hs]},head[hs]=nume,e[nume].v;
  }
  void clear(){
    for(int i=0;i<=numk;i++) head[id[i]]=0;
    numk=nume=0;
  }
};

hash_map<pair<ll, ll>, int >vi;

int ans = 0;

void bfs(int s, int t) {
    while (q.size()) q.pop();
    q.push({s, t});
    ll hashx = 0, hashy = 0, base = 17;
    vis[s][t] = 1;
    while (q.size()) {
        auto cd = q.front();
        q.pop();
        hashx = (hashx * base % mod + cd.first - s + 1) % mod;
        hashy = (hashy * base % mod + cd.second - t + 1) % mod;
        
        for (int i = 0; i < 4; i++) {
            int nx = cd.first + dx[i];
            int ny = cd.second + dy[i];
            if (vis[nx][ny] == 0 && mp[nx][ny] == 1 && nx > 0 && ny > 0 && nx <= n && ny <= m) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (vi[{hashx, hashy}] == 0) {
        ans++;
        vi[{hashx, hashy}] = 1;
    }

}

int main() {
    while (~scanf("%d %d", &n, &m) && n && m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%1d", &mp[i][j]);
                vis[i][j] = 0;
            }
        }
        vi.clear();
        ans = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis[i][j] == 0 && mp[i][j] == 1) {
                    bfs(i, j);
                    res++;
                }
            }
        }
        printf("%d %d\n", res, ans);
    }

}