#include<bits/stdc++.h>
using namespace std;

int t, n, mp[100][100];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%1d", &mp[i][j]);
            }
        }
        for(int i = 1; i <= n; i++ ){
            mp[n + 1][i] = 1;
            mp[i][n + 1] = 1;
        }
        int f = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mp[i][j]){
                    if(mp[i + 1][j] || mp[i][j + 1]){

                    }else{
                        f = 1;
                        break;
                    }
                }
            }
            if(f) break;
        }
        if(f)puts("No");
        else puts("Yes");
        for(int i = 1; i <= n + 2; i++){
            for(int j = 1; j <= n + 2; j++){
                mp[i][j] = 0;
            }
        }
    }
}