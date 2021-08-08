#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int a[N], n;
vector<ll>g;

vector<ll>v;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        g.clear();
        scanf("%d", &n);
        ll cnt = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            cnt += a[i];
        }
        sort(a + 1, a + n + 1);
        ll f = 0;
        ll cn = cnt;
        for(ll i = 2; i <= sqrt(cn); i++){
            if(cnt % i == 0){
               g.push_back(i);
               while(cnt % i == 0){
                   cnt = cnt / i;
               }
            }
        }
        if(cnt > 1)
         g.push_back(cnt);

       ll minn = LLONG_MAX;
       for(int i = 0; i < g.size(); i++){
           ll ans = 0;
           v.clear();
           for(int j = 1; j <= n; j++){
               if(a[j] % g[i]){
                   v.push_back(a[j] % g[i]);
               }
           }
        //    if(g[i] == 3){
        //        for(int to: v){
        //            cout <<to << " ";
        //        }
        //    }
           ll cat = 0;
           sort(v.begin(), v.end());
           for(int j = 0; j < v.size(); j++){
               if(cat+ v[j] >= g[i]){
                   ans += cat;
                   ans -= (cat + v[j]) % g[i];
                   cat = (cat + v[j]) % g[i];
               }else{
                    cat += v[j];
               }
              
           }
           minn = min(ans, minn);
       }
        printf("%lld\n", minn);
    }
}
