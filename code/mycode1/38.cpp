#include<bits/stdc++.h>
using namespace std;
const int N=1e6 + 7;
vector<int>g[N];
typedef long long ll;

ll w[N],id[N],va[N],cnt=1,n,mm,q;
ll tree[4*N],add[4*N];
int size[N];

void dfs(int u, int fa){
    va[cnt] = u;
    size[u] = 1;
    id[u] = cnt++;
    for(int j: g[u]){
        if(j == fa)continue;
        dfs(j, u);
        size[u] += size[j];
    }
}


#define m (l+r)/2
#define lson 2*node
#define rson 2*node+1

void build(int l,int r,int node){
    add[node]=0;
    if(l==r){
      //  cout <<"l = " <<l << " s =" << w[va[l]] << endl;
        tree[node]=w[va[l]];
        return;
    }
    build(l,m,lson);
    build(m+1,r,rson);
    tree[node] = tree[lson]+ tree[rson];
}



void update(int v, int pos,int l,int r,int node){
    if(l == r){
        tree[node]+=v;
        return;
    }
    if(pos<=m)update(v,pos,l,m,lson);
    else update(v,pos,m+1,r,rson);
    tree[node]= tree[lson] + tree[rson];
}




ll query(int ql, int qr,int l,int r,int node){
   // cout <<"l = " << ql << " r = " << qr << endl;
   if(ql <= l && qr >= r)return tree[node];
   ll ans = 0;
   if(ql <= m)ans += query(ql, qr, l, m, lson);
   if(qr > m)ans += query(ql, qr, m+ 1, r, rson);
   return ans;

}



int main(){
    int k;
    scanf("%lld%lld%d",&n,&q, &k);
    cnt=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    int u,v;
    for(int i=1;i< n;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(k,0);

    build(1,n,1);
    while(q--){
        int op;scanf("%d",&op);
        if(op==1){
            int a,b;
            scanf("%d%d",&a,&b);
            update(b,id[a], 1,n, 1);
        }else{
            int a;
            scanf("%d", &a);
            int l = id[a];
            int r = l + size[a] - 1;
           // cout << "l=  " << l << "r = " << r << endl;
            printf("%lld\n", query(l, r,1, n, 1));

        }
    }

    

}