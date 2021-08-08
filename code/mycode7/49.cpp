#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
typedef long long LL;
const int N=100005;
 
struct OP
{
	int st,ed,id;
	OP(){}
	OP(int a,int b,int c){st=a;ed=b;id=c;}
	bool operator<(const OP &b)const
	{ return ed<b.ed; }
}op[N];
struct node
{
	int lft,rht;
	LL mx,sum;
	LL flag_mx,flag_sum;
	int mid(){return MID(lft,rht);}
	void init() { mx=sum=flag_mx=flag_sum=0; }
	void fun(LL a,LL b)
	{
		flag_mx=max(flag_mx,flag_sum+b);
		flag_sum+=a;
	}
};
 
int n,m,pos[N*2],a[N];
LL res[N];
 
struct Segtree
{
	node tree[N*4];
	void PushUp(int ind)
	{
		if(tree[ind].lft!=tree[ind].rht)
		{
			tree[ind].sum=max(tree[LL(ind)].sum,tree[RR(ind)].sum)+tree[ind].flag_sum;
			tree[ind].mx=max(tree[LL(ind)].mx,tree[RR(ind)].mx);
			tree[ind].mx=max(tree[ind].mx,
					max(tree[LL(ind)].sum,tree[RR(ind)].sum)+tree[ind].flag_mx);
		}
		else
		{
			tree[ind].sum=tree[ind].flag_sum;
			tree[ind].mx=tree[ind].flag_mx;
		}
	}
	void PushDown(int ind)
	{
		LL &tmp1=tree[ind].flag_sum,&tmp2=tree[ind].flag_mx;
		tree[LL(ind)].fun(tmp1,tmp2); PushUp(LL(ind));
		tree[RR(ind)].fun(tmp1,tmp2); PushUp(RR(ind));
		tmp1=tmp2=0;
	}
	void build(int lft,int rht,int ind)
	{
		tree[ind].lft=lft;	tree[ind].rht=rht;
		tree[ind].init();
		if(lft!=rht)
		{
			int mid=tree[ind].mid();
			build(lft,mid,LL(ind));
			build(mid+1,rht,RR(ind));
		}
	}
	void updata(int st,int ed,int ind,int valu)
	{
		int lft=tree[ind].lft,rht=tree[ind].rht;
		if(st<=lft&&rht<=ed)
		{
			tree[ind].fun(valu,valu);
			PushUp(ind);
		}
		else 
		{
			PushDown(ind);
			int mid=tree[ind].mid();
			if(st<=mid) updata(st,ed,LL(ind),valu);
			if(ed >mid) updata(st,ed,RR(ind),valu);
			PushUp(ind);
		}
	}
	LL query(int st,int ed,int ind)
	{
		int lft=tree[ind].lft,rht=tree[ind].rht;
		if(st<=lft&&rht<=ed) return tree[ind].mx;
		else 
		{
			PushDown(ind);
			int mid=tree[ind].mid();
			LL mx1=0,mx2=0;
			if(st<=mid) mx1=query(st,ed,LL(ind));
			if(ed> mid) mx2=query(st,ed,RR(ind));
			//PushUp(ind);		//查询未更新值，这里可以不用向上传递
			return max(mx1,mx2);
		}
	}
}seg;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(pos,0,sizeof(pos));
		for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int st,ed;
			scanf("%d%d",&st,&ed);
			op[i]=OP(st,ed,i);
		}
		sort(op,op+m);
 
		int ind=0;
		seg.build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			int &tmp=pos[a[i]+N];
			seg.updata(tmp+1,i,1,a[i]);
			tmp=i;
			while(ind<m&&op[ind].ed==i)
			{
				res[op[ind].id]=seg.query(op[ind].st,op[ind].ed,1);
				ind++;
			}
		}
		for(int i=0;i<m;i++) printf("%lld\n",res[i]);
	}
	return 0;
}