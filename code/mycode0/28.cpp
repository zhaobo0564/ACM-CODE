#include<bits/stdc++.h>
using namespace std;

string a, b, c, d;

string big_add(string s1,string s2){
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    string res="";
    int flag = 0;
    string::iterator i,j;
    i=s1.begin();
    j=s2.begin();
    char c;
    for(;i!=s1.end()&&j!=s2.end();i++,j++){
       c = (flag + *i-'0'+*j-'0')%10+'0';
       flag = (flag + *i-'0'+*j-'0')/10;
       res+=c;
    }
    while(i!=s1.end()){
        c = (flag + *i-'0')%10+'0';
        flag = (flag + *i-'0')/10;
        res+=c;
        i++;
    }
    while(j!=s2.end()){
        c = (flag + *j-'0')%10+'0';
        flag = (flag + *j-'0')/10;
        res+=c;
        j++;
    }
    if(flag)    res+='1';
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        cin>>a>>b>>c>>d;
        a = big_add(a, b);
        a = big_add(a, c);
        a = big_add(a, d);
        cout<<a<<endl;
    }
}