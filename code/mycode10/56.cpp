#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int a[N], n;

stack<int> q;
int l[N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

int tree[4 * N];

void build(int l, int r, int node) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = max(tree[lson], tree[rson]);
}
int ans;

int work(int v, int l, int r, int node) {
    if (l == r) {
        return l;
    }
    if (tree[rson] > v) {
        return work(v, m + 1, r, rson);
    }
    return work(v, l, m, lson);
}

void query(int v, int ql, int qr, int l, int r, int node) {
    if (ql > qr) return;
    if (l >= ql && qr >= r) {
        ans = max(ans, work(v, l, r, node));
        return;
    }
    if (ql <= m) query(v, ql, qr, l, m, lson);
    if (qr > m) query(v, ql, qr, m + 1, r, rson);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    for (int i = n; i; i--) {
        while (!q.empty() && a[q.top()] < a[i]) {
            l[q.top()] = i;
            q.pop();
        }
        q.push(i);
    }
    while (q.size()) {
        l[q.top()] = 0;
        q.pop();
    }

    for (int i = 1; i <= n; i++) {
    
        if (l[i] == 0) {
            cout << 1 << endl;
        } else {
            ans = 0;
         //   cout << 1 << " " << l[i] << endl;
            query(a[i], 1, l[i] -1, 1, n, 1);
            cout << ans + 1  << endl;
        }
    }

}