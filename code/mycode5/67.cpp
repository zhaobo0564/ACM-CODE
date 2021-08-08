#include <bits/stdc++.h>

using namespace std;

#define ll long long


inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define ut unsigned int
const int N=8e7 + 1;

bool mark[N];
vector<ll> p;
int cnt;
inline void init(){
	p.emplace_back(0);
	cnt=0;
	for (int i=2 ; i < N ; ++i){
		if (!mark[i]) p.emplace_back(i),cnt++;
		for (int j=1 ; j<=cnt && i*p[j]<N ; ++j){
			mark[i*p[j]]=1;
			if (!(i%p[j])) break;
		}
	}
}

#define PII pair <ll,ll>
#define fr first
#define sc second
#define mp make_pair

vector<PII> ok;

int main(){
	init();

	ll n  = read();
	ut a,b;
	a = read(), b = read();

	for(int i=1;i<=cnt;i++){
		if(p[i]>n) break;
		if(p[i]*p[i]>n){
			break;
		}else{
			for(ll j=p[i];j<=n;j=j*p[i]){
				if(j>n) break;
				ok.emplace_back(mp(j,p[i]));
			}
		}
	}

	sort(ok.begin(),ok.end());

	int now=0;
	for(int i=1;i<=cnt;i++){
		if(p[i]>n) break;
        int sz = ok.size();
		while(now<sz&&ok[now].fr<p[i]){
			a=a*ok[now].sc+b;
			now++;
		}
		if(p[i]*p[i]>n){
			a=a*p[i]+b;
		}
	}
    int sz = ok.size();
	while(now<sz) a=a*ok[now].sc+b,now++;

	printf("%lld\n", a);
}
