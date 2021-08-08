#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n;
vector<int> g[N], v[N];
struct node{
    int u,v,w;
}p[N];

map<int, int>vis[N];
 

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &p[i].u, &p[i].v);
        p[i].w = 0;
        g[p[i].u].push_back(p[i].v);
        g[p[i].v].push_back(p[i].u);
    }
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(g[i].size() > 2){
            //cout<<"i="<<i<<endl;
            vis[i][g[i][0]] = 1;
            vis[i][g[i][1]] = 1;
            vis[i][g[i][2]] = 1;
            vis[g[i][0]][i] = 1;
            vis[g[i][1]][i] = 1;
            vis[g[i][2]][i] = 1;
            break;
        }
    }
    for(int i = 1; i < n; i++){
        int u = p[i].u;
        int to = p[i].v;
        if(vis[to][u] ){
            //cout<<"to="<<to <<endl;
            p[i].w = cnt++;
        }
    }
    for(int i = 1; i < n; i++){
        if(p[i].w == 0){
            p[i].w = cnt++;
        }
        printf("%d\n", p[i].w - 1);
    }

    

}