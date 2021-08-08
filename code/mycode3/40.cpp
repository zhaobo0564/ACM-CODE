/* ***********************************************
Author        :angon
2016年8月15日 23:52:07
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
#define N 6005
#define mod 1000000007
inline int read(){int s=0;char ch=getchar();for(; ch<'0'||ch>'9'; ch=getchar());for(; ch>='0'&&ch<='9'; ch=getchar())s=s*10+ch-'0';return s;}
 
int n,dp[N][2],father[N];
vector<int>G[N];
void dfs(int root)
{
    for(int i=0;i<G[root].size();i++)
    {
        dfs(G[root][i]);  //递归root的每个孩子
    }
    for(int i=0;i<G[root].size();i++) //回溯时计算
    {
        dp[root][0] += max(dp[G[root][i]][0],dp[G[root][i]][1]);
        dp[root][1] += dp[G[root][i]][0];
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int u,v;
    while(~scan(n))
    {
        mst(father,-1); mst(dp,0);
        REPP(i,1,n) { scan(dp[i][1]); G[i].clear();}
        while(scann(u,v)&&u&&v)
        {
            father[u]=v;
            G[v].push_back(u);
        }
        int root=1;
        while(father[root]!=-1) root=father[root];
        dfs(root);
        printf("%d\n",max(dp[root][1],dp[root][0]));
    }
 
    return 0;
}

