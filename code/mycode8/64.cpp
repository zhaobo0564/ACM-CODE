#include<bits/stdc++.h>
#define fgx cerr<<"-----------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
using namespace std;
inline int read(){
	int nm=0,fh=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fh=-1;
	for(;isdigit(c);c=getchar()) nm=nm*10+c-'0';
	return nm*fh;
}
#define M 200020
int n,q,nxt[M],pre[M],sta[M]; bool flg;
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		if(i<n) nxt[i]=i+1;
		if(i>1) pre[i]=i-1;
	}
	nxt[n]=1,pre[1]=n;
	while(q--){
		int opt=read();
		if(flg){if(opt==1) opt=2; else if(opt==2) opt=1;}
		if(opt==1){
			int x=read(),y=read();
			if(nxt[y]==x)continue;
			int nx=nxt[x],px=pre[x],ny=nxt[y];
			pre[nx]=px,nxt[px]=nx;
			nxt[y]=x,pre[x]=y,nxt[x]=ny,pre[ny]=x;
		}else if(opt==2){
			int x=read(),y=read();
			if(nxt[x]==y)continue;
			int nx=nxt[x],px=pre[x],py=pre[y];
			pre[nx]=px,nxt[px]=nx;
			nxt[py]=x,pre[x]=py,nxt[x]=y,pre[y]=x;
		}else if(opt==3)flg^=1;
		else if(opt==4){
			if(flg){flg=false; for(int i=1;i<=n;i++) swap(nxt[i],pre[i]);}
			int top=0,pos,fs=1; sta[++top]=fs,fs=nxt[fs];
			while(fs^1) sta[++top]=fs,fs=nxt[fs];
			for(int i=1;i<=n;i++) if(sta[i]==1){pos=i; break;}
			for(int i=pos;i<=n;i++) printf("%d ",sta[i]);
			for(int i=1;i<pos;i++) printf("%d ",sta[i]); puts("");
		}
	}
	return 0;
}
