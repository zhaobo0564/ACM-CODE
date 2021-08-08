#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
int a[N], n, t, p;
unordered_map<ll, int>vis;

stack<int>q;

int main() {
    scanf("%d", &t);
    while (t--) {
        vis.clear();
        scanf("%d %d", &n, &p);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        ll sum = 0;
        vis[0] = 1;
        for (int i = 1; i <= n; i++) {
            sum += 1ll*a[i];
           // cout << sum % p << " " << vis[sum % p] << endl;
            if (vis[sum % p]) {
             //   cout << sum % p << endl;
                ans++;
                sum = 0;
                vis.clear();
                vis[0] = 1;
            } else {
                vis[sum % p] = 1;
            }

        }
        printf("%d\n", ans);
    }
}


