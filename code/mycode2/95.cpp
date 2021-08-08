#include<bits/stdc++.h>
using namespace std;
int mp[1007][1007], n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%lld", &mp[i][j]);
            if(mp[i][j] == -1){
                mp[i][j] = 50000;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int minn = INT_MAX;
        for(int j = 1; j <= n; j++){
            minn = min(minn, mp[i][j]);
        }
        for(int j = 1; j <= n; j++){
            mp[i][j] -= minn;
        }
    }
    for(int i = 1; i <= n; i++){
        int minn = INT_MAX;
        for(int j = 1; j <= n; j++){
            minn = min(minn, mp[j][i]);
        }
        for(int j = 1; j <= n; j++){
            mp[j][i] -= minn;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
           if(mp[i][j]){
                printf("%d\n", 50000 - mp[i][j]);
                return 0;
            }
        }
   
    }
}