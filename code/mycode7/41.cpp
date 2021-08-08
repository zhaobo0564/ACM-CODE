#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

struct query {
    int l, r, t, id;
}q[N];

struct option {
    int pos, v;
}p[N], back[N];

int block[N], ans[N], vis[N], maxn[N], n, m, a[N],A[N];

bool cmp (query x, query y) {
    if (block[x.l] == block[y.l]) {
        if (block[x.r] == block[y.r]) {
            return x.t < y.t;
        }
        return block[x.r] < block[y.r];
    }
    return x.l < y.l;
}
vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

void update(int pos, int value) {
    a[pos] = value;
}

void add(int pos) {
 
    maxn[vis[a[pos]]]--;
    vis[a[pos]]++;
    maxn[vis[a[pos]]]++;
}

void del(int pos) {
    maxn[vis[a[pos]]]--;
    vis[a[pos]]--;
    maxn[vis[a[pos]]]++;
}

int main() {
    scanf("%d %d", &n, &m);
    int b = pow(n, 0.666666);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        A[i] = a[i];
        g.push_back(a[i]);
        block[i] = i / b;
    }
   
    int total = 0;
    int cnt = 1;
    for (int i = 1; i <= m; i++) {
        int op; scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d", &q[cnt].l, &q[cnt].r);
            q[cnt].id = i;
            q[cnt].t = total;
            cnt++;
        } else {
            total++;
            scanf("%d %d", &p[total].pos, &p[total].v);
            back[total].v = A[p[total].pos];
            back[total].pos = p[total].pos;
            A[p[total].pos] = p[total].v;
            g.push_back(p[total].v);
        
        }
    }
    
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    for (int i = 1; i <= total; i++) {
        p[i].v = get_id(p[i].v);
        back[i].v = get_id(back[i].v);
    }
    sort(q + 1, q + cnt, cmp);
    int l = 1, r = 0, now = 0;
    for (int i = 1; i < cnt; i++) {
        
        while (now < q[i].t) {
            now++;
            if (p[now].pos >= l && p[now].pos <= r) {
                maxn[vis[a[p[now].pos]]]--;
                vis[a[p[now].pos]]--;
                maxn[vis[a[p[now].pos]]]++;
                maxn[vis[p[now].v]]--;
                vis[p[now].v]++;
                maxn[vis[p[now].v]]++;

            }
            update(p[now].pos, p[now].v);
        }
        while (now > q[i].t) {
            if (l <= back[now].pos && r >= back[now].pos) {
                maxn[vis[a[back[now].pos]]]--;
                vis[a[back[now].pos]]--;
                maxn[vis[a[back[now].pos]]]++;
                maxn[vis[back[now].v]]--;
                vis[back[now].v]++;
                maxn[vis[back[now].v]]++;
            }
            update(back[now].pos, back[now].v);
            now--;
        }
        while (r < q[i].r) {
            add(++r);
        }
        while (l < q[i].l) {
            del(l++);
        }
        while (l > q[i].l) {
            add(--l);
        }
        while (r > q[i].r) {
            del(r--);
        }

        for (int j = 1; j <= 10000; j++) {
            if (maxn[j] == 0) {
                ans[q[i].id] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (ans[i]) {
            printf("%d\n", ans[i]);
        }
    }
}



