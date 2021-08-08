#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
const ll mod = 1e9 + 7;
ll base = 17;
ll ha[N], p[N];
char s[N];
int n, k;

void init() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        ha[i] = ha[i - 1] * base % mod + s[i];
        p[i] = p[i - 1] * base % mod;
    }
}

ll get_ha(int l, int r) {
    return (ha[r] - ha[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

map<ll, int> vis;

vector<int> g[N];
int top = 1;

bool judge(int x) {
    vis.clear();
    for (int i = 1; i < top; i++) {
        g[i].clear();
    }
    top = 1;
    for (int i = 1; i <= n; i++) {
        int l = i, r = i + x - 1;
        if (r > n) break;
        ll cnt = get_ha(l, r);
     //   cout << "cnt " << cnt << endl;
        if (vis[cnt] == 0) {
            vis[cnt] = top++;
        }
        g[vis[cnt]].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i < top; i++) {
        int last = -1e8;
        ans = 0;
        for (int j: g[i]) {
            if (j - last >= x) {
                last = j;
                ans++;
            }
        }
        if (ans >= k) return true;
    }
    return false;
}



int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    init();
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (judge(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
   
    printf("%d\n", ans);

    return 0;
}