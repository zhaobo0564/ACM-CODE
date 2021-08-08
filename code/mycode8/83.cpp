#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
int mp[200][200], cat[200][200];

struct node {
    int a, b, c, d, e, f;
};

vector<node >ans;

void work(int x, int y) {
    int cnt = 0;
    if (mp[x][y] && mp[x + 1][y] && mp[x][y + 1] && mp[x + 1][y + 1]) {
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
        ans.push_back({x, y, x, y + 1, x + 1, y + 1}); // 1 2 4
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
    } else if (mp[x][y] && mp[x + 1][y] && mp[x][y + 1]) {
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
    } else if (mp[x][y] && mp[x][y + 1] && mp[x + 1][y + 1]) {
        ans.push_back({x, y, x, y + 1, x + 1, y + 1}); // 1 2 4
    } else if (mp[x][y] && mp[x + 1][y] && mp[x + 1][y + 1]) {
        ans.push_back({x, y, x + 1, y, x + 1, y + 1}); // 1 3 4
    } else if (mp[x][y + 1] && mp[x + 1][y + 1] && mp[x + 1][y]) {
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
    } else if (mp[x][y] && mp[x][y + 1]) {
        ans.push_back({x, y, x + 1, y, x + 1, y + 1}); // 1 3 4
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
    } else if (mp[x][y] && mp[x + 1][y]) {
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
        ans.push_back({x, y, x, y + 1, x + 1, y + 1}); // 1 2 4
    } else if (mp[x][y] && mp[x + 1][y + 1]) {
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
    } else if (mp[x][y + 1] && mp[x + 1][y]) {
        ans.push_back({x, y, x, y + 1, x + 1, y + 1}); // 1 2 4
        ans.push_back({x, y, x + 1, y, x + 1, y + 1}); // 1 3 4
    } else if (mp[x][y + 1] && mp[x + 1][y + 1]) {
        ans.push_back({x, y, x + 1, y, x + 1, y + 1}); // 1 3 4
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
    } else if (mp[x + 1][y] && mp[x + 1][y + 1]) {
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
        ans.push_back({x, y, x, y + 1, x + 1, y + 1}); // 1 2 4
    } else if (mp[x][y]) {
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
        ans.push_back({x, y, x + 1, y, x + 1, y + 1}); // 1 3 4
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3

    } else if (mp[x + 1][y]) {
        ans.push_back({x, y, x + 1, y, x + 1, y + 1}); // 1 3 4
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
    } else if (mp[x][y + 1]) {
         ans.push_back({x, y, x, y + 1, x + 1, y + 1}); // 1 2 4
        ans.push_back({x, y, x, y + 1, x + 1, y}); // 1 2 3
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
    } else if (mp[x + 1][y + 1]) {
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1}); // 2 3  4
        ans.push_back({x, y, x + 1, y, x + 1, y + 1}); // 1 3 4
         ans.push_back({x, y, x, y + 1, x + 1, y + 1}); // 1 2 4
    }
    mp[x][y] = mp[x + 1][y] = mp[x][y + 1] = mp[x + 1][y + 1] = 0;
}

void solve() {
    ans.clear();
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &mp[i][j]);
            cat[i][j] = mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + 1 > n || j + 1 > m) continue;
               // ans.clear();
                work(i, j);
            //     for (auto i: ans) {
            //     printf("%d %d %d %d %d %d\n", i.a, i.b, i.c, i.d, i.e, i.f);
            //     cat[i.a][i.b] ^= 1, cat[i.c][i.d] ^= 1, cat[i.e][i.f] ^=1;
            //     // if (cat[i.a][i.b] == 1 || cat[i.c][i.d] == 1 || cat[i.e][i.f]) {
            //     //     break;
            //     // }
            // }
    
            // for (int i = 1; i <= n; i++) {
            //     for (int j = 1; j <= m; j++) {
            //         cout << cat[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
    
        }
    }
    printf("%d\n", ans.size());
    for (auto i: ans) {
        printf("%d %d %d %d %d %d\n", i.a, i.b, i.c, i.d, i.e, i.f);
        cat[i.a][i.b] ^= 1, cat[i.c][i.d] ^= 1, cat[i.e][i.f] ^=1;
        // if (cat[i.a][i.b] == 1 || cat[i.c][i.d] == 1 || cat[i.e][i.f]) {
        //     break;
        // }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << cat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

}

int main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }
}