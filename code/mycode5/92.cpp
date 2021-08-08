#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
#include<fstream>
#include<complex>
#include<algorithm>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
int a[5010],dp[5010][5010]; 
const int mod= 1e9+7;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n-1;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=0;
			}
		}
		if(a[1]==1){
			dp[2][1]=1;
			dp[2][2]=0;
		}
		else{
			dp[2][2]=1;
			dp[2][1]=0;
		}
		for(int i=2;i<=n-1;i++){
			if(a[i]==1){
				dp[i+1][i+1]=0;
				for(int j=i;j>=1;j--){
					dp[i+1][j]=(dp[i+1][j+1]+dp[i][j])%mod;
				}
			}
			else{
				dp[i+1][1]=0;
				for(int j=2;j<=i+1;j++){
					dp[i+1][j]=(dp[i][j-1]+dp[i+1][j-1])%mod;
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++) res=(res+dp[n][i])%mod;
		cout<<res<<endl; 
	}
    return 0;
}

