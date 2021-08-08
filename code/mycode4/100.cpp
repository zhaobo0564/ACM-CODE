#include<bits/stdc++.h>
using namespace std;
int n, m, k;
typedef long long ll;
const int N = 1e5 + 7;
int a[N], b[N];
vector<int>v;

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d", &b[i]);
    }
    for(ll i = 1; i * i <= k; i++){
        if(k % i == 0){
            v.push_back(i);
            if(k / i != i){
                v.push_back(k / i);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < v.size(); i++){
        int cnt = 0, x = 0, y = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] == 1){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt == v[i])x++, cnt--;
        }
        cnt = 0;
        for(int j = 1; j <= m; j++){
            if(b[j] == 1){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt == (k / v[i]))y++, cnt--;
        }
        ans += 1ll * x * y;
    }
    printf("%lld\n", ans);
}