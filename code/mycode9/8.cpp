 #include<bits/stdc++.h>

using namespace std;
const int N = 3e5 + 7;

int vis[N], a[N], n, q, k;

int lfi[N], lse[N];

struct node{
    int l, r, id;
};

bool cmp(node x, node y) {
    return x.l > y.l; 
}

vector<node> qu;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1
typedef long long ll;
ll tree[4 * N], flag[4 * N], res[N];

void push_down(int node, int nl, int nr) {
    if (flag[node]) {
        tree[lson] += flag[node] *nl;
        tree[rson] += flag[node] *nr;
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
}

void update(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node] += (r - l + 1);
        flag[node]++;
        return;
    }
    push_down(node, m - l + 1, r - m);
    if (ql <= m) update(ql, qr, l, m, lson);
    if (qr > m) update(ql, qr, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = 0;
    push_down(node, m - l + 1, r - m);
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

deque<int> d[N];

int main() {
    //ios::sync_with_stdio(0);
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lfi[i] = n + 1;
        lse[i] = n + 1;
    }
    lfi[n + 1] = lse[n + 1] = n + 1;
    for (int i = n; i; i--) {
        d[a[i]].push_front(i);
        while (d[a[i]].size() > k + 1) {
            d[a[i]].pop_back();
        }
        if (d[a[i]].size() == k + 1) {
            lse[i] = d[a[i]].back();
            d[a[i]].pop_back();
            lfi[i] = d[a[i]].back();
            
            lfi[i] = min(lfi[i], lfi[i + 1]);
            lse[i] = min(lse[i], lse[i + 1]);
        } else if (d[a[i]].size() == k) {
          //  cout << "AASD " << i << endl;
           // cout << d[a[i]].back() << endl;
            lfi[i] = d[a[i]].back();
            lfi[i] = min(lfi[i], lfi[i + 1]);
            lse[i] = min(lse[i], lse[i + 1]);
        } else {
            lfi[i] = min(lfi[i], lfi[i + 1]);
            lse[i] = min(lse[i], lse[i + 1]);
        }
      
    }
    
    for (int i = 1; i <= n; i++) {
      
        lse[i] = lse[i] - 1;
        if (lfi[i] == n + 1) lfi[i] = 0;  // cout << lfi[i] << " " << lse[i] << endl;
    }
  //  cout << endl;
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        qu.push_back({l, r, i});
    }
    sort(qu.begin(), qu.end(), cmp);
    int pos = n;
    for (int i = 0; i < qu.size(); i++) {

    
        int l = qu[i].l, r = qu[i].r, id = qu[i].id;
        int ll = lfi[l], rr = lse[l];

        while (pos >= l) {
            if (lfi[pos] == 0) {

            } else {
           //     cout << "l = " << lfi[pos] << "r = " << lse[pos] << endl;
               update(lfi[pos], lse[pos], 1, n, 1); 
            }
            pos--;
            
        }
        res[id] = query(l, r, 1, n, 1); 
    }

    for (int i = 1; i <= q; i++) {
        cout << res[i] << endl;
    }



}