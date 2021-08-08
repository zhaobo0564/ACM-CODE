#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e4 + 7;

int prime[N],vis[N],top=1;
int n, x[N], p[N];

int cat[N][200];

vector<int> g[N];

void Prime(){
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}


int main() {
    ios::sync_with_stdio(0);
    Prime();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < top; i++) {
        vis[prime[i]] = 1;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        int cnt = x[i];
        for (int j = 1; j < top; j++) {
            if (cnt < prime[j] || vis[cnt]) break;
            if (cnt % prime[j] == 0) {
                while (cnt % prime[j] == 0) {
                    cnt = cnt / prime[j];
                 //   cout << prime[j] << endl;
                    cat[i][prime[j]]++;
                }
                
            }
        }
        if (cnt > 1) {
            if (cnt < 200) {
                cat[i][cnt]++;
            } else {
                g[i].push_back(cnt);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    ll ans = 1;
    for (int j = 1; j < top; j++) {
        ll minn = 1e8;
        for (int i = 1; i <= n; i++) {
            if (vis[x[i]]) {
                if (prime[j] == x[i]) {
                    minn = min(minn, 1ll*p[i]);
                } else {
                    minn = 0;
                }
            } else if (prime[j] < 200){
                int cnt = cat[i][prime[j]];
             //   cout << "prime " << prime[j] << " " << cat[x[i]][prime[j]] << endl;
                minn = min(minn, 1ll*cnt * p[i]);
            } else {
                if (g[x[i]].size() && g[i][0] == prime[j]) {
                    minn = min(minn, 1ll*p[i]);
                } else {
                    minn = 0;
                }
            }
        }
      //  cout <<prime[j] << " " << minn << endl;
        if (minn < 1e7) {
            ans = ans * ksm(prime[j], minn) % mod;
        }
    }

    cout << ans << endl;

    


}