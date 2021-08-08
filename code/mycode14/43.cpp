#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int a[N], n, dp[N];

#define m (l + r >> 1)
#define ls (node << 1)
#define rs (node << 1 | 1)
int tree[4 * N];

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        if (v == 0) {
            tree[node] = v;
        } else {
            tree[node] = max(tree[node], v);
        }
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls);
    else update(v, pos, m + 1, r, rs);
    tree[node] = max(tree[ls], tree[rs]);
}

int query(int pos, int l, int r, int node) {
    if (l == r) return tree[node];
    if (pos <= m) return query(pos, l , m, ls);
    else return query(pos, m + 1, r, rs);
}

vector<pair<int, int> > temp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                int cnt = query(j, 1, N, 1);
                temp.push_back({cnt, j});
                update(0, j, 1, N, 1);
                if (j != a[i] / j) {
                    cnt = query(a[i] / j, 1, N, 1);
                    temp.push_back({cnt, a[i] / j});
                    update(0, a[i] / j, 1, N, 1);
                }
            }
        }
        dp[i] = max(dp[i], tree[1] + 1);
        for (auto j: temp) {
            update(j.first, j.second, 1, N, 1);
        }
        update(dp[i], a[i], 1, N, 1);
        temp.clear();
    }
    for (int i = 1; i <= n; i++) {
        dp[0] = max(dp[0], dp[i]);
    }
    printf("%d\n", dp[0]);

    
}