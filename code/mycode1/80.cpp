#include<bits/stdc++.h>
using namespace std;

int n, m, q;
const int N = 100;
struct node{
    int a, b, c,d;
}p[N];

int cnt[20];
int maxn;

void dfs(int dep, int value){
    if(dep == n){
        int sum = 0;
        for(int i = 1; i <= q; i++){
            if(cnt[p[i].b] - cnt[p[i].a] == p[i].c){
                sum += p[i].d;
            }
        }
        maxn = max(maxn, sum);
        return;
    }

    for(int i = value; i <= m; i++){
        cnt[dep + 1] = i;
        dfs(dep + 1, i);

    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++){
        cin >> p[i].a >> p[i].b >> p[i].c >> p[i].d;
    }
    dfs(0, 1);
    printf("%d\n", maxn);
  





}