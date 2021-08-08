/*lca + dp */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<ll>G[N];
int n;
ll dep[N],fa[N][32];
ll ff[30];
struct node
{
    ll x,y;
    ll mx;
}a[N];
 
void dfs(ll u,ll f,ll d)
{
    fa[u][0]=f;
    dep[u]=d;
    for(ll v:G[u]){
        if(v==f) continue;
        dfs(v,u,d+1);
    }
}
void init()
{
    for(int k=1;k<=21;++k){
        for(int i=1;i<=n;++i){
            fa[i][k]=fa[fa[i][k-1]][k-1];
        }
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=21;k>=0;--k)
        if(dep[fa[u][k]]>=dep[v])
             u=fa[u][k];
    if(u==v) return v;
 
    for(int k=21;k>=0;--k){
        if(fa[v][k]!=fa[u][k]) v=fa[v][k],u=fa[u][k];
    }
    return fa[v][0];
}
ll qulen(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)]+1;
}
void dfs1(int u,int fa)
{
    for(int v:G[u]){
        if(v==fa) continue;
        dfs1(v,u);
        int x=a[u].x,y=a[u].y;
        int x1=a[v].x,y1=a[v].y;
 
 
        ll l1=qulen(x,x1);
        ll l2=qulen(x,y1);
        ll l3=qulen(x1,y);
        ll l4=qulen(y1,y);
 
        if(a[v].mx>a[u].mx){
            a[u].mx=a[v].mx;
            a[u].x=a[v].x;
            a[u].y=a[v].y;
        }
        if(l1>a[u].mx){
            a[u].mx=l1;
            a[u].x=x;
            a[u].y=x1;
        }
 
        if(l2>a[u].mx){
            a[u].mx=l2;
            a[u].x=x;
            a[u].y=y1;
        }
        if(l3>a[u].mx){
            a[u].mx=l3;
            a[u].x=x1;
            a[u].y=y;
        }
        if(l4>a[u].mx){
            a[u].mx=l4;
            a[u].x=y1;
            a[u].y=y;
        }
    }
}
ll quans(ll u,ll d)
{
    if(d<0) return u;
    for(int k=21;k>=0&&d;--k){
        if(ff[k]<=d){
            d-=ff[k];
            u=fa[u][k];
        }
    }
    return u;
}
int main()
{
    ff[0]=1ll;
    for(int i=1;i<=21;++i) ff[i]=2ll*ff[i-1];
 
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0,1);
    init();
 
    for(int i=1;i<=n;++i)
    {
        a[i].x=a[i].y=i;
        a[i].mx=1;
    }
    dfs1(1,0);
    ll ans=0;
 
    for(int i=1;i<=n;++i){
        if(a[i].mx%2==1){
            ll d=a[i].mx/2+1;
            int dian=dep[a[i].x]>dep[a[i].y]?a[i].x:a[i].y;
            int t=quans(dian,d-1);
 
            ans+=t;
        }
        else{
            ll d=a[i].mx/2;
            ll dian=dep[a[i].x]> dep[a[i].y] ? a[i].x : a[i].y;
            ll t=quans(dian,d-1);
            ans+=t;
            t=quans(dian,d);
            ans+=t;
        }
    }
    printf("%lld\n",ans);
}