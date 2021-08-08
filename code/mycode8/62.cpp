#include<bits/stdc++.h>
using namespace std;

const int N = 107;

int mp[N][N], n, m;

void work(int x, int y) {
    if (mp[x][y] == mp[x + 1][y] && mp[x][y] == mp[x][y + 1] && mp[x][y] == mp[x + 1][y + 1]) {
        mp[x][y]++;
        mp[x + ]
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &mp[i][j]);
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                
            }
        }


    }
}