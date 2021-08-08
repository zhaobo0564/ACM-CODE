#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;

int top = 1, prime[N], vis[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

vector<pair<int, int> > ans;

void solve() {
    ans.clear();
    int k; scanf("%d", &k);
    int f = 0;
    for (long long i = 2; i * i < k; i++) {
        if (k % i == 0) {
            f = 1;
            break;
        }
    }
    if (f == 0 || k == 1) {
        printf("%d\n", k);
    } else {
        for (int i = 1; i < top; i++) {
            if (vis[k] == 0 || k < prime[i]) {
                break;
            }
            if (k % prime[i] == 0) {
                int cnt = 0;
                while (k % prime[i] == 0) {
                    k = k / prime[i];
                    cnt++;
                }
                ans.push_back({prime[i], cnt});
            }
        }
        if (k > 1) {
            ans.push_back({k, 1});
        }
        sort(ans.begin(), ans.end());
      //  cout << ans.size() << endl;
        int pos = 0;
        long long x = 1, r = 2;
        while(1) {
            if (x % ans[pos].first == 0) {
                int cnt = 0, cn = ans[pos].second;
                while(x % ans[pos].first == 0 && cn) {
                    x = x / ans[pos].first;
                    cnt++;
                    cn--;
                }
    
                if (cn == 0) {
                    pos++;
                } else {
                    ans[pos].second -= cnt;
                }
                if (ans[pos].second == 0) {
                    pos++;
                }
            }
            if (pos >= ans.size()) {
                printf("%d\n", r - 1);
                return;
            }
            if (x % ans[pos].first == 0) {
                
            } else {
                x = x * r;
                r++;
            }
        }
    }
}

int main() {
    init();
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}