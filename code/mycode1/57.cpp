#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

long long n, t, a[N];

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        long long maxn = 0;
        long long minn = 0;
        long long ans = 0;
        if(a[1] > 0){
            maxn = a[1];
        }else{
            minn = a[1];
        }
        for(int i = 2; i <= n; i++){
            if(maxn && a[i] < 0){
                ans += maxn;
                maxn = 0;
                minn = a[i];
            }else if(minn && a[i] > 0){
                ans += minn;
                minn = 0;
                maxn = a[i];
            }else if(maxn){
                maxn = max(maxn, a[i]);
            }else if(minn){
                minn = max(minn, a[i]);
            }
        }
        if(minn) ans += minn;
        else ans += maxn;
        printf("%lld\n", ans);
        
    }
}