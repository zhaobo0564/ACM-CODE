#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

char s[N];
int n;
ll ha[N], p[N], d = 47;
const ll mod = 987654321;

void init() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        ha[i] = (ha[i - 1] * d + s[i]) % mod;  
        p[i] = (p[i - 1] * d) % mod; 
    }
}

ll get_hash(int l, int r) {
    return (ha[r] - ha[l - 1] * p[r - l + 1] % mod + mod) % mod; 
}

vector<ll> g;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    init();

    for (ll i = 1; i <= 20; i++) {
        int cnt = 1ll << i;
        ll ans = 0;
        g.clear();
        for (int j = 1; j <= n; j++) {
            if (j + i > n) break;
            g.push_back(get_hash(j, j + i - 1));
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        //cout << g.size() << endl;
        if (cnt > g.size()) {
            cout << i << endl;
            break;
        }
    }
}