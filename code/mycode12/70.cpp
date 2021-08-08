#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;

int n, m, w, a[N], c[N], fa[N], sum[N], v[N];
int dp[N];

vector<int> g;

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main() {
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &c[i]);
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            fa[fx] = fy;
        }
    }
    for (int i = 1; i <= n; i++) {
        int fx = find(i);
        g.push_back(fx);
        sum[fx] += a[i];
        v[fx] += c[i];
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
  
    for (int i: g) {
        for (int j = w; j >= 0; j--) {
    
            if (j >= sum[i]) {
             
                dp[j] = max(dp[j], dp[j - sum[i]] + v[i]); 
            }
           
        }
    }
    cout << dp[w] << endl;
    return 0;
}