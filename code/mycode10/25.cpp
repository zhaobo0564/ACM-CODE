#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

int fa[N], vis[N], sz[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

vector<int> g;

int main() {
    for (int i = 1; i < N; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        int fx = find(x), fy = find(y);
        g.push_back(x);
        g.push_back(y);
        if (fx != fy) {
            fa[fx] = fy;
            sz[fy] += sz[fx];
            if (vis[fx] || vis[fy]) {
                vis[fx] = 1;
                vis[fy] = 1;
            }
        } else {
            vis[fx] = 1;
            
        }
    }
    int ans = 0;
    for (int i: g) {
        int fx = find(i);
        if (vis[fx] == -1) continue;
      
        if (vis[fx] == 1) {
            ans += sz[fx];
        } else {
            ans += sz[fx] - 1;
        }  
        vis[fx] = -1;
    }
    cout << ans << endl;
    
    


}