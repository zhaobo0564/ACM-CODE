#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int N = 1e5;

int n;
int head[N];

struct edge{
    int to, nxt;
}e[2 * N];
int top = 1;

void add_edge(int u, int v){
    e[top].to = v;
    e[top].nxt = head[u];
    head[u] = top++;
}

int sizes[N];
int father[N];

void dfs(int u , int fa){
    sizes[u] = 1;
    father[u] = fa;
    for(int i = head[u]; i ; i = e[i].nxt){
        int to = e[i].to;
        if(to == fa)continue;
        dfs(to, u);
        sizes[u] += sizes[to];
    }
}


int main(){

    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; i++){
           // g[i].clear();
            father[i] = 0;
            head[i] = 0;
        }
        for(int i = 1; i < n; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs(1, 0);
        int minn = ;
        // for(int i = 1; i <= n; i++){
        //     int maxn = 0;
        //     for(int j = head[i]; j ; j = e[j].nxt){
        //         int to = e[j].to;
        //         if(to == father[i])continue;
        //         maxn = max(maxn, sizes[to]);
        //     }
        //     maxn = max(maxn, n - sizes[i]);
        //     minn = min(minn, maxn);
        // }
        vector<int>v;
        for(int i = 1; i <= n; i++){
            int maxn = 0;
            if(n - sizes[i] == minn){
                v.push_back(i);
                continue;
            }
            for(int j = head[i]; j ; j = e[j].nxt){
                int to = e[j].to;
                if(to == father[i])continue; 
                maxn = max(maxn, sizes[to]);
                if(maxn == minn){
                    v.push_back(i);
                    break;
                }
            
            }
        }
        for(int i = 0; i < v.size(); i++){
            printf("%d ", v[i]);
        }
        puts("");
    }
    
}