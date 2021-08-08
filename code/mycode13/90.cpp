#include<bits/stdc++.h>
using namespace std;

char mp[500][500];
int n;

bool judge() {
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (mp[i][j] == '*') {
                v.push_back({i, j});
            }
        }
    }
    if (v.size() != 4) return false;
    if (v[1].second - v[0].second == v[3].f - v[2].first && v[0].second == v[1].second && v[2].second == v[3].second) {
        if (v[2].second - v[0].second == v[3].second - v[1].second) {
            
                return true;
            
        }
    }
    return false;
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mp[i][j];
        }
        cout << endl;
    }
}

void solve() {
    cin >> n;
    int x = 0, y = 0, xx = 0, yy = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '*') {
                if (x == 0) x = i, y = j;
                else if (xx == 0) xx = i, yy = j;
            }
        }
    }
    if (y != yy) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i ==  x || j == xx) continue;
                mp[i][y] = '*';
                mp[j][yy] = '*';
                
                if (judge()) {
                    print();
                    return;
                }
                mp[i][y] = '.';
                mp[j][yy] = '.';
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == y || j == yy) continue;
                mp[x][i] = '*';
                mp[xx][j] = '*';
                if (judge()) {
                    print();
                    return;
                }
                mp[x][i] = '.';
                mp[xx][j] = '.';
            }
        }
    }
   
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
