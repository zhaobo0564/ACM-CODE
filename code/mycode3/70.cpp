#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
typedef long long ll;
ll a[N];
int n;
vector<ll>g;
vector<ll>v[10];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
  //  g.erase(unique(g.begin(), g.end()), g.end());
    ll sum = 0;
    for(int i = 0; i < g.size(); i++){
      //  cout << g[i] << " " ;
        sum += g[i];
        v[g[i] % 5].push_back(g[i]);
    }
    for(int i = 1; i <= 4; i++){
        sort(v[i].begin(), v[i].end());
    }
    int cnt = sum % 5;
    if(cnt == 0){
        printf("%lld\n", sum);
    }else{
        if(cnt == 1){
            ll ans = LLONG_MAX;
            if(v[1].size()){
                ll cnt = v[1][0];
                ans = min(ans, cnt);
            }
            if(v[2].size() && v[4].size()){
                ll cnt = v[2][0] + v[4][0];
                ans = min(cnt, ans);
            }
            if(v[3].size() > 1){
                ll cnt = v[3][0] + v[3][1];
                ans = min(ans, cnt);
            }
            if(v[2].size() > 2){
                ll cnt = v[2][0] + v[2][1] + v[2][2];
                ans = min(ans, cnt);
            }
            if(v[4].size() > 1 && v[3].size()){
                ll cnt = v[4][0] + v[4][1] + v[3][0];
                ans = min(ans, cnt);
            }
            if(v[4].size() > 3){
                ll cnt = v[4][0] + v[4][1] + v[4][2] + v[4][3];
                ans = min(ans, cnt);
            }

            printf("%lld\n", sum - ans);
        }else if(cnt == 2){
            ll ans = LLONG_MAX;
            if(v[2].size()){
                ll cnt = v[2][0];
                ans = min(ans, cnt);
            }
            if(v[3].size() && v[4].size()){
                ll cnt = v[3][0] + v[4][0];
                ans = min(ans, cnt);
            }
            if(v[1].size() > 1){
                ll cnt = v[1][0] + v[1][1];
                ans = min(ans, cnt);
            }
            if(v[4].size() > 2){
                ll cnt = v[4][0] + v[4][1] + v[4][2];
                ans = min(ans, cnt);
            }
            if(v[3].size() > 1 && v[1].size()){
                ll cnt = v[3][0] + v[3][1] + v[1][0];
                ans = min(ans, cnt);
            }
            if(v[3].size() > 3){
                ll cnt = v[3][0] + v[3][1] + v[3][2] + v[3][3];
                ans = min(cnt, ans);
            }
            printf("%lld\n", sum - ans);
        }else if(cnt == 3){
            ll ans = LLONG_MAX;
            if(v[3].size()){
                ll cnt = v[3][0];
                ans = min(ans, cnt);
            }
            if(v[1].size() && v[2].size()){
                ll cnt = v[1][0] + v[2][0];
                ans = min(ans, cnt);
            }
            if(v[4].size() > 1){
                ll cnt = v[4][0] + v[4][1];
                ans = min(ans, cnt);
            }
            if(v[1].size() > 2){
                ll cnt = v[1][0] + v[1][2] + v[1][1];
                ans = min(ans, cnt);
            }
            if(v[2].size() > 1 && v[4].size()){
                ll cnt = v[2][0] + v[2][1] + v[4][0];
                ans = min(ans, cnt);
            }
            if(v[2].size() > 3){
                ll cnt = v[2][0] + v[2][1] + v[2][2] + v[2][3];
                ans = min(ans, cnt);
            }
            printf("%lld\n", sum - ans);
        }else if(cnt == 4){
            ll ans = LLONG_MAX;
            if(v[4].size()){
                ll cnt = v[4][0];
                ans = min(ans, cnt);
            }
            if(v[2].size() > 1){
                ll cnt = v[2][1] + v[2][0];
                ans = min(ans, cnt);
            }
            if(v[1].size() && v[3].size()){
                ll cnt = v[1][0] + v[3][0];
                ans = min(ans, cnt);
            }
            if(v[3].size() > 2){
                ll cnt = v[3][0] +v[3][1] + v[3][2];
                ans = min(ans, cnt);
            }
            if(v[1].size() > 3){
                ll cnt = v[1][0] + v[1][2] + v[1][1] + v[1][3];
                ans = min(ans, cnt); 
            }
            if(v[1].size() > 1 && v[2].size()){
                ll cnt = v[1][0] + v[1][1] + v[2][0];
                ans = min(ans, cnt);
            }
        
            printf("%lld\n", sum - ans);
        }
    }
}