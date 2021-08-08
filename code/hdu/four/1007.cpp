#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int t, n;

vector<pair<ll, ll> > g;


int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            ll t, x;
            scanf("%lld %lld", &t, &x);
            g.push_back({t, x});
        }
        sort(g.begin(), g.end(), [](pair<ll, ll> x, pair<ll, ll> y) {
            return x.first < y.first;
        });

        
    }
}