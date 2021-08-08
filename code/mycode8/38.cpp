#include<bits/stdc++.h>
using namespace std;

bool judge(string s, string t) {
	int ok = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == t[0] && i + t.length() < s.length()) {
			ok = 0;
			for (int j = 0; j < t.length(); j++) {
				if (s[i + j] == t[j]) {

				} else {
					ok = 1;
					break;
				}
			}
			if (!ok) {
				return true;
			}
		}
	}
	return false;

}

int main()
{
	string key;
	int flag,n;
	cin>>key;
	scanf("%d",&flag);
	scanf("%d",&n);
	while(n--)
	{
		string s;
		cin>>s;
		if(flag==0)//不区分大小写 
		{
			for(int i=0;i<key.length();i++)
			{
				if(key[i]>='A'&&key[i]<='Z')
				{
					key[i]+=32;
				}
			}
			for(int i=0;i<s.length();i++)
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					s[i]+=32;
				}
			}
		}
		if(judge(s, key))
		{
			cout<<s;
		}
		if(n!=0&&judge(s, key))
		{
			cout<<endl;
		}
	}
}
