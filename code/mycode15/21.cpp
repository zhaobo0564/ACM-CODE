#include<bits/stdc++.h>
using namespace std;
const int N = 5007;
typedef long long ll;
int n, m, mp[N][N];

int h[N][N], l[N], r[N];

stack<int> q;

ll ans = 0;
int vis[N][N];

void solve(int id) {
    for (int i = 1; i <= n; i++) {
        l[i] = r[i] = 0;
    }
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++) {
        while (q.size() && h[id][q.top()] > h[id][i]) {
            l[q.top()] = i;
            q.pop();
        }    
        q.push(i);
    }
    while (q.size()) l[q.top()] = n + 1, q.pop();
    for (int i = n; i; i--) {
        while (q.size() && h[id][q.top()] > h[id][i]) {
            r[q.top()] = i;
            q.pop();
        }
        q.push(i);
    }
    while (q.size()) r[q.top()] = 0, q.pop();
    cout << "id = " << id << endl;
    for (int i = 1; i <= n; i++) {
        ll R = l[i] - 1;
        ll L = r[i] + 1;
        L = max(L, 1ll*vis[L][R]);
        cout << "L = "<< L << " R = " << R << endl;
        cout << "h = " << h[id][i] << endl;
        ll cnt = 1ll * (i - L + 1) * 1ll * (R - i) + (i - L + 1); 

        vis[L][R] = i + 1;
        cout << " cnt " << cnt << endl;
        ans += cnt * 1ll * h[id][i];
     //  cout << " ans = " << ans << endl;
    }
    for (int i = 1; i <= n; i++) {
        vis[r[i] + 1][l[i] - 1] = 0;
    }

}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        mp[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            h[i][j] = mp[i][j] ^ 1;
        }
        for (int j = 1; j <= n; j++) {
            if (h[i][j]) {
                h[i][j] = h[i - 1][j] + h[i][j];
            } else {
                h[i][j] = 0;
            }
            
        }
    }

    for (int i = 1; i <= 1; i++) {
        solve(i);
    }
    printf("%lld\n", ans);
    return 0;
}