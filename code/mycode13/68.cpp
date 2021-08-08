#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
ll a[N], n;

struct node {
    int x, y, z, w, id;
}p[N];

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

bool cmp(node x, node y) {
    if (x.x == y.x) {
        if (x.y == y.y) {
            if (x.z == y.z) {
                return x.w < y.w;
            } 
            return x.z < y.z;
        }
        return x.y < y.y;
    }
    return x.x < y.x;
}
#define m (l + r >> 1)

struct msg{
    int x, y, z, w, f, id;
}g[N];

vector<int> G, G1;

int get_id(int x) {
    return lower_bound(G.begin(), G.end(), x) - G.begin() + 1;
}

int get_id1(int x) {
    return lower_bound(G1.begin(), G1.end(), x) - G1.begin() + 1;
}

int rt[N], tree[40 * N], ls[40 * N], rs[40 * N];

int lowbit(int x) {return x & -x;};

int o = 1;
inline void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = o++;
    if (l == r) {
        if (v == 0)
            tree[node] = v;
        else tree[node] = max(tree[node], v);
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
    tree[node] = max(tree[ls[node]], tree[rs[node]]);
}

inline int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = 0;
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, ls[node]));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rs[node]));
    return ans;
}

inline void add(int v, int pos, int x) {
    while (x <= G.size()) {
        update(v, pos, 1, G1.size(), rt[x]);
        x += lowbit(x);
    }
}

inline int qu(int pos, int x) {
    int ans = 0;
    while (x > 0) {
        ans = max(ans, query(1, pos, 1, G1.size(), rt[x]));
        x -= lowbit(x);
    }
    return ans;
}

inline bool cmp1(msg x, msg y) {
    if (x.y == y.y) {
        return x.f < y.f;
    }
    return x.y < y.y;
}

int dp[N];

inline void work(int l, int r) {
    if (l == r) return;
    work(l, m);
    int  top = 1;
    for (int i = l; i <= m; i++) {
        g[top++] = {p[i].x, p[i].y, p[i].z, p[i].w, -1, p[i].id};
    
    }
    for (int i = m + 1; i <= r; i++) {
         g[top++] = {p[i].x, p[i].y, p[i].z, p[i].w, 1, p[i].id};
     
    }
    sort(g + 1, g + top, cmp1);
    for (int i = 1; i < top; i++) {
        if (g[i].f == -1) { 
            add(dp[g[i].id], g[i].w, g[i].z);
        } else {
            dp[g[i].id] =max(dp[g[i].id],  qu(g[i].w, g[i].z) + 1);
        
        }
    }
    for (int i = 1; i < top; i++) {
        if (g[i].f == -1) {
            add(0, g[i].w, g[i].z);
        }
    }
    work(m + 1, r);
}

int main() {
 
    //scanf("%d", &n);
    n = read();
    for (int i = 1; i <= n; i++) {
       // cin >> p[i].x >> p[i].y >> p[i].z >> p[i].w;
       // scanf("%d %d %d %d", &p[i].x, &p[i].y, &p[i].z, &p[i].w);
       p[i].x = read();
       p[i].y = read();
       p[i].z = read();
       p[i].w = read();
        G.push_back(p[i].z);
        G1.push_back(p[i].w);
        p[i].id = i;
        dp[i] = 1;
    }
    sort(G.begin(), G.end());
    G.erase(unique(G.begin(), G.end()), G.end());
    sort(G1.begin(), G1.end());
    G1.erase(unique(G1.begin(), G1.end()), G1.end());
    for (int i = 1; i <= n; i++) {
    
        p[i].z = get_id(p[i].z);
        p[i].w = get_id1(p[i].w);
      //  cout << p[i].x << " " << p[i].y << " " << p[i].z << " " << p[i].w << endl;
    }
    sort(p + 1, p + n + 1, cmp);
    work(1, n);
    for (int i = 1; i <= n; i++) {
        dp[0] = max(dp[0], dp[i]);
    }
    printf("%d\n", dp[0]);
   


}

/*
10
12 5 4 22
25 6 8 25
30 29 19 2
27 3 1 15
6 23 30 4
7 24 18 11
33 26 14 26
20 21 2 10
9 16 32 17
13 28 23 31

3 
21 28 26 6
2 17 11 1
17 10 15 4


*/