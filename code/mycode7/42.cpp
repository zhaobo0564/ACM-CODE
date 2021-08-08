#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e6 + 7;

ll a[N], sum[N], n, m, ans[N], res, vis[N], k;
int l = 1, r = 0;
struct query{
    int l, r, id;
}q[N];

int block[N];
bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return block[x.l] < block[y.l];
}

void add(int pos) {
    res += vis[sum[pos] ^ k];
    vis[sum[pos]]++;
}

void del(int pos) {
    vis[sum[pos]]--;
    res -= vis[sum[pos] ^ k];
}



int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] ^ a[i];
        block[i] = i / b;
    }


    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }

    l = 1, r = 0;
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int f = 0;
        while (l < q[i].l) {
            del(l - 1);
            l++;
        }
        while (l > q[i].l) {
            l--;
            add(l - 1);
        
        }
      
        
        if (r == 0) {
            while (r <= q[i].r) {
                add(r++);
            }
            r--;
        } else {
             while (r < q[i].r) {
                add(++r);
           
            }
        }

        while (r > q[i].r) {
            del(r--);
        }
    
   
       
        
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld\n", ans[i]);
    }




}