#include<bits/stdc++.h>
using namespace std;
const int N = 1007;

int t, n, m;
int dp[N], x[N], y[N];



int main() {
    scanf("%d", &t);
    while (t--) { 
        scanf("%d %d", &n, &m);
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &x[i], &y[i]);
            int cnt = m / (x[i]);
            if (m % (x[i])) cnt++;
           
            ans = min(ans, cnt * y[i]);

        }
        
        printf("%d\n", ans);

    }
}