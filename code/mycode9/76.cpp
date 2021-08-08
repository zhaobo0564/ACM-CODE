#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n;
typedef long long ll;

map<int, int> fn[N];
int vi[N];
vector<int> v;

map<int, int> vis;

void bfs(ll x, int id) {
    queue<pair<ll, int> > q;
    q.push({x, 0});
    vis.clear();
    while (q.size()) {
        auto cd = q.front();
        q.pop();
        if (vis[cd.first]) continue;
        vi[cd.first]++;
        vis[cd.first] = 1;
        if (vi[cd.first] == n) {
            v.push_back(cd.first);
        }
        fn[id][cd.first] = cd.second;
        if (cd.first * cd.first < N) {
            q.push({cd.first * cd.first, cd.second + 1});
        }
        int x = sqrt(cd.first);
        q.push({x, cd.second + 1});
    }
    
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        bfs(a[i], i);
    }
    int ans = 1e8;
    for (int j: v) {
       // cout << j << endl;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += fn[i][j];
        }   
        ans = min(ans, cnt);
    }
    printf("%d\n", ans);
    
}