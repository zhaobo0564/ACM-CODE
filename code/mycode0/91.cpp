#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l, r;
vector<ll>v;

void dfs(int p, int toal, ll sum){
    if(p == toal){
        v.push_back(sum);
        return;
    }
    dfs(p + 1, toal, sum * 10 + 4);
    dfs(p + 1, toal, sum * 10 + 7);
}


int main(){
    scanf("%lld %lld", &l, &r);
    for(int i = 1; i <= 10; i++){
        dfs(0, i, 0);
    }
    sort(v.begin(), v.end());
    ll be = l;
    ll sum = 0;

    while(1){
        int p = lower_bound(v.begin(), v.end(), be) - v.begin();
        ll ans = v[p];
        if(ans >= r){
            sum += (r - be + 1)*ans;
            break;
        }else{
            sum = sum + (ans - be + 1) * ans;
        }
        
        be = ans + 1;

    }
    printf("%lld\n", sum);
}