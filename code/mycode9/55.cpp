#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=5e5+7;

ll siz[N],val[N];
ll a[N],d[N],tot=0;
ll tag[N],f[N];

vector<ll> G[N];

void dfs(int u,int fa){
	siz[u]=1;
	d[u]=++tot,a[tot]=val[u];
	f[u]=fa;

	for(auto v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}

ll t[N<<2],lazy[N<<2];

void pushdown(int rt,ll l,ll r){
	if(lazy[rt]){
		ll mid=(l+r)>>1;
		t[rt<<1]+=lazy[rt]*(mid-l+1);
		t[rt<<1|1]+=lazy[rt]*(r-mid);
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
}

void build(int rt,int l,int r){
	if(l==r){
		t[rt]=a[l];
		return;
	}

	int mid=(l+r)>>1;
	build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
	t[rt]=t[rt<<1]+t[rt<<1|1];
}

void update(int rt,int l,int r,int ul,int ur,ll x){
	if(ul<=l&&r<=ur){
		t[rt]+=1ll*(r-l+1)*x;
		lazy[rt]+=x;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);

	if(ul<=mid) update(rt<<1,l,mid,ul,ur,x);
	if(mid<ur) update(rt<<1|1,mid+1,r,ul,ur,x);

	t[rt]=t[rt<<1]+t[rt<<1|1];
}

ll query(int rt,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return t[rt];
	pushdown(rt,l,r);
	int mid=(l+r)>>1;ll res=0;
	if(ql<=mid) res+=query(rt<<1,l,mid,ql,qr);
	if(mid<qr) res+=query(rt<<1|1,mid+1,r,ql,qr);
	return res;
}

int main(){
	 //freopen("in.in", "r", stdin);   //只改变输入流的文件指针，读入这个文件的内容（必须要有input这个文件）stdin是标准输入流的文件指针
	//freopen("output.txt", "w", stdout);
	int n=input(),m=input();
	for(int i=1;i<=n;i++) val[i]=input();

	for(int i=1;i<n;i++){
		int u=input(),v=input();
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1,0);
	build(1,1,n);

	while(m--){
		int opr=input();
		if(opr==1){
			ll u=input();
			printf("%lld\n",query(1,1,n,d[u],d[u]+siz[u]-1)+tag[f[u]]);
		}
		if(opr==2){
			ll u=input(),x=input();
			update(1,1,n,d[u],d[u]+siz[u]-1,x);
		}
		if(opr==3){
			ll u=input(),x=input();
			tag[u]+=x;
			if (f[u] == 0)
				update(1,1,n,d[u],d[u],x*1ll*G[u].size() + x);
			else update(1,1,n,d[u],d[u],x*1ll*G[u].size());
		}
	}
}

/*
7 3
1 1 1 1 1 1 1
1 2
1 3
2 4
2 5
3 6
3 7

2 3 1
3 1 1
1 3
*/