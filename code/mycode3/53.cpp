#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;
typedef long long ll;
ll a[N], sum[N];
vector<ll>v;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);

    }
    ll ans = 0;
    for(int i = n; i; i--){
        if(a[i] <= 0)break;
        if(a[i] > a[i - 1]){
            ans += a[i];
        }else{
            a[i - 1] = a[i] - 1;
            ans += a[i];

        }
    }
    printf("%lld\n", ans);

}