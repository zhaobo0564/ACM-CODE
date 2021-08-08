#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
ll a[N];
int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            if(i % 2 == 0)ans += a[i];
        }
        ll maxn = 0;
        ll cnt = 0;
        for(int i = 0; i < n - 1; i += 2){
       
            maxn = max(cnt, maxn);
           if(cnt >= 0){
               cnt += a[i + 1] - a[i];
           }else{
               
                cnt = max(1ll*0, a[i + 1] - a[i]);
           }
        }
        maxn = max(maxn, cnt);
       // cout << maxn << endl;
        cnt = 0;
        for(int i = 1; i < n - 1; i += 2){
            maxn = max(cnt, maxn);
            if(cnt >= 0){
                cnt += a[i] - a[i + 1];
            }else{
                cnt = max(1ll*0, a[i] - a[i + 1]);
            }
        }
        maxn = max(cnt, maxn);
       // cout << ans << "  " << maxn << endl;
        printf("%lld\n", ans + maxn);
    }
}