#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin>>s;
    string a = "XiaoQiao";
    string b = "XiaoHuiHui";
    int j = 0;
    for(int i =0; i < s.length(); i++){
        if(a[j] == s[i]){
            j++;
        }
    }
    int c = 0;
    for(int i = 0; i < s.length(); i++){
        if(b[c] == s[i]){
            c++;
        }
    }
    if(j == 8 && c == 10){
        printf("Happy\n");
    }else{
        printf("emm\n");
    }
}