#include<bits/stdc++.h>
using namespace std;

int mp[200][200], n, m;

void dfs(int x, int y, int ans, int f) {
    
    if (f == 1) {
        if (mp[x][y + 1] == 0) {
            mp[x][y + 1] = ans;
            dfs(x, y + 1, ans + 1, f);
        } else if (mp[x + 1][y] == 0){
            dfs(x, y, ans, 2);
        }
    } else if (f == 2) {
        if (mp[x + 1][y] == 0) {
            mp[x + 1][y] = ans;
            dfs(x + 1, y, ans + 1, f);
        } else if (mp[x][y - 1] == 0){
            dfs(x, y, ans, 3);
        }
    } else if (f == 3) {
        if (mp[x][y - 1] == 0) {
            mp[x][y - 1] = ans;
            dfs(x, y - 1, ans + 1, f);
        } else if (mp[x - 1][y] == 0){
            dfs(x, y, ans, 4);
        }
    } else if (f == 4) {
        if (mp[x - 1][y] == 0) {
            mp[x - 1][y] = ans;
            dfs(x - 1, y, ans + 1, f);
        } else if (mp[x][y + 1] == 0){
            dfs(x ,y, ans, 1);
        }
    }
   
}

int main() {
    cin >> n >> m;
    int x = 1, y = 1, ans = 1;
    int fx = 0, fy = 1;
    for (int i = 0; i <= n + 1; i++) {
        mp[i][0] = 1;
        mp[i][m + 1] = 1;
    }
    for (int i = 0; i <= m + 1; i++) {
        mp[0][i] = 1;
        mp[n + 1][i] = 1;
    }
    mp[1][1] = 1;
    dfs(1, 1, 2, 1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    
}