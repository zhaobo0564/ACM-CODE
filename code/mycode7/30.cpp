#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1000005;

struct pr{
    ll a,b;
    bool operator < (const pr &x){  // 按照a从大到小排序
        return a > x.a;
    }
} s[N];

ll n,m,a[N],b[N],c[N],d[N];

void solve(){
    cin>>n>>m;
    /*
    如果达到最优，其中所取的b[i]必然相同的花或根本没取b[i]。
    枚举每一种a[i]，先取a[i]，再取所有比b[i]大的a[]，
    再取剩余该取的b[i]。每次枚举都更新答案，最后得到最优解。
    */

    for(ll i=0;i<=m+2;i++) a[i]=b[i]=c[i]=d[i]=0;
    for(ll i=1;i<=m;i++) cin>>s[i].a>>s[i].b;
    sort(s+1,s+m+1);
    for(ll i=1;i<=m;i++) a[i]=s[i].a, b[i]=s[i].b, d[i]=-a[i];
    for(ll i=1;i<=m;i++) c[i]=c[i-1]+a[i];
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ll pos=lower_bound(d+1,d+m+1,-b[i])-d-1;   // 二分查找的自带函数
        pos=min(pos,n-1);
        if(i<=pos && pos<n-1 && pos<m && a[pos+1]>b[i]) ++pos;
        ll tmp=c[pos], fg=0;
        if(i<=pos) tmp-=a[i], fg=1;
        tmp+=a[i]+b[i]*(n-1-pos+fg);
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}

