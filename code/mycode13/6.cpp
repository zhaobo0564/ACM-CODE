#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;



int n, m, c[N], a[N][N], len[N];

int vis[N];

vector<int> v;

bool ok() {
    int f = 0;
    for (int i = 1; i <= m; i++) {
        if (!c[i]) {
            int pos = 1;
            for (int j = 0; j < v.size(); j++) {
                if (pos <= len[i] && a[i][pos] == v[j]) {
                    pos++;
                }
            }
            if (pos > len[i]) return false;
            continue;
        } 
        int pos = 1;
        for (int j = 0; j < v.size(); j++) {
            if (pos <= len[i] && a[i][pos] == v[j]) {
                pos++;
            }
        }
        if (pos <= len[i]) return false;
    }
    return true;
}

vector<vector<int> >g;

void dfs(int p) {
    if (p > n) {
        // for (int i: v) {
        //     cout << i << " ";
        // }
        // cout << endl;
        if (ok()) {
            g.push_back(v);
        }

        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            v.push_back(i);
            dfs(p + 1);
            vis[i] = 0;
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> len[i];
        for (int j = 1; j <= len[i]; j++) {
            cin >> a[i][j];
        }
        cin >> c[i];
    }
 
    dfs(1);
    cout << g.size() << endl;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }






}

