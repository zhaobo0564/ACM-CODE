#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;


int t, a[N], b[N], n, fa[N];

int find(int x) {
    if (fa[x] != x) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

vector<int>g;
int  ranks[N], vis[N];

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1; 
}



int main() {
    scanf("%d", &t);
    int ca = 1;
    while (t--) {
        g.clear();
       scanf("%d", &n);
       for (int i = 1; i <= 2 * n; i++) {
           fa[i] = i;
           ranks[i] = 1;
           vis[i] = 0;


       }
       for (int i = 1; i <= n; i++) {
           scanf("%d %d", &a[i], &b[i]);
           g.push_back(a[i]);
           g.push_back(b[i]);
       }
       sort(g.begin(), g.end());
       g.erase(unique(g.begin(), g.end()), g.end());
       for (int i = 1; i <= n; i++) {
           a[i] = get_id(a[i]);
           b[i] = get_id(b[i]);
       }
       int ans = 0;
       for (int i = 1; i <= n; i++) {
           int fx = find(a[i]);
           int fy = find(b[i]);
           if (fx != fy) {
               fa[fx] = fy;
               ranks[fy] += ranks[fx];
               if (vis[fy] || vis[fx]) {
                   vis[fx] = 1;
                   vis[fy] = 1;
               }
           } else {
               vis[fx] = 1;
           }
       }
       for (int i = 1; i <= g.size(); i++) {
           int fy = find(i);
           if (vis[fy] == -1) continue;
           if (vis[fy] == 0) {
               ans += ranks[fy] - 1;
               vis[fy] = -1;
           } else {
               ans += ranks[fy];
               vis[fy] = -1;
           }
       }
       printf("Case #%d: %d\n", ca++, ans);
    }
}



