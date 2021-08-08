#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int t,n,m,fa[30007],dist[30007];
string s[30007],u,v;
vector<int>ho[30007];
map<string,int>ma;
vector<int>ans;


struct madoka{
    int p;
    bool operator < (const madoka & a) const
    {
        return s[p]>s[a.p];
    }
}lin,lin2;
priority_queue <madoka> sa;
int main(){
     ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
	cin >> t;
	int z=0;
	while(t--){
		z++;
		ma.clear();
		ans.clear();
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			ho[i].clear();
			fa[i]=0;
			dist[i]=0;
			cin>>s[i];
			ma[s[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>u;
			cin>>v;
			ho[ma[u]].push_back(ma[v]);
			fa[ma[v]]++;
		}
		for(int i=1;i<=n;i++){
			if(fa[i]!=0){
				continue;
			}
			else{
				dist[i]=1;
				lin.p=i;
				sa.push(lin);
			}
		}
		while(!sa.empty()){
			lin=sa.top();
			sa.pop();
			ans.push_back(lin.p);
			for(int i=0;i<ho[lin.p].size();i++){
				fa[ho[lin.p][i]]--;
				if(dist[ho[lin.p][i]]==0&&fa[ho[lin.p][i]]==0){
					dist[ho[lin.p][i]]=1;
					lin2.p=ho[lin.p][i];
					sa.push(lin2);
				}
			}
		}
	    cout << "Case #" << z << ":\n";
		if(ans.size()==n){
			for(int i=0;i<ans.size();i++){
				cout<<s[ans[i]]<<endl;
			}
	}
		else{
			cout << "Impossible\n";
		}
	}
}
