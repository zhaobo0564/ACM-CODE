#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int n, a[N], rt[N], vis[2 * N];
vector<int> g;

int tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(int v, int pos, int l, int r, int node) {
    if (l ==  r) {
        tree[node] += v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node] = max(tree[lson], tree[rson]);
}



int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main() {
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }



    int  r = 1, res = 0;
    for (int i = 1; i <= n; i++) {
        int maxn = 0;
        while (r <= n) {
            update(1, a[r], 1, n, 1);
            if (r - i + 1 - tree[1] <= k) {
                res = max(res, tree[1]);
            } else {
                update(-1, a[r], 1, n, 1);
                break;
            }
            r++;
            
        }
        update(-1, a[i], 1, n, 1);
        
    }
    cout << res << endl;
    
    
}