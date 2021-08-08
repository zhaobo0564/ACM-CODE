#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, q, t, top = 1, rt[N];
#define m (l + r) / 2

struct hjt {
    int l, r, sum;
}tree[24 * N];

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}


void update(int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    tree[now].sum++;
    if (l == r) return;
    if (pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
}

int query(int v, int last, int now, int l, int r) {
    if(v == 0) return 0;
    if (l == r) {
        return tree[now].sum - tree[last].sum;
    }
    int ans = 0;
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
    if (v <= m) {
        ans += query(v, tree[last].l, tree[now].l, l, m);
    } else {
        ans += sum;
        ans += query(v, tree[last].r, tree[now].r, m + 1, r);
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        top = 1;
        g.clear();
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            g.push_back(a[i]);
        }
        
        sort(g.begin(), g.end());
        g.push_back(g[0] - 1);
        sort(g.begin(), g.end());
        g.push_back(100000000);
        g.erase(unique(g.begin(), g.end()), g.end());
        
        for (int i = 1; i <= n; i++) {
            int pos  = get_id(a[i]);
            update(pos, rt[i - 1], rt[i], 1, (int)g.size());
        }  
        int last = 0;
        while (q--) {
            int ql, qr, p, k;
            scanf("%d %d %d %d", &ql, &qr, &p, &k);
            int l = 0, r = 1000000, ans;
          
            ql = last ^ ql;
            qr = last ^ qr;
            p = last ^ p;
            k = last ^ k;

            while (l <= r) {
                int down = p - m;
                int up = p + m;
                down = get_id(down);
                down--;
                up = upper_bound(g.begin(), g.end(), up) - g.begin() + 1;
                up--;
                cout <<"down " << down << " " << up << endl;
                if(down > up) down = up;
                int cntl = query(down, rt[ql - 1], rt[qr], 1, (int)g.size());
                int cntr = query(up, rt[ql - 1], rt[qr], 1, (int)g.size());
                int cnt = cntr - cntl ;
                cout << "m " << m << " cnt " << cnt << endl;
                if (cnt >= k) {
                    ans = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            printf("%d\n", ans);
            last = ans;
        }
        for (int i = 0; i <= top; i++) {
            tree[i].l = tree[i].r = tree[i].sum = 0;
        }
        for (int i = 0; i <= n; i++) {
            rt[i] = 0;
        }
    }
}