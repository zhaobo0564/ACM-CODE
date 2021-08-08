#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 7;

struct query {
    int l, r, t, id;
}q[N];

int block[N], vis[N], a[N], res = 0, A[N], ans[N];

struct option {
    int op, v;
}le[N], ri[N];


bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        if (block[x.r] == block[y.r]) {
            return x.t < y.t;
        }
        return x.r < y.r;
    }
    return x.l < y.l;
}

void add(int pos) {
    if (vis[a[pos]] == 0) {
        res++;
    }
    vis[a[pos]]++;
}
void del(int pos) {
    vis[a[pos]]--;
    if (vis[a[pos]] == 0) {
        res--;
    }
}

struct hjt{
    int l, r;
    int sum;
}tree[15 * N];

int n, rt[N], to = 1;


#define m  (l + r) / 2

void update(int v, int pos,int last, int &now, int l, int r){
    now = to++;  
    tree[now] = tree[last];  
    if(l == r){ 
        tree[now].sum = v;
        return;
    } 
    if(pos <= m) update(v, pos, tree[last].l, tree[now].l, l, m);
    else update(v, pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

int query(int now, int ql, int qr, int l, int r){
    if(ql <= l && qr >= r) return tree[now].sum;
    int ans = 0; 
    if(ql <= m) ans += query(tree[now].l, ql, qr, l, m);
    if(qr > m) ans += query(tree[now].r, ql, qr, m + 1, r);
    return ans;
}

int vi[N];
vector<int> cao;

int main() {
    int n, Q;
    scanf("%d %d", &n, &Q);
    int b = sqrt(n);
    //cout << 1ll*b * n << endl;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        A[i] = a[i];
    }
    for(int i = 1; i <= n; i++){
        if(vi[a[i]] == 0){
            update(1, i, rt[i - 1], rt[i], 1, n); 
            vi[a[i]] = i;
        }else{
            int temp; 
            update(0, vi[a[i]], rt[i - 1], temp, 1, n); 
            update(1, i, temp, rt[i], 1, n);
            vi[a[i]] = i;
        }
    }
    int top = 1;
    int cnt = 1;
    int base = 10000007;
    for (int i = 1; i <= Q; i++) {
        int op;
        int l, r;
        scanf("%d %d", &op, &l);
        if (op == 2) {
            scanf("%d", &r);
            cao.push_back(i);
            int res = query(rt[r], l, r, 1, n);
          //  cout << res << endl;
            if (res == r - l + 1) {
                ans[i] = 0;
                continue;
            }
            q[top].l = l;
            q[top].r = r;
            q[top].id = i;
            q[top].t = cnt;
            top++;
        } else {
            ri[cnt].op = l;
            ri[cnt].v = r;
            le[cnt].op = l;
            le[cnt].v = A[l];
            A[l] = base++;
            cnt++;
        }
    }
    sort(q + 1, q + top, cmp);
    int l = 1, r = 0, now = 1;
    for (int i = 1; i < top; i++) {
       
        while (now < q[i].t) {    
            if (l <= ri[now].op && ri[now].op <= r) {
                vis[a[ri[now].op]]--;
                if (vis[a[ri[now].op]] == 0) {
                    res--;
                }
                vis[ri[now].v]++;
                if (vis[ri[now].v] == 1) {
                    res++;
                }
            }
            a[ri[now].op] = ri[now].v;
            now++;
        }

        while (now > q[i].t) {
            if (l <= le[now].op && le[now].op <= r) {
                vis[a[le[now].op]]--;
                if (vis[a[le[now].op]] == 0) {
                    res--;
                }
                vis[le[now].v]++;
                if (vis[le[now].v] == 1) {
                    res++;
                }
                a[le[now].op] = le[now].v;
            
            }
            now--;
        }
        while (l < q[i].l) {
            del(l++);
        }
        while (l > q[i].l) {
            add(--l);
        }
        while (r < q[i].r) {
            add(++r);
        }
        while (r > q[i].r) {
            del(r--);
        }
        if (res == q[i].r - q[i].l + 1) {
            ans[q[i].id] = 0;
        } else {
            ans[q[i].id] = 1;
        }
        
    }

    for (int i: cao) {
        printf("%d\n", ans[i]);
    }

    
}