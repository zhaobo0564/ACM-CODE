#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=520;

void extend_gcd(ll a,ll b,ll &x,ll &y){
  if(b==0){
    x=1;
    y=0;
    return;
  }
  extend_gcd(b,a%b,y,x);
  y=y-x*(a/b);
}

ll inverse(ll a,ll m){
  ll x,y;
  extend_gcd(a,m,x,y);
  return (x%m+m)%m;
}


int main(){
  int t;
  ll n,b,c;
  cin>>t;
  while(t--){
    cin>>n>>b;
    cout << (n / b) % mod << endl;
    c=inverse(b,mod);
    cout<<(n*c)%mod<<endl;
  }
} 