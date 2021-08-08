#include <bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,a[10],i;
vector<int> v;
string ans;
int main()
{
	rep(i,10){
		cin>>a[i-1];
		if(a[i-1]&1)v.push_back(i-1);
	}
	if(v.size()>1){
		puts("-1");return 0;
	}
	if(v.size()==1)a[v[0]]--;
	rep(i,10) a[i-1]/=2;
	rep(i,9) if(a[i]){
		a[i]--;ans.push_back(i+'0');break;
	}
	if(a[0]&&ans.empty()){
		puts("-1");return 0;
	}
	rep(i,10)while(a[i-1]){
		a[i-1]--;ans.push_back(i+'0'-1);
	}
	cout<<ans;if(v.size()==1)cout<<v[0];
	reverse(ans.begin(),ans.end());cout<<ans<<endl;
	return 0;
}