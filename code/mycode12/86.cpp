#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int vis[N], top = 1, prime[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    int n; 
    init();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < top; i++) {
        vis[prime[i]] = 1;
    }
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i < top; i++) {
            if (n > prime[i]) {
                if (vis[n - prime[i]]) {
                    cout << n << " = " << min(prime[i], n - prime[i]) << " + " << max(prime[i], n - prime[i]) << endl;
                    break; 
                }
            }
        }
    }  
    
}