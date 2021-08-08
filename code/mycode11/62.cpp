#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, m;

struct edge{
    int u, v, w;
}e[N];

int vis[N], cnt[N];

vector<int> g[N];

queue<pair<int, int> >q;

bool bfs(int s) {
    while (q.size()) q.pop();
    q.push({s, 0});
    while (q.size()) {
        auto it = q.front();
        q.pop();
        if (vis[it.first]) {
            if (cnt[it.first] != it.second) {
                return false;
            }
            continue;
        }
        if (cnt[it.first] == -1) {
            cnt[it.first] = it.second;
        } else {
            if (cnt[it.first] != it.second) {
                return false;
            }
        }
        
        vis[it.first] = 1;
        for (int to: g[it.first]) {
            q.push({to, it.second ^ 1});
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     if (cnt[i] == 0) {
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;
    return true;
}

bool judge(int x) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        cnt[i] = -1;
        g[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        if (e[i].w > x) {
            g[e[i].u].push_back(e[i].v);
            g[e[i].v].push_back(e[i].u);
        }
    }


    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (!bfs(i)) {
                return false;
            }
        }
    }
    return true;
    

}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    int l = 0, r = 1e9, ans = 0;
   // judge(0);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        
    }
    cout << ans << endl;
    
}