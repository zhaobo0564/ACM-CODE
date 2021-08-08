#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 7;
int n, q, a[N];
int vis[N];
set<int> s[N];
int maxn;

struct node {
    int x, y, z, sum, id, f;
}p[N];

bool cmp(node x, node y) {
    if (x.x == y.x) {
        if (x.y == y.y) {
            return x.z < y.z;
        }
        return x.y < y.y;
    }
    return x.x < y.x;
}

#define m (l + r >> 1)

struct msg {
    int x, y, z, sum, id, f, ok;
}g[N];

bool cmp1(msg x, msg y) {
    if (x.y == y.y) {
        return x.f < y.f;
    }
    return x.y < y.y;
}

ll sum[N];
int lowbit(int x) {
    return (x & -x);
}

void add(ll v, int x) {
    while (x <= maxn) {
        sum[x] += v;
        x += lowbit(x);
    }
}

ll query(int x) {
    ll ans = 0;
    while (x > 0) {
        ans += sum[x];
        x -= lowbit(x);
    }
    return ans;
}
ll ans[N];
void work(int l, int r) {
    //cout << "l " << l << " r = " << r << endl;
    if (l == r) return;
    int top = 1;
    for (int i = l; i <= m; i++) {
        g[top++] = {p[i].x, p[i].y, p[i].z, p[i].sum, p[i].id, -1, p[i].f};
    }
    for (int i = m + 1; i <= r; i++) {
        g[top++] = {p[i].x, p[i].y, p[i].z, p[i].sum, p[i].id, 1, p[i].f};
    }
    sort(g + 1, g + top, cmp1);
    for (int i = 1; i < top; i++) {
        if (g[i].f == -1 && g[i].id == 0) {
           // cout << "sum " << g[i].sum << " " << g[i].z << endl;
            add(g[i].sum, g[i].z);
        } else if (g[i].f == 1 && g[i].id != 0) {
        //    cout << "ANS = " << g[i].z << " " << query(g[i].z) << endl;
            ans[g[i].id] += query(g[i].z) * g[i].ok;
        }
    }
    for (int i = 1; i < top; i++) {
        if (g[i].f == -1 && g[i].id == 0) {
            add(-g[i].sum, g[i].z);
        }
    }
    work(l, m);
    work(m + 1, r);
}



int main() {
    scanf("%d %d", &n, &q);
    int top = 1;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[a[i]].insert(i);
    }

    for (int i = 1; i <= n; i++) {
        int x = i;
        int y = vis[a[i]];
        int z = i - vis[a[i]];
        if (vis[a[i]] == 0) {
            z = 0;
        }
        p[top] = {x, y, top, z, 0, 0};
        top++;
        vis[a[i]] = i;
    }
    int o = 1;
    for (int i = 1; i <= q; i++) {
        int op, l, r; 
        scanf("%d %d %d", &op, &l, &r);
      //  cout << "AAA\n";
        if (op == 1) {
            int x = l;
            auto it = s[a[l]].lower_bound(l);
            if (it != s[a[l]].begin()) {
                it--;
                p[top] = {x, *it, top, *it - x, 0, 0};
                top++;
            }
            it = s[a[l]].upper_bound(l);
            if (it != s[a[l]].end()) {
                p[top] = {*it, x, top, x - *it, 0, 0};
                top++;
                int cnt = *it;
                it = s[a[l]].lower_bound(l);
                if (it != s[a[l]].begin()) {
                    it--;
                    p[top] = {cnt, *it, top, cnt - *it, 0, 0};
                    top++;
                }
            }
            it = s[r].lower_bound(l);
            if (it != s[r].begin()) {
                it--;
                p[top] = {l, *it, top, l - *it, 0, 0};
                top++;
                int cnt = *it;
                it = s[r].upper_bound(l);
                if (it != s[r].end()) {
                    p[top] = {*it, cnt, top, cnt - *it, 0, 0};
                    top++;
                }
            }
            it = s[r].upper_bound(l);
            if (it != s[r].end()) {
                p[top] = {*it, l, top, *it - l, 0, 0};
                top++;
            }
            it = s[a[l]].lower_bound(l);
         
            s[a[l]].erase(it);
            s[r].insert(l);
            a[l] = r;
            
        } else {
            int x = l - 1;
            int y = l - 1;
            p[top] = {x, y, top, 0 , o, 1};
            top++;
            x = r , y = r;
            p[top] = {x, y, top, 0, o, 1};
            top++;
            x = l - 1, y = r;
            p[top] = {x, y, top, 0, o, -1};
            top++;
            x = r, y = l - 1;
            p[top] = {x, y, top, 0, o, -1};
            top++;
            o++;
        }
    }
 
    sort(p + 1, p + top, cmp);
    // for (int i = 1; i < top; i++) {
    //     cout << p[i].x << " " << p[i].y << " " << p[i].z << " " << p[i].f << " " << p[i].id << " " << p[i].sum << endl;
    // }
    maxn = top;
    work(1, top - 1);
    for (int i = 1; i < o; i++) {
        cout << ans[i] << endl;
    }

}
