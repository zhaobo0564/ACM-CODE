#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;
bitset <20000000> qwq;
int a[100005],dp[20000005];
signed main() {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=i;j<=n;j++)
		{
			if(now+a[j]!=(now|a[j])) break;
			now|=a[j];
			qwq[now]=1;
		}
	}
	for(int i=0;i<(1<<24);i++)
	{
		if(qwq[i]) dp[i]=i;
		for(int j=0;j<=23;j++)
			dp[i]=max(dp[i],dp[i^(1<<j)]);
	}
	int ans=0,X=(1<<24)-1;
	for(int i=0;i<(1<<24);i++)
		if(qwq[i]) {
            cout << i << " " << (X ^ i) << " " << dp[X ^ i] << endl;
            ans=max(ans,i+dp[X^i]);
        }
	cout << ans;
	return 0;
}

/*
4
1 2 2 4
1 16777214 6
2 16777213 4
3 16777212 4
4 16777211 3
6 16777209 1
*/