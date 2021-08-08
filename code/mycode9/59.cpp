#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

using namespace std;

struct query {
    int l, r, id, k1, k2;
};

bool cmp(query x, query y) {
    return x.r < y.r;
}

vector<query> g[N];

int L[N], R[N], block[N], n, a[N], q, sum[N];
vector<int> v;

int get_id(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int vis[N], fn[300][N], cat[N], ans[N];

void add(int pos) {

}

void del(int pos) {

}

void solve() {
    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        int 
    }
}



int main() {
    scanf("%d", &n);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        block[i] = i / b;
        L[block[i]] = n + 1;
        R[block[i]] = 0;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int l, r, k1, k2;
        scanf("%d %d %d %d", &l, &r, &k1, &k2);
        g[block[l]].push_back({l, r, k1, k2});
    }
    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        sort(g[block[i]].begin(), g[block[i]].end(), cmp);
    }
    solve();
    for (int i = 1; i <= q; i++) {
        printf("%d\n", v[ans[i] - 1]);
    }   
}