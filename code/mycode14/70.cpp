#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int mp[N][N], n, m, k;

int work(int x, int y, int xx, int yy) {
    int ans = 0;
    for (int i = x; i <= xx; i++) {
        for (int j = y; j <= yy; j++) {
            ans = max(ans, mp[i][j]);
        }
    }
    return ans;
}

vector<int> g[N];
int top = 1;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (i + k - 1 > n) break;
        for (int j = 1; j <= m; j++) {
            if (j + k - 1 > m) break;
            int ans = work(i, j, i + k - 1, j + k - 1);
            g[top].push_back(ans);
        }
        top++;
    }
    cout << top - 1 << " " << g[top - 1].size() << endl;
    for (int i = 1; i < top; i++) {
        for (int j: g[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}