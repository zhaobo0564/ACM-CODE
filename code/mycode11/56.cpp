#include<bits/stdc++.h>

using namespace std;

int n, k, X[20], Y[20], r[20], R;

vector<pair<int,int> >v;

int dist(pair<int, int> x, pair<int, int> y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int vis[15];

int work(int x, int y) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d = dist({x, y}, {X[i], Y[i]});
        if (vis[i] == 0 && d <= (r[i] + R) * (r[i] + R)) {
            vis[i] = 1;
            ans++;
        }
    }
    return ans;
}

int maxn = 0;

void dfs(int k) {
    if (k == 0) {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (auto it: v) {
            ans += work(it.first, it.second);
        }
        maxn = max(ans, maxn);
        return;
    }
    for (int i = -7; i <=7; i++) {
        for (int j = -7; j <= 7; j++) {
            v.push_back({i, j});
            dfs(k - 1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> k >> R;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i] >> r[i];
    }
    dfs(k);

    cout << maxn << endl;

}