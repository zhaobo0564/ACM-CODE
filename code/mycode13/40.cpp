/*
线段树分治
对于维护每一个操作出现的区间
并查集维护连通性，维护的时候记录度数，按秩合并
撤销的时候把度数小的撤销掉。    
*/
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 2 * 1e6 + 10;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, M;
int tim[5001][5001];//边(i, j)加入的时间
int fa[MAXN];
struct Node {
    int x, deg;
}S[MAXN];
struct Query {
    int opt, x, y;
}Q[MAXN]; 
#define ls k << 1
#define rs k << 1 | 1
struct SegTree {
    int l, r;
    vector<int> id; 
}T[MAXN];
void Build(int k, int ll, int rr) {
    T[k] = (SegTree) {ll, rr};
    if(ll == rr) return ;
    int mid = ll + rr >> 1;
    Build(ls, ll, mid); Build(rs, mid + 1, rr);
}
void IntervalAdd(int k, int ll, int rr, int val) {
    if(ll <= T[k].l && T[k].r <= rr) {T[k].id.push_back(val); return ;}
    int mid = T[k].l + T[k].r >> 1;
    if(ll <= mid)IntervalAdd(ls, ll, rr, val); 
    if(rr >  mid)IntervalAdd(rs, ll, rr, val);
}
int Top, inder[MAXN];
int find(int x) {
    if(fa[x] == x) return x;
    else return find(fa[x]);
}
void unionn(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    if(inder[x] < inder[y]) swap(x, y);
    fa[y] = x;
    S[++Top] = (Node) {y, inder[y]};
    if(inder[x] == inder[y]) S[++Top] = (Node) {x, inder[x] = inder[x] + inder[y]};//tag
}
void Delet(int cur) {
    while(Top > cur) {
        Node pre = S[Top--];
        fa[pre.x] = pre.x;
        inder[pre.x] = pre.deg;
    }
}
void dfs(int k) {
    int cur = Top;
    for(int i = 0; i < T[k].id.size(); i++) unionn(Q[T[k].id[i]].x, Q[T[k].id[i]].y);
    if(T[k].l == T[k].r) {
        if(Q[T[k].l].opt == 2)
            putchar(find(Q[T[k].l].x) == find(Q[T[k].l].y) ? 'Y' : 'N'), putchar('\n');
    } else dfs(ls), dfs(rs);
    
    Delet(cur);
}
int main() {
    N = read(); M = read();
    for(int i = 1; i <= N; i++) fa[i] = i, inder[i] = 1;
    Build(1, 1, M);//按时间为下标建线段树 
    for(int i = 1; i <= M; i++) {
        int opt = read(), x = read(), y = read();
        if(x > y) swap(x, y);
        if(opt == 0) tim[x][y] = i;
        if(opt == 1) IntervalAdd(1, tim[x][y], i, i), tim[x][y] = 0;
        Q[i] = (Query) {opt, x, y};
    }
    for(int i = 1; i <= N; i++)
        for(int j = i; j <= N; j++)
            if(tim[i][j])
                IntervalAdd(1, tim[i][j], M, tim[i][j]);
    dfs(1);
    return 0;
}