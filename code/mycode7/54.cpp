#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

struct query {
    int l, r, t, id;
}q[N];

int block[N], vis[N], a[N], res = 0, A[N], ans[N];

struct option {
    int op, v;
}le[N], ri[N];


bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        if (block[x.r] == block[y.r]) {
            return x.t < y.t;
        }
        return x.r < y.r;
    }
    return x.l < y.l;
}

void add(int pos) {
    if (vis[a[pos]] == 0) {
        res++;
    }
    vis[a[pos]]++;
}
void del(int pos) {
    vis[a[pos]]--;
    if (vis[a[pos]] == 0) {
        res--;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int b = pow(n, 2.0 / 3.0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        A[i] = a[i];
    }
    int top = 1;
    int cnt = 1;
    for (int i = 1; i <= m; i++) {
        char op;
        int l, r;
        scanf(" %c %d %d", &op, &l, &r);
        if (op == 'Q') {
            q[top].l = l;
            q[top].r = r;
            q[top].id = top;
            q[top].t = cnt;
            top++;
        } else {
            ri[cnt].op = l;
            ri[cnt].v = r;
            le[cnt].op = l;
            le[cnt].v = A[l];
            A[l] = r;
            cnt++;
        }
    }
    sort(q + 1, q + top, cmp);
    int l = 1, r = 0, now = 1;
    for (int i = 1; i < top; i++) {
       
        while (now < q[i].t) {    
            if (l <= ri[now].op && ri[now].op <= r) {
                vis[a[ri[now].op]]--;
                if (vis[a[ri[now].op]] == 0) {
                    res--;
                }
                vis[ri[now].v]++;
                if (vis[ri[now].v] == 1) {
                    res++;
                }
            }
            a[ri[now].op] = ri[now].v;
            now++;
        }

        while (now > q[i].t) {
            if (l <= le[now].op && le[now].op <= r) {
                vis[a[le[now].op]]--;
                if (vis[a[le[now].op]] == 0) {
                    res--;
                }
                vis[le[now].v]++;
                if (vis[le[now].v] == 1) {
                    res++;
                }
                a[le[now].op] = le[now].v;
            
            }
            now--;
        }
        while (l < q[i].l) {
            del(l++);
        }
        while (l > q[i].l) {
            add(--l);
        }
        while (r < q[i].r) {
            add(++r);
        }
        while (r > q[i].r) {
            del(r--);
        }
        ans[q[i].id] = res;
    }

    for (int i = 1; i < top; i++) {
        printf("%d\n", ans[i]);
    }

    
}