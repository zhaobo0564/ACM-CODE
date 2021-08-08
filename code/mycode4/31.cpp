<span style="font-size:14px;">/* ***********************************************
Author        :angon
************************************************ */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
#define lld %I64d
#define REP(i,k,n) for(int i=k;i<n;i++)
#define REPP(i,k,n) for(int i=k;i<=n;i++)
#define scan(d) scanf("%d",&d)
#define scanl(d) scanf("%I64d",&d)
#define scann(n,m) scanf("%d%d",&n,&m)
#define scannl(n,m) scanf("%I64d%I64d",&n,&m)
#define mst(a,k)  memset(a,k,sizeof(a))
#define LL long long
#define N 100005
#define mod 1000000007
inline int read(){int s=0;char ch=getchar();for(; ch<'0'||ch>'9'; ch=getchar());for(; ch>='0'&&ch<='9'; ch=getchar())s=s*10+ch-'0';return s;}
 
int dp[N][3]; //0不回来最大，1不回来次大，2回来
int V[N];
int id[N];
int ans[N];
struct Edge
{
    int to,cost,next;
}edge[N*2];
int head[N],tot;
void addedge(int u,int v,int c)
{
    edge[tot] = (Edge){v,c,head[u]};
    head[u] = tot++;
}
 
void dfs1(int u,int fa)
{
  dp[u][2]=V[u];
  for(int i=head[u];~i;i=edge[i].next)
  {
    int v = edge[i].to;
    if(v==fa) continue;
    dfs(v,u);
    dp[u][2] += max(0 , dp[v][2] - 2*edge[i].cost);
  }
  id[u]=-1;
  dp[u][0]=dp[u][1]=V[u];
  for(int i=head[u];~i;i=edge[i].next)
  {
    int ad=edge[i].to;
    int wa=edge[i].cost;
    if(ad==fa) continue;
    int now = dp[u][2] - max(0 , dp[ad][2]-2*wa) + max(0 , dp[ad][0]-wa);
    if(now>=dp[u][0])
    {
      dp[u][1]=dp[u][0];
      dp[u][0]=now;
      id[u]=ad;
    }
    else if(now>dp[u][1]) dp[u][1]=now;
  }
  //printf("u = %d %d %d %d\n",u,dp[u][0],dp[u][1],dp[u][2]);
}
 
void dfs2(int u,int fa,int up1,int up2)
{
    ans[u] = max(dp[u][0] + up2 , dp[u][2] + up1);
    for(int i=head[u]; ~i;i=edge[i].next)
    {
        int v=edge[i].to; int cost = edge[i].cost;
        if(v==fa) continue;
        int d1,d2;
        if(v==id[u]) //从u的其余子树之一不回来
            d1 = max(0 , dp[u][1] - max(0,dp[v][2]-2*cost));
        else
            d1 = max(0 , dp[u][0] - max(0,dp[v][2]-2*cost));
        d2 = max(0, dp[u][2] - max(0, dp[v][2]-2*cost));  //从u的其余子树回来
 
        d1 = max(0 , max(up2+d1 , up1+d2) - cost );
        d2 = max(0 , d2+up2-2*cost);
        dfs2(v,u,d1,d2);
    }
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T; scan(T);
    int cas=1;
    while(T--)
    {
        int n;scan(n);
        REPP(i,1,n) scan(V[i]);
        mst(head,-1);tot=0;
        REP(i,1,n)
        {
            int u,v,c;
            scan(u);scann(v,c);
            addedge(u,v,c);
            addedge(v,u,c);
        }
        mst(dp,0);
        dfs1(1,-1);
        dfs2(1,-1,0,0);
        printf("Case #%d:\n",cas++);
        for(int i=1;i<=n;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
 
 
    return 0;
}</span>