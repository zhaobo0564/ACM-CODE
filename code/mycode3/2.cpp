#include<bits/stdc++.h>
using namespace std;

int n, m, x, y;
char mp[1007][1007];

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &m, &x, &y);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf(" %c", &mp[i][j]);
            }
        }
        if(2 * x <= y){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(mp[i][j] == '.'){
                        ans += x;
                    }
                }
            }
            printf("%d\n", ans);
        }else{
            int ans = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(mp[i][j] == '.'){
                        if(mp[i][j + 1] == '.'){
                            ans += y;
                            mp[i][j + 1] = '*';
                        }else{
                            ans += x;
                        }
                    }
                }
            }
            printf("%d\n", ans);
        }
        for(int i = 1; i <= n + 2; i++){
            for(int j = 1; j <= m + 2; j++){
                mp[i][j] = '*';
            }
        }
    }
}