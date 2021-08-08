#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
char s[N];
int n;

ll nxt[N][200];
ll vis[200];

int main() {
    scanf("%s", (s + 1));
    int n = strlen(s + 1);
    for (int i = 'a'; i <= 'z'; i++) {
        vis[i] = n + 1;
    }
    for (ll i = n; i; i--) {
        for (int j = 'a'; j <= 'z'; j++) {
            nxt[i][j] = vis[j];
        }
        vis[s[i]] = i;
    }
    memset(vis, 0, sizeof(vis));
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll l = i - vis[s[i]] - 1, r = nxt[i][s[i]] - i;
     //   cout << l << " " << r << endl;
        ans +=l + r;
        if (r > 1) {
            ans += l * (r - 1);
        }
        vis[s[i]] = i;
    }
    cout << ans << endl;
    
}