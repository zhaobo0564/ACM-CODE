#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[500];
ll dp[500][500][]

ll dfs(int p, int sum, int k, ll total){
    if(p == n){
        if(k) return total;
        return 0;
    }
    ll ans = 0;
    if(cnt[p] == 0){
        ans = max(ans, dfs(p + 1, 0, k, total));
    }else{
        ans = max(ans, dfs(p + 1, sum + 1, k -( sum + 1), total + 1));
        ans = max(ans, dfs(p + 1, 0, k, total));
    }
    return  

}