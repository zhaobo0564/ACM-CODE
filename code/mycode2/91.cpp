#include<bits/stdc++.h>
using namespace std;
int mp[1007][1007];
int cnt[1007][1007];
int n;

int main(){
    scanf("%d", &n);
    int x, y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &mp[i][j]);
            if(mp[i][j] == -1){
                x = i;
                y = j;
            }
        }
    }
    for(int i = 1; i <= n; i++){
       for(int j = 1; j <= n; j++){
           cnt[i][j] = mp[i][j];
           if(mp[i][j]){
               if(mp[i - 1][j]){
                   
               }
           }
       }
    }
}