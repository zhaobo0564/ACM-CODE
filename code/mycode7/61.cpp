#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int vis[N * 50], a[N], sum[N], n, m, block[N], A[N], cat[N];

struct qu {
    int l, r, t, id;
}q[N];

bool cmp(qu x, qu y) {
    if (block[x.l] == block[y.l]) {
        if (block[x.r] == block[y.r]) {
            return x.t < y.t;
        }
        return  x.r < y.r;
    }
    return x.l < y.l;
}

struct option {
    int pos, now, last;
}op[N];

long long res, ans[N];

void add(int pos) {
    res += 1ll*vis[sum[pos]];
    vis[sum[pos]]++;
}

void del(int pos) {
    vis[sum[pos]]--;
    res -= 1ll*vis[sum[pos]];
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        res = 0;
        int b = pow(n, 0.66666666666);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            A[i] = a[i];
            sum[i] = sum[i - 1] ^ a[i];
            cat[i] = sum[i];
            block[i] = i / b;
        }

        int top = 1, cnt = 1;
        for (int i = 1; i <= m; i++) {
            int o, l, r;
            scanf("%d %d", &o, &l);
            if (o == 1) {
                scanf("%d", &r);
                q[top].l = l;
                q[top].r = r;
                q[top].id = top;
                q[top].t = cnt;
                top++;
            } else {
                op[cnt].pos = l;
                op[cnt].now =cat[l - 1] ^ A[l + 1];
                op[cnt].last = cat[l];
                cnt++;
                cat[l] = cat[l - 1] ^ A[l + 1]; 
                swap(A[l], A[l + 1]);
            }
        }
        sort(q + 1, q + top, cmp);
        int l = 1, r = 0, now = 1;
        vis[0] = 1;
     
        for (int i = 1; i < top; i++) {
           
            while (now < q[i].t) {
                int pos = op[now].pos;
                int v = op[now].now;
                if (l - 1 <= pos && r >= pos) {
                    vis[sum[pos]]--;
                    res -= 1ll*vis[sum[pos]];
                    res += 1ll*vis[v];
                    vis[v]++;
                }
                sum[pos] = v;
                now++;
            }

            while (now > q[i].t) {
                now--;
                int pos = op[now].pos;
                int v = op[now].last;
                if (l - 1 <= pos && r >= pos) {
                    vis[sum[pos]]--;
                    res -= 1ll*vis[sum[pos]];
                    res += 1ll*vis[v];
                    vis[v]++;
                }
                sum[pos] = v;
            }
            
            while (l < q[i].l) {
                del(l - 1);
                l++;
            }
            while (l > q[i].l) {
                l--;
                add(l - 1);
            }
            while (r < q[i].r) {
                add(++r);
            }
            while (r > q[i].r) {
                del(r--);
            }
         //   cout << "l " << l <<  " r= " << r << " res = " << res << endl;

            ans[q[i].id] = 1ll*(r - l + 2) * 1ll*(r - l + 1) / 2 - res;
        }
        for (int i = 1; i < top; i++) {
            cout <<ans[i] << endl;
        }
        for (int i = 0; i <= 1024 * 1024; i++) {
            vis[i] = 0;
        }


    }
}