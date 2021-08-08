#include<bits/stdc++.h>
using namespace std;

const int N = 200007;

long long n, p[N], k;
int vis[N];
long long mod = 998244353;

int main(){
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &p[i]);
    }
    long long sum = ((n - k + 1 +n) * k) / 2;
    for(int i = n - k + 1; i <= n; i++){
        vis[i] = 1;
    }
    int j;
    for(int i = 1; i <= n; i++){
        if(vis[p[i]]){
          j = i;
          break;  
        }
    }
    long long cnt = 0, ans = 1;
    for(int i = j + 1; i <= n; i++){
        cnt++;
        if(vis[p[i]]){
            ans = ans * cnt % mod;
            cnt = 0;
        }
    }
    printf("%lld %lld\n", sum, ans);

}