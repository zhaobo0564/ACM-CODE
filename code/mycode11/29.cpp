#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int dp[N][N];
vector<int> g[N];
int d[N], a[N], temp[N], ans[N];
int n, m;
void dfs(int u) {
 //  cout << "u = " << u << endl;
    dp[u][1] = a[u];
    for (int to: g[u]) {
    //    cout << "to " << to << endl;
        
        dfs(to);
        memset(temp, 0, sizeof(temp));
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                if (i + j <= m) {
                    temp[i + j] = max(temp[i + j], dp[u][i] + dp[to][j]);
                    
                }
                
            }
        }
       // printf("AA %d\n", dp[u][1]);

        for (int i = 0; i <= m; i++) {
            dp[u][i] = temp[i];
           // printf("dp[%d][%d] = %d\n", u, i, dp[u][i]);
        }
    }
}

int main() {
   
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = v;
        d[i] = u;
        if (u == 0) continue;

        g[u].push_back(i);
    }
  //  cout << a[1] << endl;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            dfs(i);
      
            memset(temp, 0, sizeof(temp));
            // for (int j = 0; j <= m; j++) {
            //     printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            // }
            for (int k = 0; k <= m; k++) {
                for (int j = 0; j <= m; j++) {
                    temp[k + j] = max(temp[k + j], ans[k] + dp[i][j]);
                }
            }
            for (int j = 1; j <= m; j++) {
                ans[j] = temp[j];
            }
            
        }
    }
    cout << ans[m] << endl;
}
/*
8 5
0 2
1 8
1 2
2 1
3 15
2 1
0 10
0 100
*/