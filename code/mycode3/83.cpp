#include<bits/stdc++.h>
using namespace std;
 
int t, n;
typedef long long ll;
const int N = 101110;
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
string s;
#define mod  1000000007
 
pii dp[N];

pii dfs(int p, bool f){
    if(p == -1){
       return make_pair(1, 0);
    }
    if(!f && dp[p].first != -1)return dp[p];
    int up = f? s[p] - '0': 9;
    ll ans = 0, all = 0;

 
    for(int i = 0; i <= up; i++){
       pii cd = dfs(p - 1, f && (i == up)); 
       all = (all + cd.first) % mod;
        if(i == 7)ans = (ans + cd.first) % mod;
        ans = (ans + cd.second) % mod;
       
    }
    if(!f)dp[p] = {all, ans};
    return {all, ans};
}
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    
     mem(dp,-1);
    while(t--){
 
        cin >> s;
        
        reverse(s.begin() , s.end());
        n = s.size();
        cout<<dfs(n-1,1).second<<endl;
    }
    return 0;
}