#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,m,root,cur;
ll a,b,c;
struct P
{
	int d[2],mx[2],mn[2],ls,rs,v;
	ll sum;
	int& operator[](int x){return d[x];}
	friend bool operator<(P a,P b){return a[cur]<b[cur];}
}p[maxn];
struct kdtree
{
	P t[maxn];
	void up(int k)
	{
		int ls=t[k].ls,rs=t[k].rs;
		for(int i=0;i<2;i++)
		{
			t[k].mn[i]=t[k].mx[i]=t[k][i];
			if(ls)t[k].mn[i]=min(t[k].mn[i],t[ls].mn[i]);
			if(rs)t[k].mn[i]=min(t[k].mn[i],t[rs].mn[i]);
			if(ls)t[k].mx[i]=max(t[k].mx[i],t[ls].mx[i]);
			if(rs)t[k].mx[i]=max(t[k].mx[i],t[rs].mx[i]);
		}
		t[k].sum=t[ls].sum+t[rs].sum+t[k].v;
	}
	int build(int l,int r,int now)
	{
		cur=now;
		int mid=(l+r)/2;
		nth_element(p+l,p+mid,p+r+1);
		t[mid]=p[mid];
		if(l<mid)t[mid].ls=build(l,mid-1,!now);
		if(r>mid)t[mid].rs=build(mid+1,r,!now);
		up(mid);
		return mid;
	}
	int check(ll x,ll y)
	{
		return a*x+b*y<c;
	}
	int cal(P a) 
	{ 
	    int tmp=0; 
	    tmp+=check(a.mx[0],a.mx[1]); 
	    tmp+=check(a.mx[0],a.mn[1]); 
	    tmp+=check(a.mn[0],a.mx[1]);
	    tmp+=check(a.mn[0],a.mn[1]);
	    return tmp;
	}
	ll qu(int o)
	{
		int tmp=cal(t[o]);
		if(tmp==4)
		return t[o].sum;
		if(!tmp)return 0;
		ll res=0;
		if(check(t[o][0],t[o][1]))
		res+=t[o].v;
		if(t[o].ls)res+=qu(t[o].ls);
		if(t[o].rs)res+=qu(t[o].rs);
		return res;
	}
}kd;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d",&p[i][0],&p[i][1],&p[i].v);
	root=kd.build(1,n,0);
	while(m--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",kd.qu(root));
	}
}