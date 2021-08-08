#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=5e6+7;

char s[N];
int n;

ll base[3]={27,29,(int)1e5+7};
ll mod[3]={(int)113456789,998244353,(int)1e7+7};

ll p[3][N],h[4][N];

void init(){
	p[0][0]=p[1][0]=p[2][0]=1;
	for(int i=1;i<N;i++){
		p[0][i]=p[0][i-1]*base[0]%mod[0];
		//p[1][i]=p[1][i-1]*base[1]%mod[1];
		//p[2][i]=p[2][i-1]*base[2]%mod[2];
	}
}

ll Hsh(int l,int r,int id){
	return ((h[id][r]-h[id][l-1]*p[id][r-l+1])%mod[id]+mod[id])%mod[id];
}

const ll M=1e7+7;

ll tmp[M];

ll hhsh(ll a,ll b,ll c){
	ll res=0;
	res=(res*base[0]+a)%M;
	res=(res*base[0]+b)%M;
	res=(res*base[0]+c)%M;
	return res;
}

int f=0;

bool check(int k){
	f++;
	for(int i=0;i<k;i++){
		ll a=(Hsh(i+1,k,0)*p[0][i]%mod[0]+Hsh(1,i,0))%mod[0];
		//ll b=(Hsh(i+1,k,1)*p[1][i]%mod[1]+Hsh(1,i,1))%mod[1];
		//ll c=(Hsh(i+1,k,2)*p[2][i]%mod[2]+Hsh(1,i,2))%mod[2];
        ll c = 1;
		ll key=hhsh(a,b,c);
		tmp[key]=f;
	}

	for(int i = k + 1;i<=n;i+=k){
		ll a=Hsh(i,i+k-1,0);
		ll b=Hsh(i,i+k-1,1);
		//ll c=Hsh(i,i+k-1,2);
        ll c = 1;
		ll key=hhsh(a,b,c);
		
		if(tmp[key]!=f) return 0;
	}
	return 1;
}

int main(){
    freopen("1009.in", "r", stdin);   //只改变输入流的文件指针，读入这个文件的内容（必须要有input这个文件）stdin是标准输入流的文件指针
   freopen("output.txt", "w", stdout);
    init();
	int T=input();
	while(T--){
		n=input();
		scanf("%s",s+1);

		h[0][0]=h[1][0]=h[1][0]=0;
		for(int i=1;i<=n;i++){
			h[0][i]=(h[0][i-1]*base[0]+s[i])%mod[0];
			//h[1][i]=(h[1][i-1]*base[1]+s[i])%mod[1];
			//h[2][i]=(h[2][i-1]*base[2]+s[i])%mod[2];
		}

		int flag=0;
		for(long long k=1;k*k<=n;k++){
			if(n%k==0){
				if(n/k==1) continue;
				flag=check(k);
				if(flag) break;
				if(n/(n/k)==1) continue;
				flag=check(n/k);
				if(flag) break;
			}
		}

		if(flag) printf("Yes\n");
		else printf("No\n");
	}
}

