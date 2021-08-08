#include<bits/stdc++.h>
using namespace std;
long long n;

int vis[100];

int main(){
    scanf("%lld", &n);
    int cnt = 0;
    long long x = n;
    while(n){
        if(n & 1) vis[cnt] = 1;
        n = n / 2;
        cnt++;
    }
    int f = 0;
    for(int i = cnt - 1; i >= 0; i--){
        if(vis[i] == 0){
            f = 1;
            break;
        }
    }
    if(f == 0){
        printf("%lld\n", x - 1);
        return 0;
    }
   long long ans = (1ll * 1 << cnt ) - 1;
   printf("%lld\n", ans);
}