#include<bits/stdc++.h>
using namespace std;
int t, n, m;
char mp[200][200];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m;j++){
                mp[i][j] = 'B';
            }
        }
        mp[n][m] = 'W';
        for(int i = 1; i <= n; i++){
            for(int j= 1; j <= m; j++){
                printf("%c", mp[i][j]);
            }
            puts("");
        }
        
    }

}