#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int vis[100];
int n;
ll a[250007];
ll fn[60];
int v[100];

int main(){
    fn[0] = 1;
    for(int i = 1; i <= 50; i++){
        fn[i] = fn[i - 1] * 2;
    }
    scanf("%d", &n);
    ll minn = LLONG_MAX;
    for(int i = 1; i<= n; i++){
        scanf("%lld", &a[i]);
        ll x = a[i];
        minn = min(minn, x);
        int cnt = 0;
        while(x){
            if(x & 1){
                vis[cnt]++;
            }
            cnt++;
            x = x / 2;
        }
    }
    ll base = 0;
    ll ans = 0;
    do{
        base = 0;
        for(int i = 0; i <= 50; i++){
        if(vis[i]){
            base += fn[i];
            vis[i]--;
        }

    }
    ans += base * base;
    }while(base != 0);
    int f = 0;
    printf("%lld\n", ans);
}