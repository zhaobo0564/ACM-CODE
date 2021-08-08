#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;


ll a[N], n;

struct segment{
    int l, r;
    ll a, b;
}tree[30 * N];

#define m (l + r) / 2

int top = 1;
int an = 0;

void update(ll v1, ll v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        tree[node].a =min(tree[node].a, v1);
        tree[node].b = max(tree[node].b, v);
        return;
    }
    if (pos <= m) update(v1, v, pos, l, m, tree[node].l);
    else update(v1, v, pos, m + 1, r, tree[node].r);
    tree[node].a = min(tree[tree[node].l].a, tree[tree[node].r].a);
    tree[node].b = max(tree[tree[node].l].b, tree[tree[node].r].b);
}

segment query(int ql, int qr, int l, int r, int node) {
    //cout << "l " << l << " r " << r << endl;
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    segment ans;
    ans.a = LLONG_MAX;
    ans.b = 0;

    if (ql <= m) {
        segment cnt = query(ql, qr, l, m, tree[node].l);
        ans.a = min(ans.a, cnt.a);
        ans.b = max(ans.b, cnt.b);
    } 
    if (qr > m) {
        segment cnt = query(ql, qr, m + 1, r, tree[node].r);
        ans.a = min(ans.a, cnt.a);
        ans.b = max(ans.b, cnt.b);
    }
    return ans;
}

vector<ll>g;

ll b[N];

int get_id(ll x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main() {

    ios::sync_with_stdio(0);
    for (int i = 0; i < 30 * N; i++) {
        tree[i].a = LLONG_MAX;
        tree[i].b = LLONG_MIN;
        tree[i].l = tree[i].r = 0;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        b[i] = get_id(a[i]);
    }
    int maxn = 1e9 + 1, rt =0;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        segment cnt = query(1, b[i], 1, maxn, rt);
       // cout << cnt.a << " " << cnt.b << endl;
        ll res = 0;
        if (cnt.a != LLONG_MAX)
            res = a[i] * a[i] + i * i - cnt.a;
        ans = max(ans, res);
        cnt = query(b[i], maxn, 1, maxn, rt);
        if (cnt.b != LLONG_MIN) {

            res = i * i - a[i] * a[i] + cnt.b;
        }
            
      //  cout << res << endl;
        ans = max(ans, res);

        update(i * i + a[i] * a[i], a[i] * a[i] - i * i, a[i], 1, maxn, rt);
        
    }

    cout << ans << endl;


    
    

    

}