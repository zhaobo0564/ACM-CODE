#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5007;
int a[N], n;

unordered_map<int, int>vis, sum[N];

vector<int> g[N];

int main() {
    srand(time(0));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        //scanf("%d", &a[i]);
        a[i] = rand() % 1000000000 - rand() % 1000000000;
       // a[i] = i;
    }
    clock_t c1 = clock();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int cnt = a[i] - a[j];
            g[j].push_back(a[i] - a[j]);
            
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            vis[a[i] + a[j]]++;
        }
        ll cn = 0;
        if (g[i].size() == 0) continue;
        for (int j = 0; j < g[i].size() - 1; j++) {
            if (g[i][j] == g[i][j + 1]) {
                cn++;
            } else {
                cn++;
                ans += 1ll*vis[g[i][j]] * cn;
                cn = 0;
            }
        }
        cn++;
        ans += vis[g[i][g[i].size() - 1]] * cn;


        
      
    }
    
    cout << ans << endl;
    std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;


}