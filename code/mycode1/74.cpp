#include<bits/stdc++.h>
using namespace std;
int n, a[30], sum[40], vis[30];
vector<int>q;
int f;

void dfs(int p, int value){
    if(p == n){
        f = 1;
        for(int i: q){
            printf("%d ", i);
        }
        puts("");
        return;
    }
    if(f)return;
    for(int i = 1; i <= n; i++){
        if(i == p + 1 || vis[i])continue;
        if(p + 1 != n && sum[p + 1] == value + a[i])continue;
        vis[i] = 1;
        q.push_back(a[i]);
        if(f)return;
        dfs(p + 1, value + a[i]);
        if(f)return;
        q.pop_back();
        vis[i] = 0;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    dfs(0, 0);
    if(!f)puts("-1");
   


}