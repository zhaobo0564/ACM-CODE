#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int fa[N];
vector<int>g[N];
vector<int>ans;
vector<pair<int, int> >p;

int n, h;

void dfs(int u, int fa){
  
    if( g[u].size() == 1){
        ans.push_back(u);        
    }
    for(int to: g[u]){
        if(to == fa)continue;
        dfs(to, u);

    }
}

int main(){
    scanf("%d %d", &n, &h);
    h++;
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u++, v++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 0; i < ans.size() / 2; i++){
        p.push_back({ans[i], ans[ans.size() / 2 + i]});
    }
    if(ans.size() % 2){
        p.push_back({ans[0], ans[ans.size() - 1]});
    }
    cout << p.size() << endl;
    for(auto it: p){
        cout << it.first - 1 << " " << it.second - 1 << endl;
    }
    
  
    
    
}
