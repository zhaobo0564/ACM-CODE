#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int tree[20 * N], ls[20 * N], rs[20 * N], top = 1;

int n, k;

#define m (l + r >> 1)


void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node]++;
    if (l == r) return;
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (qr < ql) return 0;
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, ls[node]);
    if (qr > m) ans += query(ql, qr, m + 1, r, rs[node]);
    return ans;
}

struct node {
    int x, r, v;
}p[N];

bool cmp(node x, node y) {
    return x.r > y.r;
}

vector<int> g, v;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int get_ID(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int rt[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        //cin >> p[i].x >> p[i].r >> p[i].v;
        scanf("%d %d %d", &p[i].x, &p[i].r, &p[i].v);
        v.push_back(p[i].x); 
        v.push_back(p[i].x + p[i].r);
        v.push_back(p[i].x - p[i].r) ;      
        g.push_back(p[i].v);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int maxn = v.size();

    sort(p + 1, p + n + 1, cmp);
 
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = p[i].x - p[i].r;
        int r = p[i].x + p[i].r;
        int id = get_id(p[i].v);
        l = get_ID(l);
        r = get_ID(r);
        r = min(r, maxn);
      //  cout << "l " << l << " r = " << r << endl;
        int x = get_ID(p[i].x);
        for (int j = p[i].v - k; j <= p[i].v + k; j++) {
            if (j < 0 || j > 1000000000) continue;
            int ID = get_id(j);
            if (ID - 1 < 0) continue;
            if (g[ID - 1] != j) continue;
            ans += query(l, r, 1, maxn, rt[ID]);
         
  
        }
        
        update(1, x, 1, maxn, rt[id]);
    }
    cout << ans << endl;
    
    
}