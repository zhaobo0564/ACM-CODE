#include <bits/stdc++.h>
using namespace std;
int main()
{	char a[1000]={0},b[1000]={0};
	int ans[1000]={0};
	stack<char> t;
	int d;
	while(scanf("%d", &d) != EOF)
	{	int i,j=0;
        while (t.size()) t.pop();
		for(i=0;i<d;i++)
		{
			cin>>a[i];		
		}
		for(i=0;i<d;i++)
		{
			cin>>b[i];		
		}
		int k=0;
		for(i=0;i<d;i++)
	    {
		t.push(a[i]);
		ans[j++]=0;
		while(!t.empty()&&t.top()==b[k])
			{
			 ans[j++]=1;
			 t.pop();
			 k++;
			}
		}
	if(t.size()==0)
		{
		cout<<"Yes."<<endl;
		for(j=0;j<2*d;j++)
			if(ans[j]==1)
				cout<<"out"<<endl;
			else cout<<"in"<<endl;
		}
	else cout<<"No."<<endl;
	cout<<"FINISH";
	}
 	return 0;
}