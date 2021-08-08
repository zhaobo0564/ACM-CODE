#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
typedef long long ll;

ll a[N], n, cnt[N], res[N];
int vis[N];

vector<ll> ans;

void work(int p, int sum) {
    if (p > n) return;
    if (a[p] <= 0) {
        work(p + 1, sum);
    } else if (a[p] - (p - sum - res[p]) <= 0) {
      //  cout << "p " << p << " ans " << a[p] << endl;
        ans.push_back(p);
        a[p] = 0;
        work(p + 1, sum + 1);
    } else {
        a[p] = a[p] - (p - (sum+ res[p]));
        work(p + 1, sum);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll nn = n;
    for (int i = 1; i <= n; i++) {
        int top = 1;
        for (int j = 1; j <= n; j++) {
            res[j] = 0;
        }
        for (int j = 1; j <= n; j++) {
            if (a[j] <= 0) res[j] = 1;
        }
        for (int j = 1; j <= n; j++) {
            res[j] += res[j - 1];
        }
        for (int j = 1; j <= n; j++) {
            if (a[j] <= 0) continue; 
            cnt[j] = a[j] / top;
            if (a[j] % top) cnt[j]++; 
            top++;
        }
        ll minn = LLONG_MAX, pos;
        for (int j = 1; j <= n; j++) {
            if (a[j] <= 0) continue;
            if (minn > cnt[j]) {
                minn = cnt[j];
                pos = j;
            } 
        }
        for (int j = 1; j <= pos; j++) {
            if (a[j] <= 0) continue;
            a[j] -= minn * (j - res[j]);
        }
        for (int j = pos + 1; j <= n; j++) {
            if (a[j] <= 0) continue;
            a[j] -= (minn - 1) * (j - res[j]);
        }
        ans.push_back(pos);
        work(pos + 1, 1);
        a[pos] = 0;
        if (ans.size() == n) break;
    }
    for (ll i: ans) {
        cout << i << " ";
    }
    cout << endl;
}
