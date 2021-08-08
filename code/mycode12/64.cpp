#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
const ll mod = 998244353;


int n, a[N];
vector<int>g[N];

int dfn[N], flow[N], cnt, vis[N];
stack<int>q;

//int cat[N], top = 1;
 ll ans = 0;

void tarjan(int u){
    dfn[u] = flow[u] = ++cnt;
    vis[u] = 1;
    q.push(u);
    for(int to: g[u]){
        if(!dfn[to]){
            tarjan(to);
            flow[u] = min(flow[u], flow[to]);
        }else if(vis[to]){
            flow[u] = min(flow[u], dfn[to]);
        }
    }


    if(flow[u] == dfn[u]){
        int f = 0;
        while(1){
            f++;
            int now = q.top();
            q.pop();
            vis[now] = 0;  // now为强连通
            if(now == u)break;
        }
        if (f > 1) {
            ans++;
        }
       // top++;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == i) {
            ans++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != a[i])
            g[i].push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    ll res = 1;
    for (int i = 1; i <= ans; i++) {
        res = res * 2 % mod;
    }
    res = (res - 1 + mod) % mod;
    cout << res << endl;
}