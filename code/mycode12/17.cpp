#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;typedef long long ll;int n;int m;
struct per_linetree//��ϯ������ûɶ��˵�� 
{
	int s[2][22*N];ll val[22*N];int root[N];int cnt;
	int tim;per_linetree(){root[0]=++cnt;}
	inline void cson(int p1,int p2,int t){s[t][p2]=++cnt;s[t^1][p2]=s[t^1][p1];}
	inline void sadd(int p1,int p2,int l,int r,int pos,ll plus)
	{
		val[p2]=val[p1]+plus;if(r-l==1){return;}int mid=(l+r)/2;
		if(pos<=mid){cson(p1,p2,0);sadd(s[0][p1],cnt,l,mid,pos,plus);}
		else {cson(p1,p2,1);sadd(s[1][p1],cnt,mid,r,pos,plus);}
	}
	inline ll sum(int p,int l,int r,int dl,int dr)
	{
		if((dl==l&&dr==r)||p==0){return val[p];}int mid=(l+r)/2;ll ret=0;
		if(dl<mid){ret+=sum(s[0][p],l,mid,dl,min(dr,mid));}
		if(mid<dr){ret+=sum(s[1][p],mid,r,max(dl,mid),dr);}return ret;
	}
	inline int cadd(int pos,ll plus)//���ﷵ��һ���汾�� 
	{sadd(root[tim],root[tim+1]=++cnt,0,n,pos,plus);return ++tim;}
	inline ll csum(int t1,int t2,int l,int r)
	{return sum(root[t2],0,n,l,r)-sum(root[t1],0,n,l,r);}
}plt;
struct data
{
	ll v;int fr;int rk;//��ɢ���Ľṹ�� 
	friend bool operator <(data a,data b){return a.v<b.v;}
	friend bool operator ==(data a,data b){return a.v==b.v;}
}dx[N],dy[N];int y[N];ll add[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ll x;ll y;scanf("%lld%lld%lld",&x,&y,&add[i]);
		dx[i]=(data){x,i,0};dy[i]=(data){y,i,0};//���� 
	}sort(dx+1,dx+n+1);sort(dy+1,dy+n+1);dy[1].rk=1;//��ɢ��һ�� 
	for(int i=2;i<=n;i++){dy[i].rk=(dy[i]==dy[i-1])?dy[i-1].rk:i;}
	for(int i=1;i<=n;i++){y[dy[i].fr]=dy[i].rk;}//ӳ���ԭ����y 
	for(int i=1;i<=n;i++){int p=dx[i].fr;dx[i].rk=plt.cadd(y[p],add[p]);}//����x��˳��ӵ� 
	dx[n+1].v=0x7f7f7f7f;dy[n+1].v=0x7f7f7f7f;//�����ڱ���ֹupper_bound�Ҳ���ֵ 
	for(int i=1;i<=m;i++)
	{
		ll x1;ll x2;ll y1;ll y2; 
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		x1=(*lower_bound(dx+1,dx+n+2,(data){x1,0,0})).rk;//lower_bound��˵� 
		x2=(*(upper_bound(dx+1,dx+n+2,(data){x2,0,0})-1)).rk;//upper_bound�Ҷ˵� 
		y1=(*lower_bound(dy+1,dy+n+2,(data){y1,0,0})).rk;//lower_bound��˵� 
		y2=(*(upper_bound(dy+1,dy+n+2,(data){y2,0,0})-1)).rk;//upper_bound�Ҷ˵� 
		printf("%lld\n",plt.csum(x1-1,x2,y1-1,y2));//Ȼ���������ǰ׺�;ͺ���~ 
	}return 0;//�ݰݳ���~ 
}