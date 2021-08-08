#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

int vis[N], cnt[N], a[N];





int n, m;


vector<int>g[N], cn;



int main(){

    ll ans = 0;
    scanf("%d %d", &n, &m);
    int k = n / m;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        cnt[i] = a[i] % m;
        vis[cnt[i]]++;
        g[cnt[i]].push_back(i);
    }

    for(int i = 0; i < m; i++){
        if(vis[i] < k){
            cn.push_back(i);
        }
    }
    for(int i = 0; i < m; i++){
        if(vis[i] > k){
            int cat = vis[i] - k;
            int p = lower_bound(cn.begin(), cn.end(), i) - cn.begin();
            int j = 0;
            while(cat){
                int cs =k - vis[cn[p]];

                if(cat >= cs){
                    ans += 1ll*cs*1ll*(cn[p] - i);
                   //h[i].push_back(make_pair(cs, cn[p] - i));
                    int x = cs;
                    int y = cn[p] - i;
            
                    while(x){
                        if(j >= g[i].size()){
                            break;
                        }
                        a[g[i][j]] += y;
                        j++;
                        x--;
                    }
                    vis[cn[p]] = k;
                    cat -= cs;
                }else{
                    ans += 1ll*cat*1ll*(cn[p] - i);
                  //  h[i].push_back(make_pair(ans, cn[p] - i));
                    int x = cat;
                    int y = cn[p] - i;
            
                    while(x){
                        a[g[i][j]] += y;
                        j++;
                        x--;
                    }
                    vis[cn[p]] += ans;
                    cat =0;
                }
                p++;  
                if(p == cn.size())p = 0;    
            }

        }
    }
    printf("%lld\n", ans);
    // for(int i = 0; i < m; i++){
    //    if(h[i].size()){
    //        int j = 0;
    //        for(auto it: h[i]){
    //            int x = it.first;
    //            int y = it.second;
    //            while(x){
    //                a[g[i][j]] += y;
    //                j++;
    //                x--;
    //            }
    //        }
    //    }
    // }
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    cout << endl;


}