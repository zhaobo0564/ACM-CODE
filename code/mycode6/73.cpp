#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> g[N];
int a[N], n;

typedef long long ll;

struct hjt{
    int l, r, sum;
} tree[40 * N];

int top = 1;
#define m (l + r) / 2

void update(int v, int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].sum += v;
        return;
    }
    if (pos <= m) update(v,pos, tree[last].l, tree[now].l, l, m);
    else update(v, pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}


int rt[N], last[N];
vector<int>vis[N];

ll ans[N];

void dfs(int u, int fa, int deep) {
    if (vis[a[u]].size() == 0) {
        update(1, deep, rt[deep - 1], rt[deep], 1, n);
        vis[a[u]].push_back(deep);
    } else {
        int temp;
        update(-1, vis[a[u]][vis[a[u]].size() - 1], rt[deep - 1], temp, 1, n);
        update(1, deep, temp, rt[deep], 1, n);
        vis[a[u]].push_back(deep);
    }

    if (fa) {
        ll cnt = tree[rt[deep - 1]].sum;
    //     cout << "u " << u << " " << a[u] << endl;
    //     cout <<"fa " << fa << endl;
    //    cout << "cnt " << cnt << endl;
    //    cout << "last " << last[a[u]] << endl;
         ans[u] = ans[fa] + cnt;
        if (last[a[u]])
            ans[u] = ans[u] - last[a[u]];
        last[a[u]] = cnt;
    }

    for (int to: g[u]) {
        if (to == fa) {
            continue;
        } 

        dfs(to, u, deep + 1);
        last[a[to]] = 0;
        vis[a[to]].pop_back();
    }
}


int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int v; scanf("%d", &v);
        g[i].push_back(v);
        g[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    dfs(1, 0, 1);
    for (int i = 2; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
}