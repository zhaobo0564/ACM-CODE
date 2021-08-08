#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll t[300], x[300], y[300], n, m;

struct node {
    ll v, h;
};

queue<node> q;
int dist[N][207];
bool vis[N][207];

ll gao(double x) {
    ll y = (ll)x;
    if (x - y >= 0.00000001) {
        return y + 1;
    }
    return y;
}

void bfs() {
    q.push({0, 1});
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n + 2; j++)
            dist[i][j] = 1e8;
    }
    dist[0][1] = 0;
    while (q.size()) {
        node cd = q.front();
        q.pop();
      //  cout << cd.v << endl;
        if (cd.h > n) continue;
        if (vis[cd.v][cd.h]) continue;
        vis[cd.v][cd.h] = 1;
        ll cnt = cd.v;
        if (dist[cnt][cd.h + 1] > dist[cd.v][cd.h] + 1) {
            dist[cnt][cd.h + 1] = dist[cd.v][cd.h] + 1; 
            q.push({cnt, cd.h + 1});
        }
        

        for (ll i = 1; i <= y[cd.h]; i++) {
            if (t[cd.h] == 1) {
                ll X = x[cd.h];
                ll Y = (x[cd.h] + 99999) / 100000;
                
                cnt = Y + cnt;
                if (cnt > m) break;
             //   cout << "CNt = " << cnt << endl;
               // cout << dist[cnt][cd.h + 1] << " " << dist[cd.v][cd.h] + 1 << endl;
                if (dist[cnt][cd.h + 1] > dist[cd.v][cd.h] + 1) {
                 
                    dist[cnt][cd.h + 1] = dist[cd.v][cd.h] + 1;
                
                    q.push({cnt, cd.h + 1});
                }
            } else {
                ll X = x[cd.h];
                cnt = (cnt * X + 99999) / 100000;
                if (cnt > m) break;
                if (dist[cnt][cd.h + 1] > dist[cd.v][cd.h] + 1) {
                    dist[cnt][cd.h + 1] = dist[cd.v][cd.h] + 1;
                
                    q.push({cnt, cd.h + 1});
                }

            }
        }
    }
}

int main() {
    //srand(time(0));
    scanf("%lld %lld", &n, &m);
    //n = 200, m = 100000;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &t[i], &x[i], &y[i]);
    //    t[i] = rand()% 2 + 1;
    //    x[i] = rand() % 100000 + 1;
    //    x[i] = x[i] * m;
    //    y[i] = rand() % m + 1;
    }
    bfs();
    for (int i = 1; i <= m; i++) {
        int ans = 1e8;
        for (int j = 1; j <= n + 1; j++) {
            ans = min(ans, dist[i][j]);
        }
        if (ans > 1e7) {
            printf("-1 ");
        } else {
            printf("%d ", ans);
        }
    }
    puts("");
}
