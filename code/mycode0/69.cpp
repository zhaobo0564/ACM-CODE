#include<bits/stdc++.h>

using namespace std;

char mp[1000][1000];

int n, m, t;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf(" %c", &mp[i][j]);
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                printf("%c", mp[i][j]);
            }
            puts("");
        }

    }
}