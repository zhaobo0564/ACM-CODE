    #include<bits/stdc++.h> 
    #define ll long long
    using namespace std;
    int T;
    ll ans[500005];
    int main()
    {
    	ans[3]=8;
    	for(int i=5;i<=500000;i+=2)
    	{
    		ans[i]=ans[i-2]+1ll*(i-1)/2*4*(i-1);
    	}
    	scanf("%d",&T);
    	
    	while(T--)
    	{
    		int n;
    		scanf("%d",&n);
    		printf("%lld\n",ans[n]);
    	}
    }