#include <bits/stdc++.h>

using namespace std;
const int N = 2000;
char mp[200][200];
int n, m;
int vis[200][200];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int top = 1;

vector<pair<int, int> >g[N];
typedef long long ll;

double dist(pair<int, int> x, pair<int, int> y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

ll const mod = 123456789;

double get_hash(int id) {
    double base = 0.0;
    for (int i = 0; i < g[id].size(); i++) {
        for (int j = 0; j < g[id].size(); j++) {
            if (i == j) continue;
            double cnt = dist(g[id][i], g[id][j]);
            base = cnt + base;
           // cout << "base = " << base << endl;
        }
    }
    return base;
}

double ha[50];

int cnt = 0;

char get_id(double x) {
 
    for (int i = 0; i < cnt; i++) {
        if (fabs(ha[i] - x) <= 0.000000001) {
            return i + 'a';
        }
    } 

    ha[cnt] = x;
    cnt++;
    return 'a' + cnt - 1;  
    
}

char cat[N];

void dfs(int x, int y) {
    vis[x][y] = 1;
    g[top].push_back({x, y});
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0 && mp[nx][ny] == '1') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    swap(n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '1' && vis[i][j] == 0) {
                dfs(i, j);
                top++;
            }
        }
    }
    char s = 'a';
    for (int i = 1; i < top; i++) {
        double cnt = get_hash(i);
      //  cout << "AA" << g[i].size() << endl;
      //  cout << cnt << endl;
        cat[i] = get_id(cnt);
    }

    for (int i = 1; i < top; i++) {
        s = cat[i];
        for (auto it: g[i]) {
            mp[it.first][it.second] = s;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", mp[i][j]);
        }
        puts("");
    }


}