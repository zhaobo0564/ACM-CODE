#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;

bool vis[N];
int prime[N], top = 1;
void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

vector<pair<int, int> > ans;

bool judge(int x) {
    for (int i = 0; i < ans.size(); i++) {
        int cnt = 0;
        long long base = ans[i].first;
        for (int j = 1; j <= ans[i].second; j++) {
         
            cnt += x /  base;
            base = base * ans[i].first;
        }
        if (cnt < ans[i].second) {
            return false;
        }
    }
    return true;
}

void solve() {
    ans.clear();
    int k; scanf("%d", &k);
    int x = k;
    for (int i = 1; i < top; i++) {
        if (!vis[x] || prime[i] > x) break;
        if (x % prime[i] == 0) {
            int cnt = 0;
            while (x % prime[i] == 0) {
                x = x / prime[i];
                cnt++;
            }
            ans.push_back({prime[i], cnt});
        }
    }
    if (x > 1) {
        ans.push_back({x, 1});
    }
    int l = 1, r = k, res = 1;;
    while (l <= r) {
        int m = (l + r) / 2;
        if (judge(m)) {
            r = m - 1;
            res = m;
        } else {
            l = m + 1;
        }
    }
    printf("%d\n", res);

}

int main() {
    init();
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}