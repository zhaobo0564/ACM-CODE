#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> v;
int n;
double now=0;
int nown=0;
double  num[12]={0,1.0,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0,4.3};
double ans=0;
void dfs(int ct)
{
	if(ct==5) 
	{
		ans=max(ans,now);
//		printf("%lf\n",now);
		return ;
	}
	for(int i=0;i<=10;i++)
	{
		if(nown>=v[i]&&nown>=0)
		{
//			printf("%d> %d\n",nown,v[i]);
			nown-=v[i] ;
			now+=num[i];
			dfs(ct+1);
			now-=num[i];
			nown+=v[i];
		}
		else break;
	}
//	puts("66");
}
int main()
{
	v.push_back(95);
	v.push_back(90);
//	v.push_back(0);
	v.push_back(85);
	v.push_back(80);
	v.push_back(75);
	v.push_back(70);
	v.push_back(67);
	v.push_back(65);
	v.push_back(62);
	v.push_back(60);
	v.push_back(0);
	sort(v.begin(),v.end())	;
//	for(int i=0;i<v.size();i++)
//	{
//		printf("%d ",v[i]);
//	}
//	puts("");
	cin>>t;
	while(t--)	
	{
		int n;
		cin>>n;
		now=0;
		nown=n;
		ans=0;
//		if(n<=59)
//		{
//			printf("0.0\n");
//			continue;
//		}
//		puts("99");
		dfs(1);
		printf("%.1lf\n",ans);
	}
}
