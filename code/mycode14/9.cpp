#include<iostream>
#include<vector>
using namespace std;
const int N=2007;
const int inf=1e9;
vector<int>ho[N];
int n,m;
int f[N],d[N],ans;
void dfs(int p,int fa){
	f[p]=0;
	d[p]=inf;
	for(int i=0;i<ho[p].size();i++){
		int to=ho[p][i];
		if(to==fa)continue;
		dfs(to,p);
		f[p]=max(f[p],f[to]+1);
		d[p]=min(d[p],d[to]+1);
	}
	if(f[p]+d[p]<=2){
		f[p]=-inf;
	}
	else if(f[p]==2){
		ans++;
		f[p]=-inf;
		d[p]=0;
	}
}
void init(){
	for(int i=0;i<n;i++){
		ho[i].clear();
	}
	ans=0;
}
int main(){
	while(~scanf("%d",&n)){
		init();
		for(int i=1;i<=n;i++){
			int p,to;
			scanf("%d:(%d)",&p,&m);
			while(m--){
				scanf("%d",&to);
				ho[p].push_back(to);
				ho[to].push_back(p);
			}
            
		}
    
        int top = n + 1;
        for (int i = 0; i < n; i++) {
            ho[i].push_back(top++);
        }
		dfs(0,-1);
		if(f[0]>=0){
			printf("%d\n",ans+1);
		}
		else{
			printf("%d\n",ans);
		}
	}
}
