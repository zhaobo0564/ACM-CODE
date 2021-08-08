#include<bits/stdc++.h>
int n;
const int N = 1007;
char mp[N][N];
char cnt[N][N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf(" %c", &mp[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt[j][i] = mp[n - i + 1][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%c", cnt[i][j]);
        }
        puts("");
    }

}