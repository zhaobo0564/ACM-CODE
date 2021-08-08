#include<bits/stdc++.h>
using namespace std;
const int N = 4007;

int vis[N][N], p[N], n;
vector<int> g[N];


int main(){
    Init();
    Solve();
    printf("%d\n",ans);
}
 
int main() {
    scanf("%d", &n);

    for (int i = 1; i <= 2 * n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[i].push_back(v);
        g[i].push_back(v + );
        g[i].push_back(u);
        g[i].push_back(n + u);
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
      //  memset(vis, 0, sizeof(vis));
        if (match(i, i)) ans++;
    }
    cout << ans << endl;


    
    
}
 
 