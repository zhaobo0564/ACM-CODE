#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 7;

int vis[N], prime[N], top = 1;

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve() {
   int n; scanf("%d", &n);
   for (int i = 1; i < top; i++) {
       int cnt = n - prime[i];
       if (vis[cnt] == 0) {
           printf("%d %d\n", prime[i], cnt);
           return;
       }
   }
}

int main() {
    init();
    vis[0] = vis[1] = 1;
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}