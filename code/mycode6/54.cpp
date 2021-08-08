#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int dp[N][10];

vector<int> g[N];

bool work(int x, int y, int n) {
    int cnt = 0;
    int xx = x, yy = y;
    if (n == 2) {
        for (int i = 0; i < 2; i++) {
            if (x & 1) {
                cnt++;
            }
            if (y & 1) {
                cnt++;
            }
            x = x / 2, y = y / 2;
        }
        if (cnt % 2 == 0) return false;
        return true;
    } else {
         for (int i = 0; i < 2; i++) {
            if (x & 1) {
                cnt++;
            }
            if (y & 1) {
                cnt++;
            }
            x = x / 2, y = y / 2;
        }
        if (cnt % 2 == 0) return false;
        xx /= 2, yy /= 2;
        cnt = 0;
        for (int i = 0; i < 2; i++) {
            if (xx & 1) {
                cnt++;
            }
            if (yy & 1) {
                cnt++;
            }
            xx = xx / 2, yy = yy / 2;
        }
        if (cnt % 2 == 0) return false;
        return true;
    }

}

int count(int x, int y, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (g[i + 1][x] == (y & 1)) {

        } else {
            cnt++;
        }
        y = y / 2;
    }
    return cnt;
}

int m;

int dfs(int p, int sum, int n) {

    if (p > m) {
        return 0;
    }
    if (dp[p][sum] != -1) return dp[p][sum];

    int ans = 1e9;
    for (int i = 0; i < (1 << n); i++) {
        if(work(sum, i, n)) {
            ans = min(ans, dfs(p + 1, i, n) + count(p, i, n));
        }
    }

    return dp[p][sum] = ans;

}

int main() {
    int n; scanf("%d %d", &n, &m);
    if (m < n) {
        swap(n, m);
    } 
    for (int i = 1; i <= n; i++) {
        g[i].push_back(0);
        for (int j = 1; j <= m; j++) {
            int x; scanf("%1d", &x);
            g[i].push_back(x);
        }
    }

    int cnt = min(n, m);
    if (cnt > 3) {
        puts("-1");
    } else {
        if (n == 1) {
            int cnt = 0;
           
            cout << cnt << endl;
        } else {
            memset(dp, -1, sizeof(dp));
            int ans = 1e9;
            for (int i = 0; i < (1 << n); i++) {
                ans = min(ans, dfs(2, i, n) + count(1, i, n));
            }
            printf("%d\n", ans);
        }

    }
}