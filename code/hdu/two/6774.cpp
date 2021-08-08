#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int t, n, m, nxt[N][200], vis[200], dp[300][300];

char a[N], b[30];

int main() {

    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", (a + 1),  (b + 1));
        int la = strlen(a + 1), lb = strlen(b + 1);
        for (int i = 'a'; i <= 'z'; i++) vis[i] = la + 10;
        for (int i = la; i; i--) {
           
            for (int j = 'a'; j <= 'z'; j++) {
                nxt[i][j] = vis[j];
            } 
            vis[a[i]] = i;
        }
        for (int j = 'a'; j <= 'z'; j++) nxt[0][j] = vis[j];
        int q; scanf("%d", &q);
        while (q--) {
            int l, r; scanf("%d %d", &l, &r);
            for (int i = 0; i <= lb; i++) {
                for (int j = 0; j <= lb; j++) {
                    dp[i][j] = 1e8;
                }
            }
            dp[0][0] = l - 1;
            for (int i = 1; i <= lb; i++) {
                dp[i][0] = l - 1;
                for (int j = 1; j <= i; j++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                    if (dp[i - 1][j -  1] <= r &&nxt[dp[i - 1][j - 1]][b[i]] <= r) {
                        dp[i][j] = min(dp[i][j], nxt[dp[i - 1][j - 1]][b[i]]);
                    }
                }
            }
            for (int i = lb; i >= 0; i--) {
               if (dp[lb][i] <= r) {
                   printf("%d\n", (r - l + 1 + lb) - 2 * i);
                   break;
               }
            }
        }

    }
}