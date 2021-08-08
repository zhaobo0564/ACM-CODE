#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
ll n, k, a[N];

vector<ll>v;
map<ll, int>q;


int main(){
    int t; scanf("%d", &t);
    while(t--){
        v.clear();
        q.clear();
        scanf("%lld %lld", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            if((a[i] % k) != 0){
                v.push_back(a[i] % k);
            }
        }
        if(v.size() == 0){
            printf("0\n");
            continue;
        }
        for(int i = 0; i < v.size(); i++){
            q[v[i]]++;
        }
        ll ans = 0;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(int i = 0; i < v.size(); i++){
            ll cnt = q[v[i]];
            ll cat = (k - v[i]) + (cnt - 1) * k;
            ans = max(ans, cat);
        }
        
        ans++;
        printf("%lld\n", ans);
    }
}