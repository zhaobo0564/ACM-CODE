#include<bits/stdc++.h>
using namespace std;

int n, t, x, y, c, r;
vector<pair<int, int> >g;
int vis[20];

void dfs(int p,  int len){
    if(p == n){

    }
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            
            dfs(p + 1, len +)
        }
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &c, &r);
        scanf("%d %d", &x, &y);
        scnaf("%d", &n);
        for(int i = 1; i <= n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            g.push_back({a, b});
        }
    }
}