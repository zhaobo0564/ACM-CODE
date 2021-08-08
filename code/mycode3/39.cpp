#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
struct node{
    int u, w;
    bool operator<(const node a)const{
        return w > a.w;
    }
};

priority_queue<node>q;

vector<int>g[N];
int t[N], n, m, vis[N];

vector<int>v;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &t[i]);
        q.push({i, t[i]});
    }
    int f = 0;
    while(q.size()){
        node cd = q.top();
        q.pop();
      //  vis[cd.w] = 1;
        for(int to: g[cd.u]){
            if(cd.w == t[to]){
                puts("-1");
                return 0;
            }
        }
        v.push_back(cd.u);
    }
    for(int ans: v){
        printf("%d ", ans);
    }
    puts("");
}