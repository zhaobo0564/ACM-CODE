#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        int one = 0, zero = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0')zero++;
            else one++;
        }
        one = min(zero, one);
        if(one % 2){
            puts("DA");
        }else{
            puts("NET");
        }
    }
}