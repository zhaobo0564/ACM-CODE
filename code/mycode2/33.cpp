    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    ll t,a,b,c,d;
     
    int main(){
    	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    	ll ans=0,num;
    	ll l=d-c+1;
    	for(ll i = c; i <= d; i++){
			ll x = i - a;
			if(x < b){
				ans += (b - a + 1) * (c - b + 1);
			}else if (b <= x && x <= c){
				ans += (c - x) * (b - a + 1);
			//	cout << "ans = " << ans << endl;
				ll len = (x - b + 1);
				ll len1 = b - a;
			//	cout << "len " << len << endl;
				if(len > len1){
					ans += (len1 + 1) * len1 / 2;
				}else{
					ans += (len1  + len1 - len + 1) * (len) / 2;
				}

			}else{
				ll l = x - c ;
				ll cnt = a + l + 1;
				if(cnt > b)continue;
				ll len = c - b + 1;
				ll len1 = b - cnt + 1;
				if(len > len1){
					ans += (len1 + 1) * len1 / 2;
				}else{
					ans += (len1 + len1 - len + 1) * len / 2;
				}
				
			}
			//cout << ans << endl;
		}
		printf("%lld\n", ans);
     }