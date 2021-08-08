#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<ll>v;
 
ll en, n, m, a[100000];
 
bool judge(ll x){
 
    for(int i = 0; i < v.size(); i++){
        a[i] = v[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] < x){
            ans++;
            a[i] = a[i - 1];
        }
    }
    if(a[n] - a[n - 1] < x)ans++;
    int ans1 = 0;
    for(int i = 0; i < v.size(); i++){
        a[i] = v[i];
    }
    for(int i = n - 1; i; i--){
        if(a[i + 1] - a[i] < x ){
            a[i] = a[i + 1];
            ans1++;
        }
    }
    if(a[1]< x )ans1++;
    ans = min(ans, ans1);



    if(ans <= m)return true;
    return false;
}

int main(){
    scanf("%lld %lld %lld", &en, &n, &m);
    v.push_back(0);
    for(int i = 1; i <= n; i++){
        ll x; scanf("%lld", &x);
        v.push_back(x);
    }
    v.push_back(en);
    n++;
    ll l = 1, r = 1e10;
    ll ans = en;
    while(l <= r){
        ll m = (l + r) / 2;
        if(judge(m)){
            l = m + 1;
            ans = m;
        }else{
            r = m - 1;
           // ans = m;
        }
    }
    printf("%lld\n", ans);
 
}