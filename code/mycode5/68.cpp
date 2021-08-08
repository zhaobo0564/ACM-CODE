#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

const int N = 100007;

ll a[N],b[N];
ll ans, ans1;
int k, n, l;

void work() {
    int ok=0,r=n-1;
    ll now;
    ans=0;
    for(int i=0; i < n; i++){
        if(l - ( i % l ) <= k){
            ok++;
            if (ok >= k) {
                now = a[r];
                ans += now;
            }
            r--;
        } else {
            if (ok >= k) {
                ans += now;
            }
        }
    }
    k = l - k + 1;
    r = 0;
    ok = 0;
     ans1 = 0;
    for (int i = 0;i < n; i++){
        if (l - ( i % l) <= k){
            ok++;
            if( ok >= k ){
                now = a[r];
                ans1 += now;
            }
            r++;
        } else {
            if(ok>=k){
                ans1 += now;
            }
        }
    }   
}

int main(){
    int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&k);
		for(int i=0;i < n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		work();
		printf("%lld %lld\n",ans,ans1);
	}
}
