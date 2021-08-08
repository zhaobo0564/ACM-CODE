#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
int n;
ll k, a[N];


vector<ll>positive, negative;

bool judge(ll x){
    ll ans = 0;
    for(int i = 0; i < negative.size(); i++){
        ll l = i + 1, r = negative.size() - 1;
        ll res = r + 1;
        while(l <= r){
            ll m = (l + r) / 2;
            if(negative[m] * negative[i] <= x){
                r = m - 1;
                res = m;
            }else{
                l = m + 1;
            }
        }
        ans += negative.size() - res;
    }
  
    for(int i = 0; i < positive.size(); i++){
        ll l = i + 1, r = positive.size() - 1;
        ll res = -1;
       // cout <<"l " << l << " r " << r << endl;
        while(l <= r){
            ll m = (l + r) / 2;
         //   cout <<"AA " << positive[i] * positive[m] << endl;
            if(positive[i] * positive[m] <= x){
                
                l = m + 1;
                res = m;
            }else{
                r = m - 1;
            }
        }
        if(res != -1){
         //   cout <<"res " << res - i << endl;
            ans += res - i;
        }
        
    }
  //  cout <<"ans " << ans << endl;
    for(int i = 0; i < positive.size(); i++){
        ll l = 0, r = negative.size() - 1;
        ll res = -1;
        while(l <= r){
            ll m = (l + r) / 2;
            if(positive[i] * negative[m] <= x){
                l = m + 1;
                res = m;
            }else{
                r = m - 1;
            }
        }
        ans += res + 1;
    }
  //  cout <<"m " << x << "ans " << ans << endl;
    if(ans >= k)return true;
    return false;
}

map<ll, int>q;
int main(){
    scanf("%d %lld", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        if(a[i] >= 0)positive.push_back(a[i]);
        else negative.push_back(a[i]);
       
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    ll l = -1000000000000000000;
    ll r = 1000000000000000000;
    ll ans;
    //judge(r);
    while(l <= r){
        ll m = (l + r) / 2;
        if(judge(m)){
            r = m - 1;
            ans = m;
        }else{
            l = m + 1;
        }
    }
    printf("%lld\n", ans);
}
/*
10 40
5 4 3 2 -1 0 0 0 0 0
*/