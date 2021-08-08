#include <bits/stdc++.h>

using namespace std;

#define ll long long

string s,t;
int cnt1[26],cnt2[26];
map <string,int> p;

int main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin>>s>>t;

	for(int i=0;i<s.length();i++){
		cnt1[s[i]-'a']++;
	}

	if(s.length()<=t.length()){
		for(int i=0;i<s.length();i++){
			cnt2[t[i]-'a']++;
		}

		int Ans=0;

		for(int l=0,r=s.length()-1;r<t.length();r++,l++){
			int flag=1;
			for(int i=0;i<26;i++){
				if(cnt1[i]!=cnt2[i]) flag=0;
			}
			
			if(flag){
				string tmp="";
				for(int i=l;i<=r;i++) tmp+=t[i];
				if(!p[tmp])Ans++;
				p[tmp]=1; 
			}

			cnt2[t[l]-'a']--;
			if(r+1<t.length()) cnt2[t[r+1]-'a']++;
		}

		printf("%d\n",Ans);
	}else printf("0\n");
}
