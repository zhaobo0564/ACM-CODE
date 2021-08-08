#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 11007;

ll n, k, p[N], c[N], sum[N];

int vis[N];

vector<ll>g[N];

deque<int> q;

ll hello[N];

ll work(int x, int cnt) {
    while (q.size()) q.pop_front(); 
    for (int i = 1; i <= x; i++) {
        while (!q.empty() && sum[q.back()] >= sum[i]) {
            q.pop_back();
        }
        q.push_back(i);
        while (q.front() <= i - cnt) {
            q.pop_front();
        }
        if (q.front() == i) {
            hello[i] = sum[i - 1];
        } else {
            hello[i] = sum[q.front()];
        }
        
    }
    ll mx1 = LLONG_MIN;
    for (int i = 1; i <= x; i++) {
        mx1 = max(mx1, sum[i] - sum[max(0, i - cnt)]);

        mx1 = max(mx1, sum[i] - hello[i]);
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
            cnt += c[g[i][j]];
            sum[j + 1] = c[g[i][j]];
        }
    
        int cn = (int)g[i].size();
        for (int j = 1; j <= cn; j++) {
            sum[j + cn] = sum[j];
        }
        for (int j = 1; j <= 2 * cn; j++) {
            sum[j] = sum[j - 1] + sum[j];
        }
        if (cnt > 0) {
            ll res = k / cn;
            ll cat = res * cnt;
            res = k % cn;
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