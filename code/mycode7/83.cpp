#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 7;
int mp[N][N];
ll  h[N], cnt[N][N] ,lmin[N], rmin[N];
ll sum[N][N];

stack<int> q;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &mp[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % j == 0 || j % i == 0) {
                cnt[i][j]++;
                
                
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] += sum[i - 1][j] + 1ll * cnt[i][j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == 0) {
                h[j] = 0;
            } else {
                h[j]++;
            }
        }

        for (int j = 1; j <= n; j++) {
            while (!q.empty() && h[j] < h[q.top()]) {
                lmin[q.top()] = j;
                q.pop();
            }
            q.push(j);
        }
        while (!q.empty()) {
            lmin[q.top()] = n + 1;
            q.pop();
        }

        for (int j = n; j; j--) {
            while (!q.empty() && h[j] <= h[q.top()]) {
                rmin[q.top()] = j;
                q.pop();
            }
            q.push(j);
        }
        while (!q.empty()) {
            rmin[q.top()] = 0;
            q.pop();
        }

        for (int j = 1; j <= n; j++) {
            int len = lmin[j] - rmin[j] - 1;
            int l1 = j - rmin[j];
            int l2 = lmin[j] - j;
            ll cat = sum[l1 + l2 - 1][h[j]] - sum[l1 - 1][h[j]] - sum[l2 - 1][h[j]];
            ans += cat;

        }
        

    }
    printf("%lld\n", ans);

    

}