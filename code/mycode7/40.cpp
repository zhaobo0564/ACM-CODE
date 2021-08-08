#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll a[N];

struct node {
    ll a, t, value;

    bool operator <(const node x) const {
        return value < x.value;
    }
};

priority_queue<node>q;

ll gao(ll x, ll y) {
    ll cnt = x / y;
    ll ans = cnt * cnt * y;
    ll mod = x % y;
    ans = ans + 2 * mod * cnt + mod;
    return ans; 

}

int main() {
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    int cnt = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
        q.push({a[i], 2, gao(a[i], 1) - gao(a[i], 2)});
        sum += a[i] * a[i];
        
    }
    while (cnt < k) {
        node cd = q.top();
        q.pop();
        sum -= cd.value;
        q.push({cd.a, cd.t + 1, gao(cd.a, cd.t) - gao(cd.a, cd.t + 1)});
        cnt++;

    }
    cout << sum << endl;


}