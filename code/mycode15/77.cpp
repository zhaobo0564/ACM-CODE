#include<bits/stdc++.h>
using namespace std;
const int N=100001;
struct node
{
	int l,r;
	int len;
	char ch;
}t[40*N];
int tot=0,cnt=0,tmp;
int root[N];
#define mid (l+r>>1)
void updata(int prew,int &now,int l,int r,char ch)										                        //修改
{
	now=++tot;																	//开点
	t[now]=t[prew];																	//让当前节点等于前个版本的点
	if(l==r)
	{
		t[now].len=1;
		t[now].ch=ch;
		return ;
	}
	if(t[t[l].l].len==mid-l+1)updata(t[prew].r,t[now].r,mid+1,r,ch);					                                       //如果右孩子放满了，就放到左孩子中
	else updata(t[prew].l,t[now].l,l,mid,ch);											
	t[now].len=t[t[now].l].len+t[t[now].r].len;
}
char query(int root,int l,int r,int p)
{
	if(l==r)return t[root].ch;
	if(t[t[root].l].len>=p)return query(t[root].l,l,mid,p);								//查找第p小
	else return query(t[root].r,mid+1,r,p-t[t[root].l].len);
}
int main()
{
	int n;
	cin>>n;
	char op,ch;
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>op;
		if(op=='T')
		{
			cin>>ch;
			cnt++;
			updata(root[cnt-1],root[cnt],1,n,ch);
		}
		if(op=='U')
		{
			cin>>k;
			cnt++;
			root[cnt]=root[cnt-1-k];										//让这个根等于k给版本之前的根
		}
		if(op=='Q')
		{
			cin>>k;
			printf("%c\n",query(root[cnt],1,n,k));
		}
	}
}