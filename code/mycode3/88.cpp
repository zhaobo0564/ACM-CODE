#include<bits/stdc++.h>
using namespace std;
const int N = 300;
vector<int>g[N];
typedef long long ll;
int n, m, mp[N][N];
int vis[N], vis1[N];
const ll  mod = 1e9 + 7;

ll c[N][N];
void C()
{
    int i,j;
    for(i=0;i<N;i++)
        c[i][0]=c[i][i]=1;
    for(i=1;i<N;i++)
        for(j=1;j<=i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
}
ll get(int x, int y){
    // if(y > x)return 0;
    // if(x == y)return 1;
    return c[x][y];

}
ll work(int s, int t, int sum){
    ll ans = 0;
    for(int i = 0; i <=3; i++){
        for(int j = 0; j <= 2; j++){
            if(i + j > sum)break;
            ans = (ans + get(sum, i) * get(s, 3 - i) * get(sum - i, j)* get(t, 2 - j)) % mod;
          //  cout << ans << " " << i << " " << j << endl;
        }
    }
    return ans;
}

int main(){
    scanf("%d %d", &n, &m);
    C();
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        mp[v][u] = 1;
        mp[u][v] = 1;
    }
    vector<int>fa, son;
    ll ans = 0;
  //  cout<<c[1][2] << endl;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){
            if(i == j)continue;

            if(mp[i][j]){
                fa.clear();
               // son.clear();
                memset(vis, 0, sizeof(vis));
      //  memset(vis1, 0, sizeof(vis1));
                int cat = 0, cat1 = 0;
                for(int k = 0; k < g[i].size(); k++){
                    if(g[i][k] == j)continue;
                    fa.push_back(g[i][k]);
                    cat1++;
                }
                for(int k = 0; k < g[j].size(); k++){
                    if(g[j][k] == i)continue;
                    vis[g[j][k]] = 1;
                    cat++;
                }
                ll cnt = 0;
                for(int k = 0; k < fa.size(); k++){
                   // cout << fa[k] << " ";
                    if(vis[fa[k]] == 1){
                        cnt++;
                    }
                }
           //     cout << endl;
               
                if(cat1 >= 3 && cat >= 2){ 
                  //  cout << cat1 - cnt << " " << cat - cnt << " " << cnt << endl;
                    ans = ans + work(cat1 - cnt, cat - cnt, cnt);
                    //cout << "ans = " << ans << endl;
                    ans = ans % mod;
                
                }

                

            }
        }
    }
    printf("%lld\n", ans);
} 

