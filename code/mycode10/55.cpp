#include<bits/stdc++.h>
using namespace std;

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

const int N = 1e5 + 7;

struct segment {
    int sum;
    vector<int> v;
}tree[4 * N];
int a[N];

void update(int v, int value, int pos, int l, int r, int node) {
    tree[node].sum += v;
    if (l == r) {
        if (f == 1)
            tree[node].v.push_back(value);
        else 
            tree[node].v.pop_back();
        return;
    }
    if (pos <= m) update(v, value, pos, l, m, lson);
    else update(v, value, pos, m + 1, r, rson);
}

pair<int , int> query(int l, int r, int node) {
    if (l == r) return {tree[node].sum, tree[node].v[0]};
    if (tree[rson].sum > 0) {
        return query(m + 1, r, rson);
    } 
    return query(l, m, lson);

}

int vis[2 * N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[a[i]] == n) {
            cout << -1 << endl;
            return 0;
        }
    }

    int maxn = 0, ans;

    for (int i = 1; i <= n; i++) {
        if (vis[a[i]]) {
            if (maxn < vis[a[i]]) {
                maxn = vis[a[i]];
                ans = a[i];
            }
        }
    }
    cout << ans << endl;
 

}