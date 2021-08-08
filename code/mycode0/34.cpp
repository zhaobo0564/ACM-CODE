#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int t, n, m, s, mp[N][N], Ans;
int vis[N];

vector<int> g[N];
vector<int> v;

bool judge(int x){
 
    if(x == v.size()){
   
        return true;
    }
    for(int i: v){
        if(v[x] == i)continue;
        if(!mp[v[x]][i]) return false;
    }
    if(judge(x + 1)) return true;
    return false;

}

void dfs(int id, int p, int pos, int value){
 //   cout <<"p=" << p<< endl;
    if(pos == g[id].size())return;
    if(p + g[id].size() - pos < s)return;
    if(p == s - 1){
        v.clear();
        int ans = value;
        int cnt = 0;
        while(ans){
            if(ans & 1){
                v.push_back(g[id][cnt]);
                cout <<"asd="<<g[id][cnt]<<endl;
            }
            ans = ans / 2;
            cnt++;
        }
        v.push_back(id);
        cout<<endl;
     //   cout <<"value = " <<value << " " << vis[value]<<endl;
        if( judge(0)){
            Ans++;
      //      cout << "ans ="<< ans<< endl;
        }
    }
    dfs(id, p + 1, pos + 1, value + (1<<(p + 1)));
    dfs(id, p, pos + 1, value);
}



int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &s);
        for(int i = 1; i <= m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            g[min(u, v)].push_back(max(u, v));
          //  g[v].push_back(u);
            mp[u][v] = mp[v][u] = 1;
        }
        for(int i = 1; i <= n; i++){
            if(g[i].size() >= s - 1){
                dfs(i, 1, 0, 1);
                dfs(i, 0, 0, 0);
            }
        }
       cout << Ans<<endl;
       for(int i = 1; i <= n; i++){
           g[i].clear();
       }
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= n; j++){
               mp[i][j] = 0;
           }
       }

    }
}
