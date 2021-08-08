#include<bits/stdc++.h>
using namespace std;

int n; 
string s;

int main(){
    scanf("%d", &n);
    cin >> s;
    long long ans = 0;
    for(int i = 0; i < s.length(); i++){
        if((s[i] - '0') % 2 == 0){
            ans += i + 1;
        }
    }
    printf("%lld\n", ans);
}