#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int vis[N];
vector<int> g[40];
int a[N], m, t;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            scanf("%d", &a[i]);
            g[a[i]].push_back(i);
        }
        long long c = 1; 
        int f = 0;
        for(int i = 30 ; i >= 0; i--){
            if(g[i].size() >= c){
                f = 1;
                for(int j = 0; j < c; j++){
                    vis[g[i][j]] = 1;
                }
                break;
            }else if(g[i].size()){
                for(int j: g[i]){
                    vis[j] = 1;
                }
                c -= g[i].size();
                c = c * 2;
            }else{
                c = c * 2 ;
            }
        }
        if(!f){
            printf("impossible\n");
        }else{
            for(int i = 1; i <= m; i++){
                printf("%d", vis[i]);
            }
            puts("");
        }
        
        for(int i = 1; i <= m; i++){
            vis[i] = 0;
        }
        for(int i = 0; i <= 30; i++){
            g[i].clear();
        }
    }
}