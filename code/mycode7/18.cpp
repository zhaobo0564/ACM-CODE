#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

char s[N];
int n;

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

int tree[4 * N], tree1[4 * N], flag[4 * N], flag1[4 * N];

void push_down(int node) {
    if (flag[node] ) {
        tree[lson] += flag[node];
        tree[rson] += flag[node];
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
}

void push_down1(int node) {
    if (flag1[node] ) {
        tree1[lson] += flag1[node];
        tree1[rson] += flag1[node];
        flag1[lson] += flag1[node];
        flag1[rson] += flag1[node];
        flag1[node] = 0;
    }
}

void build(int l, int r, int node) {
    if (l == r) {
        tree[node] = l;
        tree1[node] = l;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
}

void update1(int v, int ql, int qr, int l, int r, int node) {
    if (ql > qr) return;
    if (ql <= l && qr >= r) {
        tree1[node] += v;
        flag1[node] += v;
        return;
    }

    push_down1(node);
    if (ql <= m) update1(v, ql, qr, l, m,lson);
    if (qr > m) update1(v, ql, qr, m + 1, r, rson);


}


void update(int v, int ql, int qr, int l, int r, int node) {
    if (ql > qr) return;
    if (ql <= l && qr >= r) {
        tree[node] += v;
        flag[node] += v;
        return;
    }

    push_down(node);
    if (ql <= m) update(v, ql, qr, l, m,lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);


}
void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node] = v;
        return;
    }
    push_down(node);
    if (pos <= m) {
         update(v, pos, l, m, lson);
    }else
    update(v, pos, m + 1, r, rson);
}

void update1(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree1[node] = v;
        return;
    }
    push_down1(node);
    if (pos <= m) {
         update1(v, pos, l, m, lson);
    }else
    update1(v, pos, m + 1, r, rson);
}


int query(int pos, int l, int r, int node) {
    if (l == r) {
        return tree[node];
    }
    push_down(node);
    if (pos <= m) {
        return query(pos, l, m, lson);
    }
    return query(pos, m + 1, r, rson);
}

int query1(int pos, int l, int r, int node) {
    if (l == r) {
        return tree1[node];
    }
    push_down1(node);
    if (pos <= m) {
        return query1(pos, l, m, lson);
    }
    return query1(pos, m + 1, r, rson);
}

vector<char> v;

set<int> pos[200];

int main() {
    cin >> n >> (s + 1);
    build(1, n, 1);
    v.push_back('0');
    for (int i = n; i; i--) {
        v.push_back(s[i]);
    }

    for (int i = 1; i <= n; i++) {
        pos[s[i]].insert(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int p = query(i, 1, n, 1);
        cout << s[p] << " " << v[i] << endl;
        if (s[p] != v[i]) {
            auto it = pos[v[i]].upper_bound(i);
            cout << "*********\n";
            for (auto itt: pos[v[i]]) {
                cout << itt << " ";
            }
            cout << endl;
            int p1 = *it;
            cout << "s " << v[i] << " " << p1 << " " << pos[v[i]].size()<< endl;
            p1 = query1(p1, 1, n, 1);
            pos[v[i]].erase(it);
            cout << "p1 " << p1 << endl;
            ans += p1 - i;
            update(-1, i + 1, p1, 1, n, 1);
            update(p1, i, 1, n, 1);
            update1(1, i, p1 - 1, 1, n, 1);
            update1(i, p1, 1, n, 1);
           




        } else {
             auto it = pos[v[i]].lower_bound(i);

        }
    }

    cout << ans << endl;

    
    
}