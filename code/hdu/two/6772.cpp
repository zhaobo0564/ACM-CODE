#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100;

int t, n, k;

struct node {
    ll a, b, c, d;
};

vector<node>p[100];
vector<int>v;

ll ans;

void dfs(int pos, ll a, ll b, ll c, ll d) {
    
    if (pos >= v.size()) {
       ll cnt = (a + 100) * (b + 100) * (c + 100) * (d + 100);
       ans = max(ans, cnt);
       return; 
    }
    
    for (int i = 0; i < p[v[pos]].size(); i++) {
        dfs(pos + 1, a + p[v[pos]][i].a, b + p[v[pos]][i].b, c + p[v[pos]][i].c, d + p[v[pos]][i].d);
    }

}

int main() {
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        v.clear();
        scanf("%d %d", &n, &k);
        for (int i = 0; i <= k; i++) {
            p[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            ll t, a, b, c, d;
            scanf("%lld %lld %lld %lld %lld", &t, &a, &b, &c, &d);
            p[t].push_back({a, b, c, d});
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        dfs(0, 0, 0, 0, 0);
        printf("%lld\n", ans);

    }
}