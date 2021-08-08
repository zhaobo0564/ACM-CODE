#include<bits/stdc++.h>
using namespace std;
const int N = 2007;
int a[N], n, h, l, r;
int sum[N];

int main(){
    scanf("%d%d%d%d",&n, &h, &l, &r);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=(sum[i-1]+a[i])%h;
    }
    int good=0;
    for(int i=1;i<=n;i++){
        int ll =(sum[i]-(i%h)+h)%h;
        int rr=sum[i];
        if(rr<ll){
            good++;
            continue;
        }
       // cout<<"l="<<ll<<" r="<<rr<<endl;
        if(rr<l){

        }else if(ll>r){

        }else{
            good++;
        }
    }
    printf("%d\n",good);
}