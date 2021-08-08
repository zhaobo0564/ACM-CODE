#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

struct node {
    ll a, b;
}p[N];

ll n, k;



int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }
    sort(p + 1, p + n + 1, [](node x, node y) {
        return x.a < y.a;
    });
    ll now = 0;
    for (int i = 1; i <= n; i++) {
        ll need = p[i].a - now;
        if (need > k) {
            cout << k + now << endl;
            return 0;
        } else {
            k -= need;
            k += p[i].b;
        }
        now = p[i].a;
    }
    cout << now + k << endl;
    return 0;
}