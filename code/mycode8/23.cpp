#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

typedef long long ll;
const ll mod = 1e9 + 7;
int n, m, k;
ll fn[N], Hash[N];

ll a[N];

void init() {
    fn[0] = 1;
    ll d = 27;
    for (int i = 1; i <= n; i++) {
        Hash[i] = (Hash[i - 1]  * d % mod + a[i]) % mod;
        fn[i] = fn[i - 1] * d % mod; 
    }
}

ll get_hash(int l, int r) {
    return (Hash[r] - Hash[l - 1] * fn[r - l + 1] % mod + mod) % mod;
}

int work(int x, int y, int v) {
    int l = 1, r = n / 2, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (get_hash(x, x + mid - 1) == get_hash(y, y + mid - 1)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }


    
    if ((a[x + ans] + v) % m < (a[y + ans] + v) % m) {
        return x;
    }
    return y;
}

vector<int> g[N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        g[a[i]].push_back(i);
        a[i + n] = a[i];
    }
    n += n;
    init();
    

    int ans = 1;
    for (int i = 2; i <= n / 2; i++) {
        ans = work(ans, i, 0);
    }
    printf("%lld\n", a[ans + k - 1]);

    for (int i = 1; i < m; i++) {
        if (g[m - i].size()) {
            for (int j: g[m - i]) {
                ans = work(ans, j, i);
                
            }
        }
        printf("%lld\n", (a[ans + k - 1] + i) % m);
    }



}