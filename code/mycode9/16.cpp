#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
#define ll long long
int n, a[N];
ll tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(int pos, int v, int l, int r, int node) {
    if (l == r) {
        tree[node] += 1ll*v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql > qr) return 0;
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans; 
}

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}


inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        //scanf("%d", &a[i]);
        a[i] = n - i;
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    int maxn = g.size() + 1;
    __int128 ans = 0;
    for (ll i = 1; i <= n; i++) {
        __int128 cnt = query(a[i] + 1, maxn, 1, maxn, 1);
      //  cout << "sum " << cnt << " len = " << n - i + 1 << endl;
        cnt = cnt * 1ll*(1ll*n - 1ll*i + 1ll*1);
        ans += cnt;
        update(a[i], i, 1, maxn, 1);
    }
    write(ans)

    
}