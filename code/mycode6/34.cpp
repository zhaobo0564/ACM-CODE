#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int mp[N][N], n;

bool judge(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) {
        return false;
    }
    return true;
}

vector<int> ans;

void dfs(int p, int x, int y, int sum, int step) {
    if (p == step) {
        ans.push_back(sum);
        //cout << sum << endl;
        return;
    }
    if (judge(x + 1, y)) {
        dfs(p + 1, x + 1, y, sum * 10 + mp[x + 1][y], step);
    }
    if (judge(x, y + 1)) {
        dfs(p + 1, x, y + 1, sum * 10 + mp[x][y + 1], step);
    }
    if (judge(x - 1, y)) {
        dfs(p + 1, x - 1, y, sum * 10 + mp[x - 1][y], step);
    }
    if (judge(x, y - 1)) {
        dfs(p + 1, x, y - 1, sum * 10 + mp[x][y - 1], step);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mp[i][j]);
           //mp[i][j]  = 1;
        }
    }

    for (int step = 1; step <= 5; step++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dfs(1, i, j, mp[i][j], step);
            }
        }
    }
  //  cout << ans.size() << endl;

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 1; i <= 1e6; i++) {
        int p  = lower_bound(ans.begin(), ans.end(), i) - ans.begin();
        if (ans[p] != i) {
            printf("%d\n", i);
            break;
        }
    }

    


}