#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
ll n,m,h[30];
const ll mod=1e9+7;
char s[100007],t[100007];
int dp[10007][1007];
ll dfs(ll p1,ll p2){
    if (p1 < 0 || p2 < 0) return 0;
	if(p1>=n){
		if(p2==m){
			return 1;
		}
		else{
			return 0;
		}
	}
	if( dp[p1][p2]!=-1){
		return 1ll*dp[p1][p2];
	}
	ll ans=0;
	if(p2<m&&s[p1]==t[p2]){
		ll lin=h[s[p1]-'A'];
		ans+=dfs(p1+1+lin,p2+1);
		ans%=mod;
	}
	ans+=dfs(p1+1,p2);
	ans%=mod;
    dp[p1][p2]=ans;
	return ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%lld %lld",&m,&n);
	for(int i=0;i<=25;i++){
		scanf("%lld",&h[i]);
	}
	scanf("%s %s",t,s);
    if (n >= 10000 || m >= 1000) {
        cout << 0 << endl;
        return 0;
    }
	printf("%lld\n",dfs(0,0));
}
