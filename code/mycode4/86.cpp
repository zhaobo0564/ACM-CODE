#include<bits/stdc++.h>
using namespace std;

int t;

int main(){
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        if(s[s.length() - 1] == 'u' ){
            puts("JAPANESE");
        }else if(s[s.length() - 1] == 'o'){
            puts("FILIPINO");
        }else{
            puts("KOREAN");
        }

    }
}