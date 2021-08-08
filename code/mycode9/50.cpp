#include<bits/stdc++.h>
#define N 5500
using namespace std;
typedef long long ll;
ll ct,cnt; 
ll fac[N],num[N];
const int BASE[]={2,3,5,7,11,13,17,19,23};
ll Quick_Mul(ll a,ll p,ll MOD)
{
    if(!p){
        return 0;
    }
    ll ans=Quick_Mul(a,p>>1,MOD);
    ans=(ans+ans)%MOD;
    if((p&1ll)==1ll){
        ans=ans+a%MOD%MOD;
    }
    return ans;
}
ll Quick_Pow(ll a,ll p,ll MOD)
{
    if(!p){
        return 1;
    }
    ll ans=Quick_Pow(a,p>>1,MOD);
    ans=Quick_Mul(ans,ans,MOD);
    if((p&1ll)==1ll){
        ans=a%MOD*ans%MOD;
    }
    return ans;
}
bool test(ll n,ll a,ll d){
    if(n==2){
        return 1;
    }
    if(n==a){
        return 0;
    }
    if(!(n&1)){
        return 0;
    }
    while(!(d&1ll)){
        d>>=1;
    }
    ll t=Quick_Pow(a,d,n);
    if(t==1){
        return 1;
    }
    while(d!=n-1ll && t!=n-1ll && t!=1ll){
        t=Quick_Mul(t,t,n);
        d<<=1;
    }
    return t==n-1ll;
}
bool Miller_Rabin(ll n){
    if(n==1 || n==3825123056546413051ll){
        return 0;
    }
    for(int i=0;i<9;++i){
        if(n==(ll)BASE[i]){
            return 1;
        }
        if(!test(n,(ll)BASE[i],n-1ll)){
            return 0;
        }
    }
    return 1;
}
ll pollard_rho(ll n,ll c){
    ll i=1,k=2;
    ll x=rand()%(n-1)+1;
    ll y=x;
    while(1){
        i++;
        x=(Quick_Mul(x,x,n)+c)%n;
        ll d=__gcd((y-x+n)%n,n);
        if(1ll<d &&d<n){
            return d;
        }
        if(y==x){
            return n;
        }
        if(i==k){
            y=x;
            k<<=1;
        }
    }
}
void find(ll n,int c){
    if(n==1){
        return;
    }
    if(Miller_Rabin(n)){
        fac[ct++]=n;
        return;
    }
    ll p=n;
    ll k=c;
    while(p>=n){
        p=pollard_rho(p,c--);
    }
    find(p,k);
    find(n/p,k);
}
ll n;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline void write(ll x){
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
int main(){
    srand(time(0));
    ll t;
    t = read();
    while(t--){
        n = read();
        if (n == 1) {
            puts("0");
            continue;
        }
        if (n % 2 == 0 && n % 4 != 0) {
            puts("1");
            continue;
        } else if (n % 3 == 0 && n % 9 != 0) {
            puts("1");
            continue;
        } else if (n % 5 == 0 && n % 25 != 0) {
            puts("1");
            continue;
        }
        ct=0;
        find(n,100);
        sort(fac,fac+ct);
        num[0]=1;
        int k=1;
      //  cout << ct << endl;
        for(int i=1;i<ct;++i){
            if(fac[i]==fac[i-1]){
                ++num[k-1];
            }
            else{
                num[k]=1;
                fac[k++]=fac[i];
            }
        }
        cnt=k;
        ll ans = 1e8;
        for(int i=0;i<cnt;++i){
          ans = min(ans, num[i]);
          if (ans == 1) break;
        }
        write(ans);
        puts("");
    } 
    return 0; 
}