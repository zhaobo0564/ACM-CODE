#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, m;

vector<pair<int, int> >g[N];

int  vis[N], in[N];
struct node{
    int u,v;
    /* data */
}a[N], b[N];

int top = 1;

bool bfs(){
    queue<int>q;
    q.push(1);
    in[1] = 1;
    while(q.size()){
       
        int cd = q.front(); //cout << cd << endl;
        q.pop();
        if(vis[cd])continue;
        vis[cd] = 1;
        for(auto i: g[cd]){
            int to = i.first;
            int id = i.second;
            if(vis[to]){
                if(in[to] == in[cd]){
                //    cout << cd << " " << to << endl;
                    return false;
                }
            }else{
                if(in[cd] == 1){
                    b[id].u = to;
                    b[id].v = cd;
                    in[to] = -1;
                  
                }else if(in[cd] == -1){
                    b[id].u = cd;
                    b[id].v = to;
                    in[to] = 1;
            
                }
                q.push(to);
            }
        }
     //   cn++;
    }
    return true;
    
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        a[i] = {u, v};
    }
    bool ans = bfs();
    if(!ans)puts("No");
    else{
        puts("Yes");
        for(int i = 1; i <= m; i++){
            if(a[i].u == b[i].u){
                printf("0");
            }else{
                printf("1");
            }
        }
        puts("");
    }
}