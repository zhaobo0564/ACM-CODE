#include<iostream>
#include<algorithm>
using namespace std;
int a[1000],dp[1000];
int t,n,m;
int main()
{
	
	cin>>t;
	while(t--){
		                    
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[j]<a[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		for(int i=0;i<m;i++){
			cin>>l>>r; 
		//	cout<<dp[l]<<" "<<dp[r]<<endl;//dpÇø¼äÖ®²î
			cout<<dp[r]-dp[l]+1<<" ";
		}
	}
}
