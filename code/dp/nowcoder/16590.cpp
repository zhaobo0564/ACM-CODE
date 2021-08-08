#include<bits/stdc++.h>
using namespace std;

const int N = 400;

int a[N], b[N], n, m, dp[400][41][41][41];

int dfs(int p, int one, int two, int three, int four) {
    int ans = 0;
    if (dp[p][one][two][three] != -1) return dp[p][one][two][three];
    if (one) {
        ans = max(ans, dfs(p + 1, one - 1, two, three, four) + a[p + 1]);
    } 
    if (two) {
        ans = max(ans, dfs(p + 2, one, two - 1, three, four) + a[p + 2]);
    } 
    if (three) {
        ans = max(ans, dfs(p + 3, one, two, three - 1, four) + a[p + 3]);
    }
    if (four) {
        ans = max(ans, dfs(p + 4, one, two, three, four - 1) + a[p + 4]);
    }
    return dp[p][one][two][three] = ans;

}


int main() {
  
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int one = 0, two = 0, three = 0, four = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        if (b[i] == 1) one++;
        else if (b[i] == 2) two++;
        else if (b[i] == 3) three++;
        else four++;
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(1, one, two, three, four) + a[1];
    printf("%d\n", ans);



}