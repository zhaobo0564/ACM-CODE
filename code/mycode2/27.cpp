#include<stdio.h>

typedef long long ll;
const int N = 2e5 + 7;

ll left[N], right[N], a[N], b[N];
ll lsum[N], rsum[N];

ll mod = 1000000007;
ll sum[N];

int n, m;

ll work(int l, int r, int x){
    ll ans = 0;
    if(l <= x && r >= x){
        ans = (left[x] + right[x]) % mod;
        ll cnt = left[l] % mod;
        cnt %= mod;
        cnt += right[r]  % mod;
        cnt %= mod;
        ans = (ans - cnt + mod) % mod;
    }else if(x < l){
        ans = right[l] - right[r];
        ll cn = lsum[r] - lsum[l - 1];
        ans = (ans + mod) % mod;
       // printf("ans = %lld\n", ans);
        ll cnt = (sum[l - 1] - sum[x - 1] + mod ) % mod;
      //  printf("cnt = %lld\n", cnt);
        ans += cn * cnt % mod;
        ans %= mod;
    }else if(x > r){
        ans = right[r] - right[l];
        ll cn = rsum[l] - rsum[r + 1];
        ans = (ans + mod) % mod;
        ll cnt = (sum[x - 1] - sum[r - 1] + mod) % mod;
        ans += cn * cnt % mod;
        ans %= mod;
    }
    return ans;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i < n; i++){
        scanf("%lld", &a[i]);
        sum[i] = (sum[i - 1] + a[i]) % mod;
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld", &b[i]);
        lsum[i] = (lsum[i - 1] + b[i]) % mod;
    }
    for(int i = 2; i <= n; i++){
        left[i] =left[i - 1] + lsum[i - 1] * a[i - 1];
        left[i] %= mod;
    }
    for(int i = n; i; i--){
        rsum[i] = (rsum[i + 1] + b[i]) % mod;
    }
    for(int i = n - 1; i; i--){
    //    printf("%lld %lld\n", rsum[i + 1], a[i]);
        right[i] =right[i + 1] + rsum[i + 1] * a[i] % mod;
        right[i] %= mod;
    }

    // for(int i = 1; i <= n; i++){
    //     printf("%lld ", right[i]);
    // }
    // puts("");

    while(m--){
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        printf("%lld\n", work(l, r, x));
    }    
   
}
