#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 7;

int prime[N], vis[N], top = 1;

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int ans[N];

vector<int> v;

int main() {
    init();
    ll l, r;
    while (~scanf("%lld %lld", &l, &r)) {
        for (ll i = l; i <= r + 1; i++) {
            ans[i - l] = 0;
        }
        for (int i = 1; i < top; i++) {
            int cnt = l / prime[i];
            if (cnt == 0) {
                cnt = 2;
            } else if (cnt == 1) {
                cnt = 2;
            }
            for (ll j = cnt * prime[i]; j <= r; j += prime[i]) {
                ans[j  - l] = 1;
            }
        }
        v.clear();
        for (ll i = l; i <= r; i++) {
            if (ans[i - l] == 0 && i != 1) {
                v.push_back(i);
            }
        }
        if (v.size() < 2) {
            cout << "There are no adjacent primes.\n";
        } else {
            int minn = INT_MAX, maxn = 0;
            for (int i = 1; i < v.size(); i++) {
                minn = min(minn, v[i] - v[i - 1]);
                maxn = max(maxn, v[i] - v[i - 1]);

            }
            for (int i = 1; i < v.size(); i++) {
                if (v[i] - v[i - 1] == minn) {
                    printf("%d,%d are closest, ", v[i - 1], v[i]);
                    break;
                }
            }
    
            for (int i = 1; i < v.size(); i++) {
                if (maxn == v[i] - v[i - 1]) {
                    printf("%d,%d are most distant.\n", v[i - 1], v[i]);
                    break;
                }
            }

        }
    }
}