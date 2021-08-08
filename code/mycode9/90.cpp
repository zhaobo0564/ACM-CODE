// dijkstra���·��
// ����˼· ������·�ߵ�Ȩֵ����һ����̵�·�� Ȼ����������·�Ҵζ̵��Դ�����
// �ö���Ѱ�����·�ߵ�ȫֵΪ���Ϳռ临�Ӷ�
// ��ջ���Կ������·�� 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int N=10007;
const int Max=1e9;
int map[N][N];
int dist[N];  	// ��¼��Դ�㵽�õ��Ȩֵ
int p[N];       // ��¼������·��
int flag[N];    // ���Ѿ��ҵ����·���ĵ����ɼ���
int n,m;		// n�ǳ��и���m�ǳ���֮���·������

void shortpath(int u);
void showpath(int u);

struct node		// ���ȶ��еĽṹ�� 
{
	int i;
	int w;	
	node(int i=0,int w=0)
	{
		this->i=i;
		this->w=w;
	}
	bool operator<(const node n)const // ����Сֵ���� 
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
			map[i][j]=Max; 	// ������·�̸����ֵ����ûͨ·��������� 
		dist[i]=Max;		// ͬ�� 
	}
	int a,b,w;				// a->b���е�Ȩֵw
	while(m--)
	{
		cin>>a>>b>>w; 
		if(map[a][b]==Max)map[a][b]=w;
		else if(map[a][b]<w) map[a][b]=w;
	} 
	//cin>>a;					// ����Դ���λ�� 	
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
	cout<<"Դ��Ϊ"<<u<<endl;
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
		cout<<i<<"��̾���Ϊ��"<<dist[i]<<endl;	
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
