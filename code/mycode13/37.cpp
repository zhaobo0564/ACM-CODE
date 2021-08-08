#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int s, n, money[N];

vector<vector<pair<int, int> > >g;

int mp[N], need[N];
int top = 0, dp[110][6][6][6][6][6];

int dfs(int p, int a, int b, int c, int d, int e) {
    if (p >= top) {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
            return 0;
        }
        return 1e8;
    }
    if (dp[p][a][b][c][d][e] != -1) return dp[p][a][b][c][d][e];
    int ans = 1e8;
    int A = a, B = b, C = c, D = d, E = e;
    for (int i = 1; i <= 5; i++) {
        A = a, B = b, C = c, D = d, E = e;
        for (int j = 0; j < g[p].size(); j++) {
            int id = g[p][j].first, k = g[p][j].second;
            if (mp[id] == 1) {
                A = a - i * k;
            } else if (mp[id] == 2) {
                B = b - i * k;
            } else if (mp[id] == 3) {
                C = c - i * k;
            } else if (mp[id] == 4) {
                D = d - i * k;
            } else if (mp[id] == 5) {
                E = e - i * k;
            } 
        }
        ans = min(ans, dfs(p + 1, max(A, 0), max(B, 0), max(C, 0), max(D, 0), max(E, 0)) + i * money[p]);
    }
    ans = min(ans, dfs(p + 1, a, b, c, d, e));
    return dp[p][a][b][c][d][e] = ans;

}

int main() {
    cin >> s;
    for (int i = 1; i <= s; i++) {
        int n; cin >> n;
        vector<pair<int, int> >v;
        for (int j = 1; j <= n; j++) {
            int c, k;
            cin >> c >> k;
            v.push_back({c, k});
        }
        int p; cin >> p;
        money[top++] = p;
        g.push_back(v);
    }
    int b; cin >> b;
    for (int i = 1; i <= b; i++) {
        int c, k, p;
        cin >> c >> k >> p;
        vector<pair<int, int> > v;
        mp[c] = i;
        need[i] = k;
        v.push_back({c, 1});
        g.push_back(v);
        money[top++] = p;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, need[1], need[2], need[3], need[4], need[5]) << endl;
    return 0;
}