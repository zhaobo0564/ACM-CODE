#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int t, n, k;
vector<int>g[N];
int vis[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n ;i++){
            scanf("%d", &k);
            for(int j = 1; j <= k; j++){
                int x; scanf("%d", &x);
                g[i].push_back(x);
            }
        }
        int pos = 1;
        for(int i = 1; i <= n; i++){
            int f = 0;
            for(int j : g[i]){
                if(!vis[j]){
                    vis[j]++;
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                pos = i;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                ans = i;
                break;
            }
        }
        if(ans == 0){
            printf("OPTIMAL\n");
        }else{
            printf("IMPROVE\n");
            printf("%d %d\n", pos, ans);
        }
        for(int i = 1; i<= n; i++){
            vis[i] = 0;
            g[i].clear();
        }
    }
}