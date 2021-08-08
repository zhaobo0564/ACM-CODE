#include<bits/stdc++.h>
#define ll long long 
using namespace std;
map<ll,int>mp;
int l[130],r[130],cnt;
void dfs(ll n)
{
	if(mp.count(n))return;
	if(n==1)
	{
		mp[n]=cnt++;
		return;
	}
	ll m=n/2;
	dfs(n-m),dfs(m);
	mp[n]=cnt++;
	l[cnt-1]=mp[n-m];
	r[cnt-1]=mp[m];
}
int main()
{
	int T;
	scanf("%d",&T);
	l[0]=-1,r[0]=-1;
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		mp.clear();
		cnt=0;
		dfs(n);
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++)printf("%d %d\n",l[i],r[i]);
		printf("%d\n",cnt-1);
	}
}