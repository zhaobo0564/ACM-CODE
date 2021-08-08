#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int n, q;

char s[N], t[N];

int tree[4 * N][30], flag[4 * N], temp[27];

#define m ((l + r) >> 1)
#define lson (node << 1)
#define rson (node << 1 | 1)

void push_up(int node) {
    for (int i = 0; i <= 25; i++) {
        tree[node][i] = tree[lson][i] + tree[rson][i];
    }
}

void push_down(int node) {
    if (flag[node]) {
        for (int i = 0; i <= 25; i++) {
            temp[i] = tree[lson][i];
        }
        for (int i = 0; i <= 25; i++) {
            tree[lson][(i + flag[node]) % 26] = temp[i];
        }
        for (int i = 0; i <= 25; i++) {
            temp[i] = tree[rson][i];
        }
        for (int i = 0; i <= 25; i++) {
            tree[rson][(i + flag[node]) % 26] = temp[i];
        }
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
}


void build(int l, int r, int node) {
    if (l == r) {
        tree[node][(s[l] - t[l] + 26) % 26] = 1;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    push_up(node);
}

void update(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        for (int i = 0; i <= 25; i++) {
            temp[i] = tree[node][i];
        }
        for (int i = 0; i <= 25; i++) {
            tree[node][(i + 1) % 26] = temp[i];
        }
        flag[node]++;
        return;
    }
    push_down(node);
    if (ql <= m) update(ql, qr, l, m, lson);
    if (qr > m) update(ql, qr, m + 1, r, rson);
    push_up(node);
}

void up(int v, int pos, int l, int r, int node) {
    if (l == r) {
        for (int i = 0; i <= 25; i++) {
            tree[node][i] = 0;
        }
       // cout << v << endl;
        tree[node][v] = 1;
        return;
    }
    push_down(node);
    if (pos <= m) up(v, pos, l, m, lson);
    else up(v, pos, m + 1, r, rson);
    push_up(node);
}

int query(int l, int r, int node) {
    if (l == r) {
        if (tree[node][0] == 1) {
            return l + 1;
        }
        return l;
    }
    push_down(node);
    if (tree[lson][0] == m - l + 1) {
        return query(m + 1, r, rson);
    } else {
        return query(l, m, lson);
    }
}




int main() {
  //  ios::sync_with_stdio(0);
    scanf("%d %d", &n, &q);
    scanf("%s %s", s + 1, t + 1);
    build(1, n, 1);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x;
            char v;
            cin >> x >> v;
            s[x] = v;
            up((s[x] - t[x] + 26) % 26, x, 1, n, 1);
        } else if (op == 2) {
            int l, r; cin >> l >> r;
        
            update(l, r, 1, n, 1);
        } else {
            int ans = query(1, n, 1);
           
            cout << ans - 1<< endl;
        }
    }

}