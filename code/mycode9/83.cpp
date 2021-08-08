#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fn[40];

struct node {
    ll fenzi, fenmu;
};

vector<node> v;

bool cmp(node x, node y) {
  
    return x.fenzi * y.fenmu > y.fenzi * x.fenmu;
    
}

int main() {
    fn[0] = 1;
    for (int i = 1; i <= 32; i++) {
        fn[i] = fn[i - 1] * 2;
    }

    int t; cin >> t;
    while (t--) {
        v.clear();
        ll a, b, n;
        cin >> a >> b >> n;
        for (int i = 0; i <= n; i++) {
            ll cnt = a * i + b;
            ll cn = fn[i];
            v.push_back({cnt, cn});
        }
        sort(v.begin(), v.end(), cmp);
        if (v[0].fenzi == 0) {
            puts("0");
            continue;
        }
        ll g = __gcd(v[0].fenmu, v[0].fenzi);
        g = abs(g);
     
        if (v[0].fenmu / g == 1) {
            printf("%lld\n", v[0].fenzi / g);
            continue;
        }

        printf("%lld/%lld\n", v[0].fenzi / g, v[0].fenmu / g);


    }
}