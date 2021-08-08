#include<bits/stdc++.h>
#define per(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int inf =0x3f3f3f3f;
const double eps=1e-8;
#define siz 100005
int n,head[siz],Enum=0,val[siz],ans[siz],dp[siz][2],G[siz][2];//0 is not back; 1 is back
//int no_back[siz];
struct Edge{int to,w,ne;}edge[siz*2];
bool vis[siz];
void add_edge(int a,int b,int c){
    edge[Enum].to=b;
    edge[Enum].w=c;
    edge[Enum].ne=head[a];
    head[a]=Enum++;
}
void init()
{
    memset(head,-1,sizeof(head));
    Enum=0;
    memset(ans,0,sizeof(ans));
}
void dfs(int u,int fa)
{
    dp[u][0]=dp[u][1]=val[u];
    for(int i=head[u];i!=-1;i=edge[i].ne){
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        dp[u][0]=max(dp[u][0],max(dp[u][0]+dp[v][1]-edge[i].w*2,dp[u][1]+dp[v][0]-edge[i].w));
        dp[u][1]=max(dp[u][1],dp[u][1]+dp[v][1]-edge[i].w*2);
    }
}
void dfs2(int u,int fa,int Cost,int fa_max_node,int fa_sec_node,int fa_sec_val)
{
    int mm=0,max_node=-1,sec_node=-1,max_val=0,sec_val=0,bk,nbk;//bk表示回，nbk表示不回 通过这两个相减来比较出最大边和次大边
    for(int i=head[u];i!=-1;i=edge[i].ne){
        int v=edge[i].to;
        //if(v==fa)continue; //不返回的也可能是父节点
        if(v==fa){
            int tmp0=dp[fa][0],tmp1=dp[fa][1];//然后减去本节点的影响
            if(u==fa_max_node){//这里tmp0不能用dp减，因为dp已经更新过了，算上父节点了
                tmp0-=(G[u][0]-Cost);
                if(fa_sec_node!=-1)tmp0+=fa_sec_val;
                if(G[u][1]-Cost*2 > 0)tmp1-=(G[u][1]-Cost*2);//理由同下
            }
            else if(u!=fa_max_node){
                if(G[u][1]-Cost*2 > 0){int ttt=G[u][1]-Cost*2;tmp0-=ttt;tmp1-=ttt;}
            }
            bk=tmp1-Cost*2;
            nbk=tmp0-Cost;
        }
        else if(v!=fa){
            bk=dp[v][1]-edge[i].w*2;
            nbk=dp[v][0]-edge[i].w;
        }
        if(nbk>0 && nbk-max(0,bk) > max_val){//注意这里要选用0和bk的最大值，因为nbk可能是负数，
            sec_node=max_node;  //然后考虑的是算上这个子树的nbk的贡献是否比其他子树的nbk-bk的大
            sec_val=max_val;    //大的话就要考虑加上这个nbk了
            max_node=v;
            max_val=nbk-max(0,bk);
        }
        else if(nbk>0 && nbk-max(0,bk) >sec_val){//成不了最大权路径就考虑次大权路径
            sec_node=v;
            sec_val=nbk-max(0,bk);
        }
    }
    for(int i=head[u];i!=-1;i=edge[i].ne){
        int v=edge[i].to;
        if(v==fa)continue;
        int tmp0=dp[u][0],tmp1=dp[u][1];//然后减去节点v的影响
        if(v==max_node){//v是max_node,则说明nbk是大于0的而不能说明back是大于零的，还需要判断一下
            tmp0-=(dp[v][0]-edge[i].w);
            if(sec_node!=-1)tmp0+=sec_val;
            if(dp[v][1]-edge[i].w*2 > 0)tmp1-=(dp[v][1]-edge[i].w*2);
//            dp[v][0]=max(dp[v][0],dp[v][1]+tmp0-edge[i].w);
//            dp[v][0]=max(dp[v][0],dp[v][0]+tmp1-edge[i].w*2);//！！！注意：这样写就加两遍啦！！！
            dp[v][0]=max(dp[v][0],max(dp[v][1]+tmp0-edge[i].w,dp[v][0]+tmp1-edge[i].w*2));
            dp[v][1]=max(dp[v][1],dp[v][1]+tmp1-edge[i].w*2);
        }
        else if(v!=max_node){
            if(dp[v][1]-edge[i].w*2 > 0){int ttt=dp[v][1]-edge[i].w*2;tmp0-=ttt;tmp1-=ttt;}
            dp[v][0]=max(dp[v][0],max(dp[v][0]+tmp1-edge[i].w*2,dp[v][1]+tmp0-edge[i].w));
            dp[v][1]=max(dp[v][1],dp[v][1]+tmp1-edge[i].w*2);
        }
        dfs2(v,u,edge[i].w,max_node,sec_node,sec_val);
    }
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        cas++;
        int a,b,c;
        scanf("%d",&n);
        init();
        per(i,1,n)scanf("%d",&val[i]);
        per(i,1,n-1){scanf("%d %d %d",&a,&b,&c);add_edge(a,b,c);add_edge(b,a,c);}
        dfs(1,-1);
        per(i,1,n){G[i][0]=dp[i][0];G[i][1]=dp[i][1];}
        dfs2(1,-1,0,0,0,0);
        printf("Case #%d:\n",cas);
        per(i,1,n)printf("%d\n",dp[i][0]);
    }

    return 0;
}

