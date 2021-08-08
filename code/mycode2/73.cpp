#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[100007];

multiset<long long>v;


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        v.insert(a[i]);
    }
    long long maxn = 0;
    for(int i = 1; i <= n; i++){
        auto it = v.lower_bound(a[i]);
        v.erase(it);
        v.insert(a[i] + 1ll *i * m);
        auto ans = v.end();
        ans--;
        auto ans1 = v.begin();
        maxn = max(maxn, *ans - *ans1);
        it = v.lower_bound(a[i] + 1ll*i * m);
        v.erase(it);
        v.insert(a[i] - 1ll * i * m);
        ans = v.end();
        ans--;
        ans1 = v.begin();
        maxn = max(maxn, *ans - *ans1);
        it =v.lower_bound(a[i] - 1ll * i * m);
        v.erase(it);
        v.insert(a[i]);
    }
    printf("%lld\n", maxn);

   
    
}