#include<bits/stdc++.h>
using namespace std;

const int N = 2000;

bitset<N> mp[N], mp1[N];

int vis[N][N];

int main() {
    int n, m1, m2, q;

    cin >> n >> m1 >> m2 >> q;
    for (int i = 1; i <= m1; i++) {
        int x, y; cin >> x >> y;
        mp[x][y] = 1;
    }

    for (int i = 1; i <= m2; i++) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) mp[i][j] = 1;
            if (mp[j][i]) {
                mp[j] |= mp[i];
            }
            if (vis[i][j] == 0) {
                mp1[i][j] = 1;
            } 
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp1[i][j]) mp1[i][j] = 1;
            if (mp1[j][i]) {
                mp1[j] |= mp1[i];
            }
        }
    }
    while (q--) {
        int x, y; cin >> x >> y;
        if (mp[x][y]) {
            printf("Yes ");
        } else {
            printf("No ");
        }
        if (mp1[x][y]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    
    
}