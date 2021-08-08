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
int ans[N];

int main() {
    int n; cin >> n;
    init();
    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 1; j < top; j++) {
            if (!vis[x]) break;
            if (x % prime[j] == 0) {
                int cnt = 0;
                while (x % prime[j] == 0) {
                    x = x / prime[j];
                    cnt++;
                }
                ans[prime[j]] += cnt;
            }
        }
        if (x > 1) {
            ans[x] += 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            cout << i << " " << ans[i] << endl;
        }
    }
}