#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int t, n;

char a[N], b[N];

vector<int> g[1000];
vector<int > v[1000];

int fa[N], vis[N];



int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i <= n + 2; i++) {
            fa[i] = i;
            vis[i] = 0;
            
        }
        for (int i = 'a'; i <= 'z'; i++) {
            g[i].clear();
            v[i].clear();
        }

        scanf("%s", (a + 1));
        scanf("%s", (b + 1));
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i])
            g[a[i]].push_back(i);
            maxn = max(maxn, (int)a[i]);
        }
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > b[i]) {
                f = 1;
                break;
            }
        }
        if (f) puts("-1");
        else {
            int ans = 0;
            for (int i = 'a'; i <= 't'; i++) {
                if (g[i].size()) ans++;
                for (int pos: g[i]) {
                    v[i].push_back(b[pos] - a[pos]);
                }
                if (v[i].size() == 0)continue;
                sort(v[i].begin(), v[i].end());
                int ok = 0;
               
                for (int j = 1; j < v[i].size(); j++) {
                    if (v[i][j] - v[i][0] > 0)
                        v[i + 1].push_back(v[i][j] -v[i][0]);
                }
                
            }
            int pos = 't' + 1;
            sort(v[pos].begin(), v[pos].end()); 
            for (int j = 1; j < v[pos].size(); j++) {
                if (v[pos][j] > v[pos][j - 1]) {
                    ans++;
                } 
            }
            printf("%d\n", ans );
        }
        
    }
}
