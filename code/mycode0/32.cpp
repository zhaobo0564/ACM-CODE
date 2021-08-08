#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int main(){
    scanf("%d", &t);
    while(t--){
        cin >> s;
        int h = 0, o = 0, c = 0;
        for(auto i: s){
            if(i == 'H')h++;
            else if(i == 'C')c++;
            else o++;
        }
        int ans = h + c * 12 + o * 16;
        printf("%d\n", ans);
    }
}