#include<bits/stdc++.h>
using  namespace std;

const int N = 100;

vector<int> g[N];

int vis[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            g[i].push_back(x);
            vis[i][x]++;
        }
    }

    
    while (1) {
        int count = 1, small = 0;
        for (int i = 1; i <= 3; i++) {
            int f = 0;
            for (int j = 1; j <= m; j++) {
                if (vis[i][j] >= count && j > small) {
                    vis[i][j] -= count;
                    small = j;
                    f = 1;
                    break;
                } 
            }
            if (f == 0) {
                for (int j = 1; j <= m; j++) {
                    if (vis[i][j] > count) {
                        vis[i][j] -= count;
                        vis[i][j] -= 1;
                        small = j;
                        count = count + 1;
                        f = 1;
                        break;
                    }
                }
            }
            int ok = 0;
            for (int j = 1; j <= m; j++) {
                if (vis[i][j]) {
                    ok = 1;
                }
            }
            if (ok == 0) {
                cout << i << endl;
                return 0;
            }
        }
    }

}