    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    ll t,a,b,c,d;
     
    int main(){
    	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    	ll ans=0,num;
    	ll l=d-c+1;
    	for(ll i=a+b;i<=b+c;i++){
    		if(i>a+b&&i<b+c){
    			num=min(i-(a+b)+1,(b+c)-i+1);
    			num=min(num,min(b-a+1,c-b+1));
    		}
    		else num=1; 
    		ll tmp=i-c;
    		tmp=max(0ll,tmp);
    		tmp=min(tmp,l);
    		ans+=(tmp*num);
    	}
    	printf("%lld\n", ans);
    	
    	return 0;
     }