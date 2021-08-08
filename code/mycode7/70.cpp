#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct qu {
    int l, r, t, id, limit;
}q[N];

int block[N], a[N], ans[N], cn[N];
bool cmp(qu x, qu y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return x.l < y.l;
}

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int  vis[N], maxn[N], Max = 0, cnt[N];


void add(int pos) {
    maxn[vis[a[pos]]]--;
    vis[a[pos]]++;
    maxn[vis[a[pos]]]++;
    if (Max < vis[a[pos]]) {
        Max++;
    }
}

void del(int pos) {
    maxn[vis[a[pos]]]--;
    vis[a[pos]]--;
    maxn[vis[a[pos]]]++;
    if (maxn[Max] == 0) Max--;
}



int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back(a[i]);
        block[i] = i / b;
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].t);
        q[i].id = i;
        int limit = (r - l + 1) / q[i].t;
        limit++;
    }
    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
       // cout << " l = " << q[i].l << " r = " << q[i].r << endl;
        while (l > q[i].l) {
           add(--l);

        }
        while (r < q[i].r) {
            add(++r);
        }
        while (l < q[i].l) {
            del(l++); 
        }
        while (r > q[i].r) {
            del(r--);
        }

       
        int res = -1;
        if (Max < limit) {
            ans[q[i].id] = -1;
            continue;
        }
        int sum = 0;
        for (int j = l; j <= r; j ++) {
            sum += cnt[a[j]];
            if (r - sum + 1 < limit) break;
            if (vis[a[j]] >= limit  ) {
        
                res = max(res, g[a[j] - 1]);
               // j += max(limit - 2, 0);
            }
        }
       
       
        ans[q[i].id] = res;
    }

    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }


}
