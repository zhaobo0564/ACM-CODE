#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long a[N], n, sum[N];

bool judge(long long x){
    long long cnt =  x % n;
    long long cat = x / n;
    for(int i = 1; i <= n; i++){
        sum[i] = 0;
    }
    for(int i = 1; i <= cnt; i++){
        sum[i] = 1;
    }
    long long cn = 0;
    for(int i = 1; i <= n; i++){
        sum[i] += a[i] + cat;
    }
    sort(sum + 1, sum + n + 1);
    long long base = sum[n / 2];
    for(int i = 1; i <= n; i++){
        cn += abs(base - sum[i]);
    }
    if(cn <= x) return true;
    base = sum[n / 2 + 1];
    cn = 0;
    for(int i = 1; i <= n; i++){
        cn += abs(base - sum[i]);
    }
    if(cn <= x)return true;
    return false;
}

int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    long long l = 1, r = 1e14;
    long long ans = 0;
    while(l <= r){
        long long m = (l + r) / 2;
        if(judge(m)){
            r = m - 1;
            ans = m;
        }else{
            l = m + 1;
        }
    }
    printf("%lld\n", ans);
    
}