#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
typedef long long ll;
char a[N], b[N];
ll c[N];
int n;

vector<ll> v;

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }
    scanf("%s %s", a + 1, b + 1);
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '1') {
            sum += c[i];
        }
        if (a[i] == '1' && a[i] == b[i]) {
            v.push_back(c[i]);
        }
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    ll ans = 0;
    while (1) {
        int f = 0;
        int maxn = 0, pos = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == '1' && a[i] != b[i]) {
                if (maxn < c[i]) {
                    maxn = c[i];
                    pos = i;
                }
            }
        }
        if (pos == -1) break;
        sum -= maxn;
        ans += sum;
        a[pos] = b[pos];
    }

    while (1) {
        int f = 0;
        ll minn = 1e10, pos = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == '0' && a[i] != b[i]) {
                if (minn > c[i]) {
                    minn = c[i];
                    pos = i;
                }
            }
        }
        if (pos == -1) break;
        sum += minn;
        ans += sum;
        a[pos] = b[pos];

    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll res = ans;
    ll t = 1;
    for (int i = 0; i < v.size(); i++) {
        ll cnt = ans - cnt * v[i];
        sum += v[i] * t;
        cnt = cnt + sum;
        res = min(res, cnt);
        t++;
    }
    cout << ans << endl;
}

