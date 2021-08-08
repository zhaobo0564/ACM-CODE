#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int vis[100], prime[100], top = 1;

void init() {
    for (int i = 2; i < 50; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < 50; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll ans = 0, res;

void dfs(int p, ll sum, ll cnt) {
    if (p >= 10) {
        if (cnt > ans) {
            ans = cnt;
            res = sum;
        } else if (cnt == ans) {
           // cout << sum << endl;
            res = min(res, sum);
        }
        return; 
    }
    //dfs(p + 1, sum, cnt * (ct + 1), 0);
  
    ll ct = 1;
    for (int j = 0; j <= 40; j++) {
        if (j == 0) {
            ct = 1;
        } else {
            ct = ct * prime[p];
        }
        if (sum * ct > n) return;
        dfs(p + 1, sum * ct, cnt * 1ll * (j + 1));
    }
        
        

    
}

int main() {
    init();
    cin >> n;
    dfs(1, 1, 1);
    cout << res << endl;
}