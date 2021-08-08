#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
    char ch=getchar(); int x=0,fl=1;
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
    return x*fl;
}
const int N=500005;
  
int n,m,x,l,r,a[N],st[N],rr[N],p1[N<<1],p2[N<<1];
LL ans;
unordered_map<int,int> ct[N<<1];
int L=1e6;

void ins(int x,int y){
	if(!p1[x]) p1[x]=y;
	else p2[x]=y;
}
int get(int x,int y){
	if(y<0) return 0;
	int res=0;
	if(p1[y]==x) res++;
	if(p2[y]==x) res++;
	return res;
}
  
int main(){
    n=read(); m=read(); x=l=r=read();
    for(int i=1;i<=n;i++) a[i]=read();
    memset(st,-1,sizeof(st));
    l--; r++;
	st[x]=0; ins(0,a[x]);
    rr[0]++;
    int lst=0;
    for(int i=1;i<=m;i++){
        int opt=read(),h=read();
        int res=h-lst,tmp=lst+1;
        while(l>=1&&tmp<=h){
            st[l]=tmp;
            rr[tmp]++;
            if(a[l]<=L) ins(st[l],a[l]);
            l--;
            tmp++;
        }
        tmp=lst+1;
        while(r<=n&&tmp<=h){
            st[r]=tmp;
            rr[tmp]++;
            if(a[r]<=L) ins(st[r],a[r]);
            r++;
            tmp++;
        }
        //-st[j]==cc/a[j]-h
        if(opt==1){
            int cc=read();
            if(!cc) ans+=1LL*rr[h];
            for(int j=1;j*j<=cc;j++){
                if(cc%j==0){
                    ans+=1LL*get(j,h-cc/j);
                    if(j*j!=cc) ans+=1LL*get(cc/j,h-j);
                }
            }
        }
        else cout<<ans<<'\n';
        lst=h;
    }
    return 0;
}