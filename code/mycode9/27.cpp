#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
int dp[MAXN];
vector<int>hv[2];
vector<int> a[MAXN];
vector<ll> w[MAXN];
bool vis[MAXN];

int now;
void dfs(int x,int fa){
    dp[x]=1;
    for(int i=0;i<a[x].size();i++){
        int u=a[x][i];
        if(u==fa||vis[u])
            continue;
        dfs(u,x);
        dp[x]+=dp[u];
    }
}
int dfs1(int x,int fa,int siz){
    int minid=-1;
    dp[x]=siz-dp[x];
    for(int i=0;i<a[x].size();i++){
        int u=a[x][i];
        if(u==fa||vis[u])
            continue;
        dp[x]=max(dp[x],dp[u]);
        int v=dfs1(u,x,siz);
        if(minid==-1||dp[v]<dp[minid])
            minid=v;
    }
    if(minid==-1||dp[x]<dp[minid])
        minid=x;
    return minid;
}
int get_hv(int x){
    dfs(x,0);
    return dfs1(x,0,dp[x]);
}
int n;
ll ans,p;
map<ll,int> used;
ll fsp[MAXN],ifsp[MAXN];
void dfs2(int x,int fa,ll pre,int dep){
    ans+=used[(p-pre)*ifsp[dep]%p];
    for(int i=0;i<a[x].size();i++){
        int u=a[x][i];
        if(vis[u]==1||u==fa)
            continue;
        dfs2(u,x,(pre*10ll+w[x][i])%p,dep+1);
    }
}
void dfs3(int x,int fa,ll pre,int dep,int val){
    used[pre]+=val;
    for(int i=0;i<a[x].size();i++){
        int u=a[x][i];
        if(vis[u]==1||u==fa)
            continue;
        dfs3(u,x,(pre+fsp[dep]*w[x][i])%p,dep+1,val);   
    }
}
void solve(int x){
    used.clear();
    used[0]++;
    for(int i=0;i<a[x].size();i++){
        if(vis[a[x][i]])
            continue;
        dfs3(a[x][i],x,w[x][i],1,1);
    }
    for(int i=0;i<a[x].size();i++){
        if(vis[a[x][i]])
            continue;
        dfs3(a[x][i],x,w[x][i],1,-1);
        dfs2(a[x][i],x,w[x][i],1);
        dfs3(a[x][i],x,w[x][i],1,1);    
    }
    ans+=(used[0]-1);
}
void work(){
    while(hv[now].size()){
        for(int i=0;i<hv[now].size();i++){
            int x=hv[now][i];
            solve(x);
            vis[x]=1;
            for(int i=0;i<a[x].size();i++)
                if(vis[a[x][i]]==0)
                    hv[now^1].push_back(get_hv(a[x][i]));
        }
        hv[now].clear();
        now^=1;
    }
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll xx=y;
    ll yy=x-a/b*y;
    x=xx;
    y=yy;
}
ll get_inv(ll x,ll y){
    ll xx,yy;
    exgcd(x,y,xx,yy);
    return (xx%y+y)%y;
} 
int main(){
    SF("%d%d",&n,&p);
    fsp[0]=1;
    for(int i=1;i<=n;i++)
        fsp[i]=fsp[i-1]*10ll%p;
    ifsp[n]=get_inv(fsp[n],p);
    for(int i=n;i>=1;i--)
        ifsp[i-1]=ifsp[i]*10ll%p;
    int u,v,val;
    for(int i=1;i<n;i++){
        //SF("%d%d%d",&u,&v,&val);
        u = i, v = i + 1, val = 8;
        val%=p;
        a[u].push_back(v);
        a[v].push_back(u);
        w[u].push_back(val);
        w[v].push_back(val);    
    }
    hv[0].push_back(get_hv(0));
   // work();
   dfs(1, 0);
    puts("AA\n");
    PF("%I64d\n",ans);
}