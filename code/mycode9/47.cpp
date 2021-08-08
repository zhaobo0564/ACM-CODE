#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int prime[N],vi[N],top=1;
vector<pair<int, int> > g[N];
typedef long long ll;

int n, a[N], m;


void Prime() {
    for(int i=2;i<N;i++){
        if(!vi[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vi[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

struct query {
    int l, r, id;
}q[N];

int block[N];

bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return x.l < y.l;
}


ll inv[N];
ll MOD = 1e9 + 7;
void init() {
      
    inv[1] = 1;
    for(ll i = 2; i < N; i++)
        inv[i] = inv[MOD % i] * (MOD - MOD / i + MOD) % MOD;

}


ll vis[N], res, ans[N];

ll ksm(ll x, ll y) {
    x = x % MOD;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x % MOD;
        }
        x = x * x % MOD;
        y = y / 2;
    }
    return base % MOD;
}

void add(int pos) {
  //  cout << "pos = " << pos << endl;
    for (int i = 0; i < g[pos].size(); i++) {
        int cnt = g[pos][i].second;
        int va = g[pos][i].first;
     //   cout << "va = " << va << " " << cnt << endl;
        if (vis[va] + 1 != 0)
            res = res * inv[abs(vis[va] + 1)] % MOD;
        vis[va] += cnt;
        
        if (vis[va] + 1 != 0)
            res = res * (vis[va] + 1);
        res = res % MOD;
    }
}

void del(int pos) {
    for (int i = 0; i < g[pos].size(); i++) {
        int cnt = g[pos][i].second;
        int va = g[pos][i].first;
        if (vis[va] + 1 != 0)
            res = res * inv[abs(vis[va] + 1)] % MOD;
        vis[va] -= cnt;
        if (vis[va] +1 != 0)
            res = res * (vis[va] + 1);
        res = res % MOD;
    }
}

int sum[N];


int main() {
    Prime();
    init();
    
    scanf("%d %d", &n, &m);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
       // a[i] = i;
        block[i] = i / b;
    }
    top = 169;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= top; j++) {
            if (a[i] % prime[j] == 0) {
                int cnt = 0;
                while (a[i] % prime[j] == 0) {
                    a[i] = a[i] / prime[j];
                   // g[i].push_back(prime[j]);
                   cnt++;
                }
                g[i].push_back({prime[j], cnt});
            } else if (a[i] < prime[j]) {
                break;
            }
        }
        if (a[i] > 1) {
            g[i].push_back({a[i], 1});
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp);

    int l = 1, r = 0;
    res = 1;

    for (int i = 1; i <= m; i++) {
    //    cout << "l = " << q[i].l << " r = " << q[i].r << endl;
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
        ans[q[i].id] = res;

    }

    for (int i = 1; i <= m; i++) {
        printf("%lld\n", abs(ans[i]));
    }

       


}