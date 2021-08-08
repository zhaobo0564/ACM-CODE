#include<bits/stdc++.h>
using namespace std;

long long mp[1007][1007];
long long cnt[1007][1007];
int n;
long long k;
int main(){
    scanf("%d %lld", &n, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%lld", &mp[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        cnt[i][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%lld ", cnt[i][j] - mp[i][j]);
        }
        puts("");
    }
    
}