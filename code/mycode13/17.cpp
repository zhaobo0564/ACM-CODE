#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;

ll fn[N], base = 147, cnt[N];
int n;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void init() {
    fn[0] = 1;
    for (int i = 1; i <= n; i++) {
        fn[i] = fn[i - 1] * base;
        fn[i] %= mod;
        cnt[i] = (cnt[i - 1] + fn[i]) % mod;
    }


}

struct segment{
    int maxn, ct;
    ll sum;
} tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

int a[N];

void push_up(int node) {
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    if (tree[lson].maxn == tree[rson].maxn) {
        tree[node].ct = tree[lson].ct + tree[rson].ct;
    } else if (tree[lson].maxn == tree[node].maxn) {
        tree[node].ct = tree[lson].ct;
    } else {
        tree[node].ct = tree[rson].ct;
    }
    tree[node].sum = (tree[lson].sum + tree[rson].sum) % mod;
}

void build(int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = a[l];
        tree[node].sum = (a[l] * fn[l]) % mod;
        tree[node].ct = 1;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    push_up(node);
  
}

int flag[4 * N];




void push_down(int node, int l1, int r1, int l2, int r2) {
    if (flag[node]) {
        tree[lson].maxn += flag[node];
        tree[lson].sum = (tree[lson].sum + ((cnt[r1] - cnt[l1 - 1] + mod) % mod) % mod * flag[node] % mod) % mod;
        tree[rson].maxn += flag[node];
        tree[rson].sum = (tree[rson].sum + ((cnt[r2] - cnt[l2 - 1] + mod) % mod) % mod * flag[node] % mod) % mod;
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
}

void update(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        flag[node]++;
        tree[node].maxn++;
        tree[node].sum = (tree[node].sum + cnt[r] - cnt[l - 1]  + mod) % mod;
        return;
    }
    push_down(node, l, m, m + 1, r);
    if (ql <= m) update(ql, qr, l, m, lson);
    if (qr > m) update(ql, qr, m + 1, r, rson);
    push_up(node);

}

void up(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = v;
        tree[node].sum = (fn[l] % mod * tree[node].maxn % mod) % mod;
        return;
    }
    push_down(node, l, m, m + 1, r);
    if (pos <= m) up(v, pos, l, m, lson);
    else up(v, pos, m + 1, r, rson);
    push_up(node);
}
char s[N], t[N];

ll ha[N];

void work(int l, int r, int node) {
    if (tree[node].ct == (r - l + 1)) {

        tree[node].maxn = tree[node].maxn % 26;
      //  cout << "NN " << tree[node].maxn << endl;
        tree[node].sum = ((cnt[r] - cnt[l - 1] + mod) % mod * tree[node].maxn) % mod;
        return;
    }
    push_down(node, l, m, m + 1, r);
    if (tree[lson].maxn > 26) {
        work(l, m, lson);
    }
    if (tree[rson].maxn > 26) {
        work(m + 1, r, rson);
    }
    push_up(node);
    
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node].sum;
    }
    ll ans = 0;
     push_down(node, l, m, m + 1, r);
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    ans %= mod;
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    ans %= mod;
    return ans;
}

int gao() {
    if (tree[1].maxn > 26) {
        work(1, n, 1);
    }
    int l = 1, r = n, ans = 0;
  //  cout << tree[1].sum << " " << ha[n] << endl;
    while (l <= r) {
        ll cnt = query(1, m, 1, n, 1);
        
        if (cnt == ha[m]) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
   

}


int main() {
    int q;
    n = read(), q = read();
    scanf("%s %s", s + 1, t + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] - 'a' + 1;
    }
    init();
    for (int i = 1; i <= n; i++) {
        ll c = t[i] - 'a' + 1;
    
        ha[i] = (ha[i - 1] + (fn[i] % mod * 1ll*(c) % mod) % mod) % mod;
        ha[i] = ha[i] % mod;

    }
    


    build(1, n, 1);
    while (q--) {
        int op = read();
        if (op == 1) {
            int l = read();
            char v; scanf(" %c", &v);
            int w = v - 'a' + 1;
            up(w, l, 1, n, 1);
        } else if (op == 2) {
            int l = read(), r = read();
            update(l, r, 1, n, 1);
        } else {
            printf("%d\n", gao());
        }
    }


}
