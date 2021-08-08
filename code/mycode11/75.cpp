#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 7;

ll n, a[N];
priority_queue<ll> q;

int main() {
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q.push(-a[i]);
    }
    while (q.size() > 1) {
        ll cd = q.top();
        q.pop();
        ll cnt = q.top();
        q.pop();
       // cout << cd << " " << cnt << endl;
        ans += (abs(cd) +  abs(cnt));
        q.push(-(abs(cd) +  abs(cnt)));
    }
    cout << ans << endl;
  
    
}