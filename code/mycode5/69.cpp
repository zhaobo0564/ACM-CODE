#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

int n;
ll a[N], b[N];

struct hjt{
    int sum, l, r;
}tree[24 * N];

int top = 1, rt[N];
#define m (l + r) / 2

void update(int pos, int last, int &now, int l, int r){
    now = top++;
    tree[now] = tree[last];
    tree[now].sum++;
    if(l == r)return;
    if(pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
}

int query(int k, int last, int now, int l, int r){
    if(l == r)return l;
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
    if(sum >= k) return query(k, tree[last].l, tree[now].l, l, m);
    return query(k - sum, tree[last].r, tree[now].r, m + 1, r);
}

vector<int>g;

int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

// int main(){
//     int n, q; scanf("%d %d", &n, &q);
   
//     for(int i = 1; i <= n; i++){
//         scanf("%d", &a[i]);
//         g.push_back(a[i]);
//     }
//     sort(g.begin(), g.end());
//     g.erase(unique(g.begin(), g.end()), g.end());
//     n = g.size();
//     for(int i = 1; i <= n; i++){
//         int pos = get_id(a[i]);
//         update(pos, rt[i - 1], rt[i], 1, n);
//     }
//     while(q--){
//         int l, r, k;
//         scanf("%d %d %d", &l, &r, &k);
//         printf("%d\n", g[query(k, rt[l - 1], rt[r], 1, n) - 1]);
//     }
// }

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        top = 1;
        g.clear();
        int l, k;
        scanf("%d %d %d", &n, &l, &k);
        for (int i = 1; i <= n; i++) rt[i] = 0, b[i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int id = n;
        for (int i = 1; i <= n; i += l) {
            for (int j = i - (l - k) - 1; j <= i + l - 1; j++) {
                b[j] = a[id--];
            }

        }

        for (int i = 1; i <= n; i++) {
            if (b[i] == 0) {
                b[i] = a[id--];
            }
        }
        for (int i = 1; i <= n; i++) {
            g.push_back(b[i]);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        for(int i = 1; i <= n; i++){
            int pos = get_id(b[i]);
            update(pos, rt[i - 1], rt[i], 1, g.size());
        }
        ll ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int ll = i, r = i + l  - 1;
            if (r > n) break;
            ans += g[query(l - k + 1, rt[ll - 1], rt[r], 1, g.size()) - 1];
        }
        int cat = k;
        k = l - k + 1;
        for (int i = 1; i < top; i++) {
            tree[i].l = tree[i].r = tree[i].sum = 0;
        }
        top = 1;
        id = 1;
        for (int i = 1; i <= n; i++)b[i] = 0, rt[i] = 0;
         for (int i = 1; i <= n; i += l) {
            for (int j = i - (l - k) - 1; j <= i + l - 1; j++) {
                b[j] = a[id++];
            }

        }
        for (int i = 1; i <= n; i++) {
            if (b[i] == 0) {
                b[i] = a[id++];
            }
        }
    
     
        for(int i = 1; i <= n; i++){
            cout << b[i] << " ";
            int pos = get_id(b[i]);
            update(pos, rt[i - 1], rt[i], 1, g.size());
        }
        cout << endl;
         ll ans1 = 0;
    
        for (int i = 1; i <= n; i++) {
            int ll = i, r = i + l - 1;
            if (r > n) break;
            ans1 += g[query(l - k + 1, rt[ll - 1], rt[r], 1, g.size()) - 1];
        }
        printf("%lld %lld\n", ans, ans1);
        for (int i = 1; i < top; i++) {
            tree[i].l = tree[i].r = tree[i].sum = 0;
        }
    }
}