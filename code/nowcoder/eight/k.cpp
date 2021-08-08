#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 1e5 + 7;
 
ll n, a[N], b[N], sum[N];
 
#define m (l + r) / 2
#define lson  2 * node
#define rson 2 * node + 1
 
struct sumtree{
    ll w, pos;
}tree[4 * N];
 
void build(int l, int r, int node) {
    if (l ==  r) {
        tree[node].w = sum[l];
        tree[node].pos = l;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    if (tree[lson].w >= tree[rson].w) {
        tree[node].w = tree[lson].w;
        tree[node].pos = tree[lson].pos;
    } else {
        tree[node].w = tree[rson].w;
        tree[node].pos = tree[rson].pos;
    }
}
 
int pos = INT_MAX;
ll ans = LLONG_MIN;
 
void query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        if (ans < tree[node].w) {
            ans =  tree[node].w;
            pos = tree[node].pos;
        }
        return;
    }
    if (ql <= m) query(ql, qr, l, m, lson);
    if (qr > m) query(ql, qr, m + 1, r, rson);
}
 
struct mintree{
    ll minn;
    int pos;
}tree1[4 * N];
 
ll add[4 * N];
 
void build1(int l, int r, int node) {
    if (l == r) {
        tree1[node].minn = b[l];
        tree1[node].pos = l;
        return;
    }
    build1(l, m, lson);
    build1(m + 1, r, rson);
    if (tree1[lson].minn <= tree1[rson].minn) {
        tree1[node].minn = tree1[lson].minn;
        tree1[node].pos = tree1[lson].pos;
    } else {
        tree1[node].minn = tree1[rson].minn;
        tree1[node].pos = tree1[rson].pos;
    }
}
 
void push_up(int node) {
    if (add[node] != 0) {
        tree1[lson].minn += add[node];
        tree1[rson].minn += add[node];
        add[lson] += add[node];
        add[rson] += add[node];
        add[node] = 0;
    }
}
 
void update1(ll v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree1[node].minn += v;
        add[node] += v;
        return;
    }
    push_up(node);
    if (ql <= m) update1(v, ql, qr, l, m, lson);
    if (qr > m) update1(v, ql, qr, m + 1, r, rson);
    if (tree1[lson].minn <= tree1[rson].minn) {
        tree1[node].minn = tree1[lson].minn;
        tree1[node].pos = tree1[lson].pos;
    } else {
        tree1[node].minn = tree1[rson].minn;
        tree1[node].pos = tree1[rson].pos;
    }
     
}
 
int pos1;
ll ans1 = LLONG_MAX;
void query1(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        if (ans1 > tree1[node].minn) {
            ans1 = tree1[node].minn;
            pos1 = tree1[node].pos;
        }
        return;
    }
    push_up(node);
    if (ql <= m) query1(ql, qr, l, m, lson);
    if (qr > m) query1(ql, qr, m + 1, r, rson);
 
}
inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
 
int main() {
    int t; scanf("%d", &t);
    int ca = 1;
    while (t--) {
        scanf("%lld", &n);
        memset(add, 0, sizeof(add));
         
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &b[i]);
        }
        build(1, n, 1);
        build1(1, n, 1);
        int l = 1, r = n;
        __int128 res = 0;
        ll pepole = 0;
        while (l <= r) {
          //  cout << "l " << l<< " r " << r << endl;
            ans = LLONG_MIN;
            pos = -1;
            query(l, r, 1, n, 1);
          //  cout << "ans " << ans << " pos " << pos << endl;
            ans1 = LLONG_MAX;
            pos1 = -1;
            query1(l, pos, 1, n, 1);
           // cout << "ans1 " << ans1 << " pos " << pos << endl;
            if (ans1 > 0) {
                __int128  a1 = ans1;
                __int128 an = ans;
                res += a1 * an;
                pepole += ans1;
                update1(-ans1, l, pos, 1, n, 1);
                r = pos1 - 1;
            }
             
        }
        printf("Case #%d: %lld ", ca++, pepole);
        write(res);
        puts("");

    }
}