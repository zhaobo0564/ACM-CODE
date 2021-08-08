#include<bits/stdc++.h>
using namespace std;

const int N = 30007;

#define m (l + r) / 2

int top = 1, tree[40 * N], ls[40 * N], rs[40 * N], flag[40 * N];
int fa[N], sz[N], rt[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

void update(int pos, int v, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        tree[node] += v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, ls[node]);
    else update(pos, v, m + 1, r, rs[node]);
}

void push_down(int node) {
    if (flag[node]) {
        if (ls[node]) {
            tree[ls[node]] += flag[node];   
            flag[ls[node]] += flag[node];
        }
        if (rs[node]) {
            tree[rs[node]] += flag[node];
            flag[rs[node]] += flag[node];
        }
        flag[node] = 0;
    }
}

int query(int pos, int l, int r, int node) {
    if (l == r) {
        return tree[node];
    }
    push_down(node);
    if (pos <= m) return query(pos, l, m, ls[node]);
    else return query(pos, m + 1, r, rs[node]);
}

int merge(int x, int y, int l, int r) {
    if (!x) return y;
    if (!y) return x;
    if (l == r) {
        tree[x] += tree[y];
      // printf("x = %d\n", tree[x]);
        return x;
    }
    push_down(x);
    push_down(y);
    ls[x] = merge(ls[x], ls[y], l, m);
    rs[x] = merge(rs[x], rs[y], m + 1, r);
    return x;
}

int main() {
    int t; scanf("%d", &t);
    int maxn = 30000;
    for (int i = 1; i < N; i++) {
        fa[i] = i;
        sz[i] = 1;
        update(i, 1, 1, maxn, rt[i]);
    }
    //cout << query(1, 1, maxn, rt[1]) << endl;

    while (t--) {
        char op;
        int a, b;
        scanf(" %c %d %d", &op, &a, &b);
        int fx = find(a);
        int fy = find(b);
        if (op == 'M') {
            if (fx != fy) {
                flag[rt[fx]] += sz[fy];
             //   cout << "a " << sz[fy] << endl;
                rt[fy] = merge(rt[fy], rt[fx], 1, maxn);  
                fa[fx] = fy;
                sz[fy] += sz[fx];
            }
        } else {
            if (fx == fy) {
                a = query(a, 1, maxn, rt[fx]);
                b = query(b, 1, maxn, rt[fx]);
             //   printf("a = %d, b = %d\n", a, b);
                printf("%d\n", abs(a - b) - 1);
            } else {
                puts("-1");
            }
        }
    }
}