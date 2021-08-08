#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
const ll mod = 1e9 + 7;

struct segment {
    int maxn, minn;
    long long sum, o, mul;
    int min_pos;
    bool ok;

    segment operator +(const segment &n)  {
        segment ans;
        ans.maxn = max(this->maxn, n.maxn);
        ans.minn = min(this->minn, n.minn);
        ans.mul = (this->mul % mod * n.mul % mod) % mod;
        ans.sum = this->sum + n.sum;
        ans.o = this->o ^ n.o;
        ans.ok = this->ok | n.ok;
        ans.min_pos = min(this->min_pos, n.min_pos);
        return ans;
    }

}tree[4 * N];

#define m  (l + r) / 2
#define lson  2 * node
#define rson  2 * node + 1
int a[N];

void build(int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = a[l];
        tree[node].minn = a[l];
        tree[node].sum = tree[node].o = tree[node].mul = a[l]; 
        return;
    }

    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

segment query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    segment ans;
    ans.maxn = 0, ans.minn = INT_MAX, ans.mul = 1, ans.o = 0, ans.sum = 0;
    ans.min_pos = 1000000000,  ans.ok = 0;

    if (ql <= m) {
        ans =ans + query(ql, qr, l, m, lson);
    } 
    if (qr > m) {
        ans =ans + query(ql, qr, m + 1, r, rson);
    }
    return ans;
}

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node].min_pos = v;
        tree[node].ok = false;
        return;
    }

    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos ,m + 1, r, rson);
    tree[node].min_pos = min(tree[lson].min_pos, tree[rson].min_pos);
}

void up(int v, int pos, int l, int r, int node) {
    tree[node].ok = true;
    if (l == r) {
        tree[node].maxn = v;
        tree[node].minn = v;
        tree[node].sum = tree[node].o = tree[node].mul = v;
        return; 
    }

    if (pos <= m) up(v, pos, l, m, lson);
    else up(v, pos, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];

}

int vis[25000007];

long long sum[2 * N], cnt[2 * N], mul[2 * N];

ll ksm(ll x, ll y) {
    x = x % mod;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x;
            base %= mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


int main() {

    
    int n, q;
    n = read(), q = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    mul[0] = 1;
    for (int i = 1; i < 2 * N; i++) {
        sum[i] = sum[i - 1] + i;
        cnt[i] = cnt[i - 1] ^ i;
        mul[i] = (mul[i - 1] * i) % mod;
    }
    build(1, n, 1);

    for (int i = n; i; i--) {
        if (vis[a[i]]) {
           update(vis[a[i]], i, 1, n, 1); 
        } else {
            update(n + 1, i, 1, n, 1);
        }
        
        vis[a[i]] = i;
    }
  
    while (q--) {
        int op, l, r;
       // scanf("%d %d %d", &op, &l, &r);
       op = read(), l = read(), r = read();
        if (op == 1) {
            up(r, l, 1, n, 1);
        } else {
            segment ans = query(l, r, 1, n, 1);
            if (ans.ok) {
                if (ans.maxn - ans.minn == r - l) {
                    r = ans.maxn, l = ans.minn;
                    ll cn = sum[r] - sum[l - 1];
                    ll cn1 = cnt[r] ^ cnt[l - 1];
                    ll inv = ksm(mul[l - 1], 1e9 + 5);
                    ll cn2 = (mul[r] % mod * inv % mod) % mod;

                    if (ans.mul == cn2 && ans.sum == cn && ans.o == cn1) {
                        puts("damushen");
                    } else {
                        puts("yuanxing");
                    }
                } else {
                    puts("yuanxing");
                }

            } else {
                if (ans.maxn - ans.minn == r - l && ans.min_pos > r ) {
                    puts("damushen");
                } else {
                    puts("yuanxing");
                }
            }
        }
    }

    

}