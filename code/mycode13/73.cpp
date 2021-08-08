#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int p[N], n;

int vis[N];

vector<int> g[N];

vector<pair<int, int> > ans[N];

int pos[N];

int main() {
    scanf("%d", &n);
    int ok = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        if (p[i] != i) {
            ok = 1;
        }
        pos[p[i]] = i;
    }
    if (ok == 0) {
        cout << 0 << endl;
        return 0;
    }
    int top = 0;
    for (int i = 1; i <= n; i++) {
        int a = p[i];
        if (vis[a] == 0) {
            top++;
        }
        while (vis[a] == 0) {
            g[top].push_back(pos[a]);
            vis[a] = 1;
            a = p[a];
        }
    
    }


    int o = 1;
    int f = 0;
    for (int i = 1; i <= top; i++) {
        if (g[i].size() == 1) continue;
        if (g[i].size() == 2) {
            ans[o].push_back({g[i][0], g[i][1]});
            swap(g[i][0], g[i][1]);
        } else {
            f = 1;
            ans[o].push_back({g[i][0], g[i][1]});
            swap(g[i][0], g[i][1]);
            int l = 2, r = g[i].size() - 1;
            while (l < r) {
                ans[o].push_back({g[i][l], g[i][r]});
                swap(g[i][l], g[i][r]);
                l++, r--;
            }
        }
    }
    if (f == 0) {
        cout << 1 << endl;
        cout << ans[o].size() << " ";
        for (int i = 0; i < ans[o].size(); i++) {
            cout << ans[o][i].first << " " << ans[o][i].second << " ";
           // swap(p[ans[o][i].first], p[ans[o][i].second]);
        }
        cout << endl;
    } else {
        o++;
        for (int i = 1; i <= top; i++) {
            if (g[i].size() > 2) {
                int l = 1, r = g[i].size() - 1;
                while (l < r) {
                    ans[o].push_back({g[i][l], g[i][r]});
                    swap(g[i][l], g[i][r]);
                    l++, r--;
                }
            }
        }
        cout << 2 << endl;
        for (int i = 1; i <= 2; i++) {
            cout << ans[i].size()  << " ";
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j].first << " " << ans[i][j].second << " ";
               // swap(p[ans[i][j].first], p[ans[i][j].second]);
            }
            cout << endl;
        }
        cout << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << p[i] << " ";
    // }
    // cout << endl;

    return 0;


}