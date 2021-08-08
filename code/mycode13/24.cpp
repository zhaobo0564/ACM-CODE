#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define ULL unsigned long long

const int N=1e3+10,ha=137;
int n,m,k;
int a[N][N];
LL s[N][N];
LL dp[302][1001];
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			s[i][j]=s[i][j-1]+a[i][j];
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--){
			for(int c=k;c>=j;c--){
				dp[i][c]=max(dp[i][c],dp[i+1][c-j]+s[i][j]);
			}
		}
	}
	cout<<dp[1][k] << endl;;
}
int main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
} 
/*
6 5

aaaaaa
abcdab
3
2 2 4
3

*/