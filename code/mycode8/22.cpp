#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <bitset>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<' ';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, P2 = 998244353, INF = 0x3f3f3f3f;
const ll bas[]={122777,163729};
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head
 
 
const int N = 1e6+10;
int n, m, k, a[N];
int has[N], fac[N];
vector<int> g[N];
 
int Hash(int l, int r) {
	int ret = (has[r]-(ll)has[l-1]*fac[r-l+1])%P;
	if (ret<0) ret+=P;
	return ret;
}
int chk(int x, int y, int add) {
	int l=0,r=n,pos;
	while (l<=r) {
        cout << "l " << x << " r = " << x + mid - 1 << endl;
        cout << "l1 " << y << "r = " << y + mid - 1 << endl;
		if (Hash(x,x+mid-1)==Hash(y,y+mid-1)) pos=mid,l=mid+1;
		else r=mid-1;
	}
	return (a[x+pos]+add)%m<(a[y+pos]+add)%m?x:y;
}
 
 
int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP(i,1,n) {
		scanf("%d", a+i);
		g[a[i]].pb(i);
		a[i+n]=a[i];
	}
	fac[0]=1;
	REP(i,1,2*n) { 
		has[i]=(has[i-1]*bas[0]+a[i])%P;
		fac[i]=fac[i-1]*bas[0]%P;
	}
	int ans = 1;
	REP(i,2,n) ans = chk(ans,i,0);
    cout << "ans " << ans << endl;
	printf("%d\n", a[ans+k-1]);
	REP(i,1,m-1) {
		int sz = g[m-i].size();
		if (sz) {
			ans = g[m-i][0];
			REP(j,1,sz-1) ans = chk(ans,g[m-i][j],i);
		}
		printf("%d\n", (a[ans+k-1]+i)%m);
	}
}