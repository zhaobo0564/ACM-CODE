#include <bits/stdc++.h>

using namespace std;

const int N = 507;
typedef long long ll;
const ll mod = 1e9 + 7;

int mp[N][N], n, k;

ll ans = 1;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int vis[N][N];

bool judge(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) {
        return false;
    }
    return true;
}

vector<pair<int, int> > v;
int bfs(int x, int y) {
    queue<pair<int, int> >q;
    q.push({x, y});
    int ans = 0;
    while (q.size()) {
        auto it = q.front();
        q.pop();
        if (vis[it.first][it.second]) continue;
        vis[it.first][it.second] = 1;
        ans++;
        v.push_back({it.first, it.second});
        for (int i = 0; i < 4; i++) {
            int nx = it.first + dx[i];
            int ny = it.second + dy[i];
            if (judge(nx, ny) && mp[nx][ny]) {
                q.push({nx, ny});
            }            
        }
    }
    return ans;
}

int fa[N * N], sz[N * N], cat[N][N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

void merge(int fx, int fy) {
    if (fx == fy) return;
    fa[fx] = fy;
    sz[fy] += sz[fx];
}

ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x =  x * x % mod;
        y = y / 2;
    }
    return base % mod;
}

ll fn[N * N];




int main() {
    int top = 1;
    fn[0] = 0;
    fn[1] = 1;
    for (int i = 2; i < N * N; i++) {
        fn[i] = fn[i - 1] * i % mod;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &mp[i][j]);
            cat[i][j] = top++;
            fa[top - 1] = top - 1;
            sz[top - 1] = 1;
        }
    }
    int cnt = 0;
  

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] == 0 && mp[i][j]) {
                v.clear();
                cnt++;
                ans = ans * bfs(i, j) % mod;
                for (int k = 1; k < v.size(); k++) {
                    int fy = find(cat[v[k - 1].first][v[k - 1].second]);
                    int fx = find(cat[v[k].first][v[k].second]);
                    merge(fx, fy);
                }

            }
        }
    }
 
  //cout << "A\n";
   //cout << "ans " << ans << " " << cnt << endl;
   

    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        x++, y++;
        
        
        if (mp[x][y] == 0) {
            if (mp[x + 1][y]) {
                int fy = find(cat[x][y]);
                int fx = find(cat[x + 1][y]);
                if (fx != fy) {
                     ans = ans * ksm(sz[fy], mod - 2) % mod;
                    ans = ans * ksm(sz[fx], mod - 2) % mod; 
                    merge(fx, fy);
                    fx = find(cat[x][y]);
                    ans = ans * sz[fx] % mod;
                }
               
            } else {
                cnt++;
            }
            mp[x][y] = 1;
        } else {
            cout << ans * fn[cnt] % mod << endl;
            continue;
        }

        if (mp[x][y]) {
            if (mp[x - 1][y]) {
                
                int fy = find(cat[x][y]);
                int fx = find(cat[x - 1][y]);
                if (fx != fy) {
                    ans = ans * ksm(sz[fy], mod - 2) % mod;
                    ans = ans * ksm(sz[fx], mod - 2) % mod;
                
                    merge(fx, fy);
                    fx = find(fx);
                    ans = ans * sz[fx] % mod;
                    cnt--;
                }
               
            } 

            if (mp[x][y - 1]) {
                int fy = find(cat[x][y]);
                int fx = find(cat[x][y - 1]);   
                if (fx != fy) {
                     ans = ans * ksm(sz[fy], mod - 2) % mod;
                    ans = ans * ksm(sz[fx], mod - 2) % mod;  
                
                //  cout << "szx= " << sz[fx] << " szy = " << sz[fy] << endl;
                    merge(fx, fy);
                    fx = find(fx);
                    ans = ans * sz[fx] % mod;
                // cout << "szz " << sz[fx] << " ans = " << ans << endl;
                    cnt--;
                }
             //   cout << "ans = " << ans << endl;
               
            } 
            if (mp[x][y + 1]) {
                int fy = find(cat[x][y]);
                int fx = find(cat[x][y + 1]);
                if (fx != fy) {
                    ans = ans * ksm(sz[fy], mod - 2) % mod;
                    ans = ans * ksm(sz[fx], mod - 2) % mod;
                    merge(fx, fy);
                    fx = find(fx);
                    ans = ans * sz[fx] % mod;
                    cnt--;
                }
                
            } 
        }
       // cout << "ans = " << ans <<  " cnt = " << cnt << endl;
        ll res = ans * fn[cnt] % mod;
        cout << res << endl;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << mp[i][j];
        //     }
        //     cout << endl;
        // }


    


    }
}
