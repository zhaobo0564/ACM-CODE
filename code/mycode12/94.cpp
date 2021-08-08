#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 7;

ll a0, a1, b0, b1;
int vis[N], prime[N], top = 1;

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

vector<pair<int, int> >g;
ll ans = 0;

ll lcm(ll x, ll y) {
    return x * y / __gcd(x, y);
}

void dfs(int p, ll sum) {
    if (p >= g.size()) {
       // cout << sum << endl;
        if (lcm(sum, b0) == b1 && __gcd(sum, a0) == a1) {
           // cout << sum << endl;
            ans++;
        }
        return;
    }

    
    ll cnt = 0;
    for (int j = 0; j <= g[p].second; j++) {
        if (j == 0) {
            cnt = 1;
        } else {
            cnt = cnt * 1ll*g[p].first;
        }
        dfs(p + 1, sum * cnt);
    }
    

}

int main()  {
    init();
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        g.clear();
        scanf("%lld %lld %lld %lld", &a0, &a1, &b0, &b1);
        ll x = b1;
        for (int i = 1; prime[i] <= x / prime[i]; i++) {
           // if (x < prime[i] || !vis[x]) break;
            if (x % prime[i] == 0) {
                int ct = 0;
                while (x % prime[i] == 0) {
                    x = x / prime[i];
                    ct++;
                }
                g.push_back({prime[i], ct});
            }
            
        }
        if (x > 1) {
            g.push_back({x, 1});
        }
     
        
        ans = 0;
        dfs(0, 1);
        cout << ans << endl;
    }
}