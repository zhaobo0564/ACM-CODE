#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

const int N=300010;

struct node{
	int x,y;ll w;
}tree[N<<2];
int to[N<<1],nxt[N<<1],head[N],cnt;
int fa[N],size[N],dep[N],son[N],top[N];
ll dis[N],val[N<<1],n,m;

inline void insert(int x,int y,ll z){
	to[++cnt]=y,nxt[cnt]=head[x],head[x]=cnt,val[cnt]=z;	
}

inline void dfs1(int u,int f){
	fa[u]=f,size[u]=1,dep[u]=dep[f]+1;
	int maxson=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];if(v==fa[u])continue;
		dis[v]=dis[u]+val[i];
		dfs1(v,u);size[u]+=size[v];
		if(size[v]>size[maxson])maxson=v;
	}son[u]=maxson;
}

inline void dfs2(int u,int topf){
	top[u]=topf;if(!son[u]) return;
	dfs2(son[u],topf);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];if(v==fa[u]||v==son[u])continue;dfs2(v,v);
	}
}

inline int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}return dep[x]<dep[y]?x:y;
}

inline ll dist(int x,int y){return dis[x]+dis[y]-2*dis[LCA(x,y)];}

inline node MAX(node a,node b){return dist(a.x,a.y)>dist(b.x,b.y)?a:b;}

inline node push_up(node a,node b){
	node res=MAX(MAX((node){a.x,b.x,0},(node){a.x,b.y,0}),MAX((node){a.y,b.x,0},(node){a.y,b.y,0}));
	
    res.w=dist(a.x,b.y) + dist(a.x, b.y) + dist(a.y, b.x) + dist(a.y, b.y);
	//if(a.w>res.w)res=a;if(b.w>res.w)res=b;
	return res;
}

inline void build(int l,int r,int x){
	if(l==r){tree[x].x=tree[x].y=l,tree[x].w=0;return;}
	int mid=l+r>>1;build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	tree[x]=push_up(tree[x<<1],tree[x<<1|1]);return;
}

inline node query(int ql,int qr,int l,int r,int x){
	if(ql<=l&&qr>=r) return tree[x];
	int mid=l+r>>1,ls=0,rs=0;
	node res1,res2;
	if(ql<=mid) ls=1,res1=query(ql,qr,l,mid,x<<1);
	if(qr>mid) rs=1,res2=query(ql,qr,mid+1,r,x<<1|1);
	return (ls&rs)?push_up(res1,res2):(ls?res1:res2);
}

int main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	n=read(),m=read();ll x,y,z;
	for(int i=1;i<n;i++){
		x=read(),y=read(),z=read();
		insert(x,y,z),insert(y,x,z);
	}
	dfs1(1,1),dfs2(1,1);build(1,n,1);
	while(m--){
		x=read(),y=read();
		printf("%lld\n",query(x,y,1,n,1).w);
	}return 0;
}
