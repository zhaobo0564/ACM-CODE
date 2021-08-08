#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
typedef long long ll;
int n, m;
char s[N], t[N];

#define  ul unsigned long long 
const ul mod = 998765432109871;
const ul base = 47;
vector<ll> g;

ll mul(ll x, ll y) {
    ll sum = 1;
    while (y) {
        if (y & 1) {
           sum = (sum + x) % mod; 
        }
        y = y / 2;
        x = (x + x) % mod;
    }
    return sum;
}

unordered_map<ll, int> vis;

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", s + 1, t + 1);
    for (int i = 1; i <= m; i++) {
        ul sum = 0;
        for (int j = i; j <= m; j++) {
            sum = sum * base + t[j];
            vis[sum] = 1;
        }
    }
    // sort(g.begin(), g.end());
    // g.erase(unique(g.begin(), g.end()), g.end());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        for (int j = i; j <= n; j++) {
            sum = sum * base + s[j];
          //  int p = lower_bound(g.begin(), g.end(), sum) - g.begin();
            if (vis[sum] == 0) ans++;
        }
    }
    printf("%d\n", ans);
}