#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
 
int n,q;
int a[MAXN],a1[MAXN*2],top;
int tr1[MAXN],tr2[MAXN],lenx,leny;
int rt[MAXN*350],tot;
struct Tree{
	int l,r;
	int siz;
}tr[MAXN*350];
struct Query{
	int l,r,k;
}que[MAXN];
 
int Read(){
	int i=0,f=1;
	char c;
	for(c=getchar();(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')
	  f=-1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())
	  i=(i<<3)+(i<<1)+c-'0';
	return i*f; 
}
 
void update(int &root,int las,int l,int r,int x,int key){
	root=++tot;
	tr[root]=tr[las];
	tr[root].siz+=key;
	if(l==r)
	  return ;
	int mid=l+r>>1;
	if(x<=mid)
	  update(tr[root].l,tr[las].l,l,mid,x,key);
	else
	  update(tr[root].r,tr[las].r,mid+1,r,x,key);
}
 
int query(int l,int r,int k){
	if(l==r)
	  return l;
	int s=0;
	for(int i=1;i<=lenx;++i)
	  s-=tr[tr[tr1[i]].l].siz;
	for(int i=1;i<=leny;++i)
	  s+=tr[tr[tr2[i]].l].siz;
	int mid=l+r>>1; 
	if(k<=s){
		for(int i=1;i<=lenx;++i)
		  tr1[i]=tr[tr1[i]].l;
		for(int i=1;i<=leny;++i)
		  tr2[i]=tr[tr2[i]].l;
		return query(l,mid,k);
	}
	else{
		for(int i=1;i<=lenx;++i)
		  tr1[i]=tr[tr1[i]].r;
		for(int i=1;i<=leny;++i)
		  tr2[i]=tr[tr2[i]].r;
		return query(mid+1,r,k-s);
	}
}
 
int lowbit(int x){
	return x&(-x);
}
 
void add(int x,int val){
	int pos=lower_bound(a1+1,a1+top+1,a[x])-a1;
	for(int i=x;i<=n;i+=lowbit(i)){
		update(rt[i],rt[i],1,top,pos,val);
	}
}
 
int main(){
	n=Read(),q=Read();
	for(int i=1;i<=n;++i)
	  a[i]=a1[++top]=Read();
	for(int i=1;i<=q;++i){
		char cz[3];
		scanf("%s",cz);
		if(cz[0]=='C'){
			que[i].l=Read();
			que[i].r=Read();
			que[i].k=0,a1[++top]=que[i].r;	
		}
		else{
			que[i].l=Read();
			que[i].r=Read();
			que[i].k=Read();
		}
	}
	sort(a1+1,a1+top+1);
	top=unique(a1+1,a1+top+1)-a1-1;
	for(int i=1;i<=n;++i){
		add(i,1);
	}
	for(int i=1;i<=q;++i){
		if(que[i].k){
			lenx=0,leny=0;
			for(int j=que[i].r;j;j-=lowbit(j))
			  tr2[++leny]=rt[j];
			for(int j=que[i].l-1;j;j-=lowbit(j))
			  tr1[++lenx]=rt[j];
			cout<<a1[query(1,top,que[i].k)]<<'\n';
		}
		else{
			add(que[i].l,-1);
			a[que[i].l]=que[i].r;
			add(que[i].l,1);
		}
	}
	return 0;
}