#include<bits/stdc++.h>
using namespace std;
const int N = 4e6 + 7;

typedef long long ll;

int head[N], n, m, x, st, en;

char a[N];

ll dist[N];
int vis[N], top = 1, cnt;

pair<int, int> cat[N];


struct edge {
    int to, nxt;
    ll w;
}e[2 * N];

struct node {
    int v;
    ll w;
    node(){};
    node (int v, ll w) {
        this->v = v;
        this->w = w;
    }
    bool operator < (const node cd) const {
        return w > cd.w;
    } 
};


void add_edge(int u, int v, ll w) {
    e[top].to = v;
    e[top].w = w;
    e[top].nxt = head[u];
    head[u] = top++;
}
priority_queue<node> q;

void dj(int s) {
    q.push(node(s, 0));
    for (int i = 1; i <= cnt + 1; i++) {
        dist[i] = 1e16;
        vis[i] = 0;
    }
    dist[s] = 0;
    while (q.size()) {
        node cd = q.top();
        q.pop();
        if (vis[cd.v]) continue;
        vis[cd.v] = 1;
        for (int i = head[cd.v]; i; i = e[i].nxt) {
            int to = e[i].to;
            ll cost = e[i].w;
            if (a[to] == a[cd.v]) {
                if (dist[to] > dist[cd.v] + cost) {
                    dist[to] = dist[cd.v] + cost;
                    q.push(node(to, dist[to]));
                }
            } else {
                if (dist[to] > dist[cd.v] + cost + x) {
                    dist[to] = dist[cd.v] + cost + x;
                    q.push(node(to, dist[to]));
                }
            }
        }
       
    }
}



int main() {
    int t; scanf("%d", &t);
    while (t--) {
        top = 1;
        scanf("%d %d %d %d %d", &n, &m, &st, &en, &x);
          for (int i = 0; i <= n; i++) {
            cat[i].first = 0;
            cat[i].second = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf(" %c", &a[i]);
        }
        cnt =  n + 1;
        for (int i = 1; i <= m; i++) {
            int u, v;
            ll w;
            scanf("%d %d %lld", &u, &v, &w);
            if (a[u] == 'M' && a[v] == 'M') {
                if (cat[u].first && cat[v].first) {

                } else if (cat[u].first) {
                    cat[v].first = cnt;
                    cat[v].second = cnt + 1;
                    a[cnt] = 'L';
                    a[cnt + 1] = 'R';
                    cnt  += 2; 
                } else if (cat[v].first) {
                    cat[u].first = cnt;
                    cat[u].second = cnt + 1;
                    a[cnt] = 'L';
                    a[cnt + 1] = 'R';
                    cnt  += 2;
                } else {
                    cat[v].first = cnt;
                    cat[v].second = cnt + 1;
                    a[cnt] = 'L';
                    a[cnt + 1] = 'R';
                    cnt  += 2; 
                    cat[u].first = cnt;
                    cat[u].second = cnt + 1;
                    a[cnt] = 'L';
                    a[cnt + 1] = 'R';
                    cnt  += 2;
                }

                add_edge(cat[u].first, cat[v].first, w);
                add_edge(cat[u].first, cat[v].second, w);
                add_edge(cat[u].second, cat[v].first, w);
                add_edge(cat[u].second, cat[v].second, w);
                add_edge(cat[v].first, cat[u].first, w);
                add_edge(cat[v].first, cat[u].second, w);
                add_edge(cat[v].second, cat[u].first, w);
                add_edge(cat[v].second, cat[u].second, w);

                
            } else if (a[u] == 'M') {
                
                if (cat[u].first) {
                    add_edge(cat[u].first, v, w);
                    a[cat[u].first] = 'L';
                    add_edge(v, cat[u].first, w);
                    a[cat[u].second] = 'R';
                    add_edge(cat[u].second, v, w);
                    add_edge(v, cat[u].second, w);
                } else {
                    cat[u].first = cnt;
                    cat[u].second = cnt + 1;
                    add_edge(cat[u].first, v, w);
                    a[cat[u].first] = 'L';
                    add_edge(v, cat[u].first, w);
                    a[cat[u].second] = 'R';
                    add_edge(cat[u].second, v, w);
                    add_edge(v, cat[u].second, w);
                    cnt += 2;
                }
               
            } else if (a[v] == 'M') {
                if (cat[v].first) {
                    add_edge(cat[v].first, u, w);
                    a[cat[v].first] = 'L';
                    add_edge(u, cat[v].first, w);
                    a[cat[v].second] = 'R';
                    add_edge(cat[v].second, u, w);
                    add_edge(u, cat[v].second, w);
                } else {
                    cat[v].first = cnt;
                    cat[v].second = cnt + 1;
                    add_edge(cat[v].first, u, w);
                    a[cat[v].first] = 'L';
                    add_edge(u, cat[v].first, w);
                    a[cat[v].second] = 'R';
                    add_edge(cat[v].second, u, w);
                    add_edge(u, cat[v].second, w);
                    cnt += 2;
                }
            }else if (a[u] != 'M' && a[v] != 'M') {
                add_edge(u, v, w);
                add_edge(v, u, w);
            }
            
        }
        
        if (cat[st].first) {
            ll ans = 0; 
            dj(cat[st].first);
            if (cat[en].first) {
                ans = min(dist[cat[en].first], dist[cat[en].second]);
            } else {
                ans = dist[en];
            }
       
            dj(cat[st].second);
            if (cat[en].first) {
                ans = min(ans ,min(dist[cat[en].first], dist[cat[en].second]));
            } else {
                ans = min(ans, dist[en]);
            }
             printf("%lld\n", ans);
        } else {
            dj(st);
            if (cat[en].first) {
                printf("%lld\n", min(dist[cat[en].first], dist[cat[en].second]));
            } else {
                printf("%lld\n", dist[en]);
            }
            
            
        }
        for (int i = 0; i <= top; i++) {
                head[i] = 0;
        }
        
      
    }
}

/*
1
5 5 1 5 100
MLRML
1 2 10
1 3 10
3 4 8
2 4 10
4 5 1
*/

