#include<iostream>
using namespace std;
#define ll long long
ll n;
double x;
double ksm(double x,ll n){
    double res=1;
    while(n){
        if(n&1){
            res=res*x;
            while(res>10){
                res/=10;
            }
        }
        x=x*x;
        while(x>10){
            x/=10;
        }
        n/=2;
    }
    return res;
}
int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        x=n;
        while(x>10){
            x/=10;
        }
        double res=ksm(x,n);
        printf("%lld\n",(ll)res);
    }
}