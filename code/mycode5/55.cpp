#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 7;

int n, dp[N];

struct node{
    int a, b;
}p[N];

bool cmp1(node x, node y) {
    return x.a < y.a;
}

bool cmp2(node x, node y) {
    return x.b < y.b;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }
    int ans = 0;
    sort(p + 1, p + n + 1, cmp1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[j].b > p[i].b) {
                dp[j] = max(dp[i] + 1, dp[j]);
                ans = max(dp[j], ans);
            }
            
        }
    }
    sort(p + 1, p + n + 1, cmp2);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[j].a > p[i].a) {
                dp[j] = max(dp[i] + 1, dp[j]);
                ans = max(dp[j], ans);
                
            }
        }
    }
    cout << ans << endl;

}