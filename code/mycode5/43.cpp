#include<iostream>
using namespace std;
#define ll long long
ll nn,m,kk,la,ra,lb,rb,dis,sum,ans;
int main(){
    int tt;
	scanf("%lld",&tt);
	while(tt--){
		ans=0;
		scanf("%lld %lld",&nn,&kk);
		scanf("%lld %lld",&la,&ra);
		scanf("%lld %lld",&lb,&rb);
		m=nn;
		dis=(min(ra,rb)-max(la,lb));
		sum=max(ra,rb)-min(la,lb);
		if(dis>0){
			sum-=dis;
			kk-=dis*nn;
			dis=0;
		}
		else{
			dis=-dis;
		}
		if(kk<=0){
			printf("%lld\n",ans);
			continue;
		}
		ans=ans+dis+min(kk,sum);
		kk-=min(kk,sum);
		m--;
		while(kk*2>(dis+min(kk,sum))&&m){
			m--;
			ans = ans+dis+min(kk,sum);
			kk -= min(kk,sum);
		}
		ans += kk*2;
		printf("%lld\n",ans);
	}
}
