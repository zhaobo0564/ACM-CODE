#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int vis[N], prime[N], top = 1, n, a[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

vector<int> g[N];
int color[N];

int main() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i] = i + 1;
        g[a[i]].push_back(i);
    }
    // for (int i = 1; i <= n; i++) {
    //     int x = a[i], maxn = -1;
    //     for (int j = 1; j < top; j++) {
    //         if (vis[x] == 0) break;
    //         if (x % prime[j] == 0) {
               
    //             while (x / prime[j] == 0) {
    //                 x = x / prime[j];
    //             }   
    //             for (int j: g[prime[j]]) {
    //                 if (j == i) continue;
    //                 maxn = max(maxn, color[j]);
    //             }
    //         }
    //     }
    //     if (x > 1) {
    //         for (int j: g[x]) {
    //             if (j == i) continue;
    //             maxn = max(maxn, color[j]);
    //         }
    //     }
    //     color[i] = maxn + 1;

    //}
    for (int i = 2; i <= n + 1; i++) {
        if (!vis[i]) color[i] = 1;
        else color[i] = 2;
    }
    int maxn = 0;
    for (int i = 2; i <= n + 1; i++) {
        maxn = max(maxn, color[i]);
    }
    cout << maxn << endl;
    for (int i = 2; i <= n + 1; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
    
}