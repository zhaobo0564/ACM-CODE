#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n;
vector<int> g[N];
int tire[300*N][2], top = 1;

void insert(int x) {
    int now = 0;
    for (int i = 22; i >= 0; i--) {
        int pos = 0;
        if ((x & (1 << i))) pos = 1;
        if (!tire[now][pos]) {
            tire[now][pos] = top++;
        }
        now = tire[now][pos];
    }
}

int query(int k, int base, int node) {
    if (k < 0) return 0;
    int pos = 0;
    if ((base & (1 << k))) pos = 1;
   
    if (tire[node][pos ^ 1]) {
 
        return query(k - 1, base, tire[node][pos ^ 1]) + (1 << k);
    } else {
        return query(k - 1, base, tire[node][pos]);
    } 
}

int son[N], sz[N], deep[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    deep[u] = deep[fa] ^ a[u];
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

int ask(int base, int k, int node) {
    if (k < 0) return 0;
    int pos = 0;
    if ((base & (1 << k))) pos = 1;
    if (tire[node][pos ^ 1]) {
  
        int cnt = 0;
        if (pos == 0) cnt = 1 << k; 
        return ask(base, k - 1, tire[node][pos ^ 1]) + cnt;
    } else if (tire[node][pos]){
     
        int cnt = 0;
        if (pos) cnt = 1 << k;
        return ask(base, k - 1, tire[node][pos]) + cnt;
    } else {
        return 0;
    }
}

int find(int x, int k, int node) {

    for (int i = 22; i >= 0; i--) {
        int pos = 0;
        if ((x & (1 << i))) pos = 1;
      //  cout << "k = " << i << " pos = " << pos << " tire " << tire[node][pos] << endl;
        if (tire[node][pos]) {
            node = tire[node][pos];
        } else {
            return false;
        }
    }
    return true;
}

vector<pair<int, int> > cat, all;
int ans = 0;

void gao(int u) {

    for (auto i: cat) {
        int base = i.first ^ a[u];
        ans = max(ans, query(22, base, 0));
       
      
        
        ans = max(ans, i.first ^ deep[u] ^ a[u]);
        // for (auto j: all) {
        //     int base = i.first ^ j.first ^ a[u];
        //     ans = max(ans, base);
        //     // if (ans == 4194303 ) {
        //     //     cout << i.second << " " << j.second << endl;
        //     //     cout << (i.first ^ a[u]) << " " << (ans ^ i.first ^ a[u]) << endl;
        //     //     return;
        //     // }

            
        // }
    }


    
    for (auto i: cat) {
         
        insert(i.first);
        all.push_back({i.first, i.second});
        
    }
    cat.clear();
}

void dfs1(int u, int fa) {
	cat.push_back({deep[u], u});
	for (int to: g[u]) {
		if (to == fa) continue;
		dfs1(to, u);
	}
}

void work(int u, int fa, int zson) {
    cat.push_back({deep[u], u});
    gao(u);
    for (int to: g[u]) {
        if (to == fa || to == zson) continue;
        dfs1(to, u);
        gao(u);
    }
}

void clear() {
    for (int i = 0; i <= top; i++) {
        tire[i][0] = tire[i][1] = 0;
    }
  //  memset(tire, 0, sizeof(tire));
    all.clear();
    top = 1;
}

void solve(int u, int fa, int ok) {
    for (int to: g[u]) {
        if (to == fa || to == son[u]) {
            continue;
        }
        solve(to, u, 1);
    }
    if (son[u]) {
        solve(son[u], u, 0);
    }
    work(u, fa, son[u]);
    if (ok) {
        clear();
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    solve(1, 0, 1);
    printf("%d\n", ans);
    return 0;
}


