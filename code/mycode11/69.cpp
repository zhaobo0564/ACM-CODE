#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

ll eular(ll n){
    ll ans = n;
    for(int i=2; i*i <= n; ++i){
        if(n%i == 0){
            ans = ans/i*(i-1);
            while(n%i == 0)
                n/=i;
        }
    }
    if(n > 1) ans = ans/n*(n-1);
    return ans;
}


void solve(int t) {
    int n; cin >> n;
    ll ans = 3;
    for (int i = 2; i <= n; i++) {
        ans += eular(i) * 2;
    }


    cout << t << " " << n << " " << ans << endl;


}
 

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

}