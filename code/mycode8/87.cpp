#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=100000;
const int N=100;
const int M=10000;
int top;
int dist[N],pre[N];
bool vis[N];
int c[N];
int maxflow;
struct Vertex
{
	int first;
}V[N];
struct Edge
{
	int v,next;
	int cap,flow,cost;
}E[M];
void init()
{
	memset(V,-1,sizeof(V));
	top=0;
	maxflow=0;
}
void add_edge(int u,int v,int c,int cost)
{
	E[top].v=v;
	E[top].cap=c;
	E[top].flow=0;
	E[top].cost=cost;
	E[top].next=V[u].first;
	V[u].first=top++;
}
void add(int u,int v,int c,int cost)
{
	add_edge(u,v,c,cost);
	add_edge(v,u,0,-cost);
}
bool SPFA(int s,int t,int n)
{
	int i,u,v;
	queue<int>qu;
	memset(vis,false,sizeof(vis));
	memset(c,0,sizeof(c));
	memset(pre,-1,sizeof(pre));
	for(i=1;i<=n;i++)
		dist[i]=INF;
	vis[s]=true;
	c[s]++;
	dist[s]=0;
	qu.push(s);
	while(!qu.empty())
	{
		u=qu.front();
		qu.pop();
		vis[u]=false;
		for(i=V[u].first;i!=-1;i=E[i].next)
		{
			v=E[i].v;
			if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost)
			{
				dist[v]=dist[u]+E[i].cost;
				pre[v]=i;
				if(!vis[v])
				{
					c[v]++;
					qu.push(v);
					vis[v]=true;
					if(c[v]>n)
						return false;
				}
			}
		}
	}
	cout<<"最短路数组"<<endl;
	cout<<"dist[ ]=";
	for(int i=1;i<=n;i++)
		cout<<" "<<dist[i];
	cout<<endl;
	if(dist[t]==INF)
		return false;
	return true;
}
int MCMF(int s,int t,int n)
{
	int d;
	int i,mincost;
	mincost=0;
	while(SPFA(s,t,n))
	{
		d=INF;
		cout<<endl;
		//cout<<"增广路径："<<t;
		for(i=pre[t];i!=-1;i=pre[E[i^1].v])
		{
			d=min(d,E[i].cap-E[i].flow);
			cout<<"--"<<E[i^1].v;
		}
	//	cout<<"增流："<<d<<endl;
	//	cout<<endl;
		maxflow+=d;
		for(i=pre[t];i!=-1;i=pre[E[i^1].v])
		{
			E[i].flow+=d;
			E[i^1].flow-=d;
		}
		mincost+=dist[t];
	}
	return mincost;
}
void printg(int n)//输出网络邻接表
{
	cout<<"-----网络邻接表如下：-----"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"v"<<i<<" ["<<V[i].first;
		for(int j=V[i].first;~j;j=E[j].next)
			cout<<"]--["<<E[j].v<<" "<<E[j].cap<<" "<<E[j].flow<<" "<<E[j].cost<<" "<<E[j].next;
		cout<<"]"<<endl;
	}
	cout<<endl;
}
void printflow(int n)//输出实流边
{
	cout<<"-----实流边如下：-----"<<endl;
	for(int i=1;i<=n;i++)
		for(int j=V[i].first;~j;j=E[j].next)
			if(E[j].flow>0)
			{
				cout<<"v"<<i<<"--"<<"v"<<E[j].v<<" "<<E[j].flow<<" "<<E[j].cost;
				cout<<endl;
			}
}
int main() {
	int u,v,w,c;
	int n,m;
	cout<<"输入节点个数和边数："<<endl;
	cin>>n>>m;
	init();
	cout<<"输入两个节点u，v及边（u--v）的容量w,单位容量费用c："<<endl;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w>>c;
		add(u,v,w,c);
	}
	cout<<endl;
	printg(n);
	cout<<"网络的最小费用为："<<MCMF(1,n,n)<<endl;
	cout<<"网络的最大流值："<<maxflow<<endl;
	printg(n);
	printflow(n);
	return 0;
}
