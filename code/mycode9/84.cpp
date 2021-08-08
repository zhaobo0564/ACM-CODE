#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll cnt = min(a, b);
    ll ans = cnt;
    a -= cnt, b-= cnt;
    cnt = min(a, c);
    ans += cnt;
    a -= cnt, c -= cnt;
    ans += c / 2;
    cout << ans << endl;
}