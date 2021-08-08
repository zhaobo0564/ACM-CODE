#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;

int x, n, m, vis[N];

vector<int> g[N];

vector<int> ans;


void dfs(int u) {
    vis[u] = 1;
    ans.push_back(u);
    for(int to: g[u]) {
        if (vis[to] == 0) {
            dfs(to);
        }
    }
}
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
   cin >> x >> n >> m;
   int top = x + 1;
   for (int i = 1; i <= m; i++) {
       int y; cin >> y;
       v.clear();
       for (int j = 1; j <= y; j++) {
           int cnt; cin >> cnt;
            v.push_back(cnt);
       }
       for (int j = 0; j < v.size(); j++) {
           for (int k = j + 1; k < v.size(); k++) {
               g[v[j]].push_back(v[k]);
               g[v[k]].push_back(v[j]);
           }
       }
   }
    dfs(n);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << " ";
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;

}
