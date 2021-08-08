#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;


#define int unsigned int

int n, m, q;


short a[N], b[N];

int res = 0;

bool flag[2 * N];


struct segment {
    int32_t dp[64];
    int l, r;
}tree[2 * N];




int32_t temp[67], ans[67];
int top = 1;

int sum = 0;

int build(int l, int r) {
    int node = top++;
    if (l == r) {
        for (int i = 0; i < m; i++) {
            tree[node].dp[i] = -1;
        }
        tree[node].dp[a[l]] = (int32_t)b[l];
 
        tree[node].dp[0] = max(tree[node].dp[0], 0);

        return node;
    }
    int mid = (l + r) >> 1;
    tree[node].l = build(l, mid);
    tree[node].r = build(mid + 1, r);

    for (int i = 0; i < m; i++) tree[node].dp[i] = -1;
    for (int  i = 0; i < m; i++) {
        if (tree[tree[node].l].dp[i] > -1) {
            for (int j = 0; j < m; j++) {
                if (tree[tree[node].r].dp[j] > -1 && (i ^ j) < m) {
                    tree[node].dp[i ^ j] = max(tree[node].dp[i ^ j], tree[tree[node].l].dp[i] + tree[tree[node].r].dp[j]);
                }
            }
        }
    }
    return node;
    
}



void update(int ql, int qr, int l, int r, int node) {
  
    if (ql <= l && qr >= r) {

        
        int f = 0;
        for (int i = 0; i < m; i++) {
            if (ans[i] == -1) {
                f++;
            } else {
                break;
            }
        }
        if (f == m) {

            for (int i = 0; i < m; i++) {
               
                
                ans[i] = tree[node].dp[i];
            }
        } else {
    
            for (int i = 0; i < m; i++) {
                temp[i] = ans[i];
            }
            for (int i = 0; i < m; i++) {
             
                if (ans[i] < 0) continue;
                for (int j = 0; j < m; j++) {
                    if (tree[node].dp[j] >= 0) {
                        if ((i ^ j) >= m) continue;
                        temp[i ^ j] = max(temp[i ^ j], tree[node].dp[j] + ans[i]);
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                ans[i] = temp[i];
            }
        }
      
        return;
    }


    int mid = (l + r) >> 1;
    if (ql <= mid) update(ql, qr, l, mid, tree[node].l);
    if (qr > mid) update(ql, qr, mid + 1, r, tree[node].r);


}
 int rt = 0;
void work(int l, int r, int x) {
    for (int i = 0; i < m; i++) {
        ans[i] = -1;
    }
    update(l, r, 1, n, rt);
    for (int i = 0; i < m; i++) {
         res = res + (ans[i] * (x ^ i));
    }
}

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int32_t main() {


    //ios::sync_with_stdio(0);
    //cin >> n >> m >> q;
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) {
       // cin >> a[i] >> b[i];
       a[i] = read(), b[i] = read();
    }
    rt = build(1, n);

    int k = 1;
    int sum = 0;
    while (q--) {
        res = 0;
        int l, r;
        int x;
        cin >> l >> r >> x;
        l++, r++;
        work(l, r, x);
        sum += res ^ k;
        //cout << res << endl;
        k++;    
        
    }
  
    cout << sum << endl;
}


