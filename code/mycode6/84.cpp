#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll work(ll l , ll r, ll n) {
    ll ans = 0;
    for(ll l=1,r;l<=n;l=r+1) {
        r=n/(n/l);
        ans+=(r-l+1)*(n/l);
    }
    return ans;
}

int main() {
    ll n, m, ans = 0;
    cin >> n >> m;
    ans = work(1, m, n - 1);
    ans = work(1, m, m) - ans;
    
    cout << ans << endl;
}