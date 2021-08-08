#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5007;

ll n, k, p[N], c[N], sum[N];

int vis[N];

vector<ll>g[N];

ll tree[8 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(ll v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node] = v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node] = min(tree[lson], tree[rson]);

}


ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = LLONG_MAX;
    if (ql <= m) ans = min(ans, query(ql, qr, l, m, lson));
    if (qr > m) ans = min(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

ll work(int x, int cnt) {
    for (int i = 1; i <= x; i++) {
        update(sum[i], i, 1, x, 1);
    }
    ll mx1 = LLONG_MIN;
    for (int i = 1; i <= x; i++) {
        int l =max(1, i - cnt + 1);
        if (i - 1 >= l) {
             ll res = query(l, i - 1, 1, x, 1);
            mx1 = max(mx1, sum[i] - res);
        }
       
        mx1 = max(mx1, sum[i] - sum[max(0, i - cnt)]);
        
    }
    return mx1;
}

void dfs(int id, int u) {
    vis[u] = 1;
    g[id].push_back(u);
    if (vis[p[u]] == 0) {
        dfs(id, p[u]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int top = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(top, i);
            top++;
        }
    }
    ll maxn = LLONG_MIN;
    for (int i = 1; i < top; i++) {
        ll cnt = 0;
        for (int j = 0; j < g[i].size(); j++) {
            //cout << g[i][j] << " ";
            cnt += c[g[i][j]];
            sum[j + 1] = c[g[i][j]];
        }
      //  cout << endl;
    
        int cn = (int)g[i].size();
        for (int j = 1; j <= cn; j++) {
            sum[j + cn] = sum[j];
        }
        for (int j = 1; j <= 2 * cn; j++) {
            sum[j] = sum[j - 1] + sum[j];
        }
        if (cnt > 0) {
            ll res = k / cn;
           // cout << "res " << res << " cnt " << cnt << endl;
            ll cat = res * cnt;
            res = k % cn;
          //  cout << "res1 " << res << endl;
            ll ca = cat;
            if (res) {
                cat += work(2 * cn, res);
                maxn = max(maxn, cat);
            } 
            cat = ca;
            cat -= cnt;
            cat += work(2 * cn, cn);
            maxn= max(maxn, cat);
            
            
        } 
        if (k >= cn) {
            maxn = max(maxn, work(2 * cn, cn));
        } else {
            maxn = max(maxn, work(2 * cn, k));
        }

    }
    cout << maxn << endl;
}
/*9 7876
4 2 5 1 6 8 3 7 9 
-6557 -2648 -2420 25613 4314 25455 -6418 -2334 -763 */
/*

3 1670
1 3 2 
-10082 20147 -12332 
*/