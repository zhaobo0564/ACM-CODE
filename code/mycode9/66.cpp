#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(int x){
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
const int N=100005;
char s[N];
int x[N],y[N],SA[N],rk[N],n,Q;
int lg[N],cnt[N],hei[N][20];

int cmp(int i,int j,int k){
	return y[i]!=y[j]||((i+k>n)?-1:y[i+k])!=(j+k>n?-1:y[j+k]);
}
void build_SA(){
	int m=26;
	For(i,0,m) cnt[i]=0;
	For(i,1,n) cnt[x[i]=s[i]-'a'+1]++;
	For(i,1,m) cnt[i]+=cnt[i-1];
	Rep(i,n,1) SA[cnt[x[i]]--]=i;
	for (int k=1;k<n;k<<=1){
		int p=0;
		For(i,n-k+1,n) y[++p]=i;
		For(i,1,n) if (SA[i]>k) y[++p]=SA[i]-k;
		For(i,0,m) cnt[i]=0;
		For(i,1,n) cnt[x[y[i]]]++;
		For(i,1,m) cnt[i]+=cnt[i-1];
		Rep(i,n,1) SA[cnt[x[y[i]]]--]=y[i];
		
		For(i,0,n+2) swap(x[i],y[i]);
		m=x[SA[1]]=1;
		For(i,2,n) x[SA[i]]=(m+=cmp(SA[i-1],SA[i],k));
	}
	For(i,1,n) rk[SA[i]]=i;
	For(i,2,n) lg[i]=lg[i/2]+1;
	int p=0;
	For(i,1,n) if (rk[i]!=1){
		p-=(p!=0);
		for (;s[i+p]==s[SA[rk[i]-1]+p];++p);
		hei[rk[i]][0]=p;
	}
	For(i,1,16) For(j,1,n-(1<<i)+1)
		hei[j][i]=min(hei[j][i-1],hei[j+(1<<(i-1))][i-1]);
}

const int M=5000005;

int ls[M],rs[M],S[M];
int rt[N],nd;

void insert(int &nk,int k,int l,int r,int p){
	nk=++nd; S[nk]=S[k]+1;
	ls[nk]=ls[k]; rs[nk]=rs[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[nk],ls[k],l,mid,p);
	else insert(rs[nk],rs[k],mid+1,r,p);
}
int ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return S[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,y)+ask(rs[k],mid+1,r,x,y);
}
int query_1(int p,int l,int r){
	return l<=r?ask(rt[p],1,n,l,r):0;
}
int rmq(int x,int y){
	int k=lg[y-x+1];
	return min(hei[x][k],hei[y-(1<<k)+1][k]);
}
int find_l(int x,int len){
	x=rk[x];
	int l=1,r=x-1,p=x;
	while (l<=r){
		int mid=(l+r)/2;
		if (rmq(mid+1,x)>=len)
			p=mid,r=mid-1;
		else l=mid+1;
	}
	return p;
}
int find_r(int x,int len){
	x=rk[x];
	int l=x+1,r=n,p=x;
	while (l<=r){
		int mid=(l+r)/2;
		if (rmq(x+1,mid)>=len)
			p=mid,l=mid+1;
		else r=mid-1;
	}
	return p;
}
int /*d[50005],*/f[50005],res[N];
vector<pii> op[N];
void solve(){
	//scanf("%d%d",&n,&Q);
	n = read(), Q = read();
	scanf("%s",s+1);
	build_SA();
	nd=0;
	For(i,1,n)
		insert(rt[i],rt[i-1],1,n,SA[i]);
	For(i,1,n) op[i].resize(0);
	For(i,1,Q){
		int l,r,x;
		//scanf("%d%d%d",&l,&r,&x);
		l = read(), r = read(), x = read();
		int pl=find_l(x,r-x+1);
		res[i]=query_1(pl-1,l,x-1)+1;
		res[i]+=query_1(rk[x],x+1,r);
		op[x].push_back(pii(r,i));
	}
	For(i,1,n){
		if (!op[i].size()) continue;
		/*d[i-1]=*/f[i-1]=0;
		//d[i]=0; 
		f[i]=i-1;
		For(j,i+1,n){
			int p=f[j-1];
			for (;p!=i-1&&s[p+1]!=s[j];p=f[p]);
			f[j]=p+(s[p+1]==s[j]);// d[j]=d[f[j]]+(f[j]!=i-1&&rk[i+(j-f[j])]>rk[i]);
			//cout<<j<<' '<<f[j]<<' '<<d[j]<<endl;
		}
		for (auto p:op[i])
		{
			int sum=0;
			for(int j=p.fi;f[j]!=i-1;j=f[j])sum+=rk[i+p.fi-f[j]]>rk[i];
			res[p.se]+=sum;
		}
	}
	For(i,1,Q) {
		write(res[i]);
		puts("");
	}
		//cout<<res[i]<<endl;
}

int main(){
	//freopen("1.in","r",stdin);
	int T;
	T = read();	while (T--) solve();
}