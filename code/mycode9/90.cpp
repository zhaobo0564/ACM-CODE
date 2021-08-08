// dijkstra最短路径
// 核心思路 在所有路线的权值中找一个最短的路线 然后沿着这条路找次短的以此类推
// 用队列寻找最短路线的全值为降低空间复杂度
// 用栈可以快速求出路劲 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int N=10007;
const int Max=1e9;
int map[N][N];
int dist[N];  	// 记录从源点到该点的权值
int p[N];       // 记录经过的路径
int flag[N];    // 将已经找到最短路径的点加入可集合
int n,m;		// n是城市个数m是城市之间的路径个数

void shortpath(int u);
void showpath(int u);

struct node		// 优先队列的结构体 
{
	int i;
	int w;	
	node(int i=0,int w=0)
	{
		this->i=i;
		this->w=w;
	}
	bool operator<(const node n)const // 以最小值优先 
	{
		return w>n.w;
	}
};

int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			map[i][j]=Max; 	// 给所以路程赋最大值这样没通路就是无穷大 
		dist[i]=Max;		// 同理 
	}
	int a,b,w;				// a->b城市的权值w
	while(m--)
	{
		cin>>a>>b>>w; 
		if(map[a][b]==Max)map[a][b]=w;
		else if(map[a][b]<w) map[a][b]=w;
	} 
	//cin>>a;					// 输入源点的位置 	
//	shortpath(a);
	shortpath(7);
	//cout<<dist[]<<endl; 
 } 
 
void shortpath(int u)
{
	node cd;
	int t;
	priority_queue<node>q;
	dist[u]=0;
	p[u]=-1;
	q.push(node(u,0));
	while(!q.empty())
	{
		cd=q.top();
		q.pop();
		t=cd.i;
		if(flag[t]) continue;
		flag[t]=1;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i]&&map[t][i]<Max)
				if(dist[i]>dist[t]+map[t][i])
				{
					dist[i]=dist[t]+map[t][i];
					p[i]=t;
					q.push(node(i,dist[i]));
				}
		}
        cout << "AAA\n ";
        for (int i = 1; i <= n; i++) {
            cout << dist[i] << " " << p[i] << endl;
        }
	}
	
}
 
void showpath(int u)
{
	int x;
	stack<int>q;
	cout<<"源点为"<<u<<endl;
	for(int i=1;i<=n;i++)
	{
		x=p[i];
		while(x!=-1)
		{
			q.push(x);
			x=p[x];
		}
		while(!q.empty())
		{
			cout<<q.top()<<"--";
			q.pop();
		}
		cout<<i<<"最短距离为："<<dist[i]<<endl;	
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
