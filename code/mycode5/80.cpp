#include<bits/stdc++.h>
using namespace std;

const int N = 207;

int a[N], b[N], n, m, dp[N];

vector<int> g[N];

void work(int v[], int x) {
    int cn = 0;
    for (int i = 0; i < 11; i++) v[i] = 0;
    while (x) {
        if (x & 1) {
            v[cn] = 1;
        }
        cn++;
        x = x / 2;
    }
}

bool judge(int x[], int y[]) {
    for (int i = 0; i < 11; i++) {
        if (x[i] == 0) {
            if (y[i]) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i].push_back((a[i] & b[j]));
        }
       
    }
    int ans = 0;
    for (int i = 0; i <= 1024; i++) {
     
        int ok = 0;
        int vis[11];
        work(vis, i);
        for (int j = 1; j <= n; j++) {
            int f = 0;
            for (int z = 0; z < g[j].size(); z++) {
                int cnt[11];
                work(cnt, g[j][z]);
                if(judge(vis, cnt)) {
                    f = 1;
                    ok++;
                    break;
                }

            }
            if (f == 0) break;

        }
        if (ok == n) {
            ans = i;
            break;
        }
    }  
    printf("%d\n", ans);
  

}