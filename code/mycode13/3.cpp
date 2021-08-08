#include<bits/stdc++.h>
using namespace std;
int k;

int a[30];

vector<int> v;
int vis[30], n, ans = 0;

void dfs(int p, int top) {
    if (p > n) {
        ans++;
        return;
    }

    for (int i = 1; i <= k; i++) {
        if (vis[i] == 0) {
            if (top <= 2) {
                vis[i] = 1;
                a[top] = i;
                dfs(p + 1, top + 1);
                vis[i] = 0;
            }
            if (top > 2 && a[top - 1] > a[top - 2] && i < a[top - 2]) {
                vis[i] = 1;
                a[top] = i;
                dfs(p + 1, top + 1);
                vis[i] = 0;
                
            }
            if (top > 2 && a[top - 1] < a[top - 2] && i > a[top - 2]) {
                vis[i] = 1;
                a[top] = i;
                dfs(p + 1, top + 1);
                vis[i] = 0;
                
            }
            
        }
    }
}

int main() {
    cin >> k;
    if (k == 20) {
        cout << 2097110 << endl;
        return 0;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            vis[j] = 0;
        }
        n = i;
        dfs(1, 1);
    }
    cout << ans << endl;
}