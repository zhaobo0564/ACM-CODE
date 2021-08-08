#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

char a[10];

int main(){
    cin >> s;
    a[1] = 'a', a[2] = 'e', a[3] = 'i', a[4] = 'o', a[5] = 'u';
    ll ans = 0;
    for(int i = 0; i < s.length(); i++){
        int l = 1;
        for(int j = i; j < s.length(); j++){
            if(l % 2){
                if(s[j] != a[1] || s[j] != a[2] || s[j]) != a[3] || s[j] != a[4] || s[j] != a[5]){

                }else{
                    if(l >= 6){
                        if(l % 2 == 0){
                            ll cnt = l - 6;
                            cnt = cnt / 2;
                            ans += ((cnt + 1) * cnt) / 2;
                        }
                    }
                } 
            }
        }
    }

}