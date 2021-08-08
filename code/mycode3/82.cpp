#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define int long long
#define ll __int128_t
const int inf = 0x3f3f3f3f;
const int maxn = 101110;
 int M = 1e9+7;
int n,m,k,ok;
 
string a;
 
pii dp[maxn];
 
pii dfs(int sw,bool limit)
{
    if(sw == -1) return make_pair(1,0);
    if(!limit && dp[sw].first != -1) return dp[sw];
    int cnt = 0,sum = 0;
    int up = limit?a[sw]-'0':9;
    for(int i = 0; i <= up; i++)
    {
        pii tmp = dfs(sw-1,limit&&(i==up));
        cnt = (cnt + tmp.first)%M;
        if(i == 7) sum = (sum + tmp.first)%M;
        sum = (sum + tmp.second)%M;
    }
    if(!limit) dp[sw] = {cnt,sum};
    return {cnt,sum};
}
 
 
signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
   
    int T;
    cin>>T;
    mem(dp,-1);
    while(T--)
    { 
        cin>>a;
        reverse(a.begin(),a.end());
        n = a.size();
        
        cout<<dfs(n-1,1).second<<endl;
        
    }
    return 0;
}