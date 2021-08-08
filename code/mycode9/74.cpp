#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e3 + 7;

ll dp[N][N][2], a[N], temp[N][2];
vector<int> g[N];

int n, t, sz[N];

void dfs(int u) {
    sz[u] = 1;
    for (int to: g[u]) {
        dfs(to);

        for (int i = 0; i <= sz[u] + sz[to]; i++) {
            temp[i][0] = temp[i][1] = 1e15;
        }
        for (int i = 0; i <= sz[u]; i++) {
            for (int j = 0; j <= sz[to]; j++) {
                temp[i + j][0] = min(temp[i + j][0], dp[u][i][0] + dp[to][j][0] + a[to]);
                if (j > 0)
                    temp[i + j][0] = min(temp[i + j][0], dp[u][i][0] + dp[to][j][1]);
                if (i > 0)
                    temp[i + j][1] = min(temp[i + j][1], dp[u][i][1] + dp[to][j][0]);
                if (i > 0 && j > 0)
                    temp[i + j][1] = min(temp[i + j][1], dp[u][i][1] + dp[to][j][1]);
            }
        }
        //cout << "U =  " << u << endl;
        for (int i = 0; i <= sz[u] + sz[to]; i++) {
            dp[u][i][0] = temp[i][0];
            dp[u][i][1] = temp[i][1];
          //  printf("dp[%d][%d][0] = %lld, dp[%d][%d][1] = %lld\n", u, i, dp[u][i][0], u, i, dp[u][i][1]);
        }
        //cout << endl;
        sz[u] += sz[to];

    }
    for (int i = 0; i <= sz[u]; i++) {
        dp[u][i][0] += a[u];
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            for (int j = 0; j <= n; j++) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
        for (int i = 2; i <= n; i++) {
            int x; scanf("%d", &x);
            g[x].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        dfs(1);
        for (int i = 0; i <= n; i++) {
            printf("%lld ", min(dp[1][i][0], dp[1][i][1]));
        }
        puts("");
    }
}