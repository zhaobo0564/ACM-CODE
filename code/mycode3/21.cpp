#include<bits/stdc++.h>
using namespace std;
int t;
string s;

int main(){
    scanf("%d",&t);
    while(t--){
        cin >> s;
        int ans = 0, cnt = 0;
        for(int i = 0; i <s.length(); i++){
            if(s[i] == '1')cnt++;
        }
        if(s[0] == '1') ans = cnt - 1;
        else if(s[s.length() - 1] == '1')ans = cnt - 1;
        else ans = cnt;
        ans = min(ans, cnt);
        int x = s.length();
        ans = min(ans, x - cnt);
        int cnt1= 0, cat = cnt;
        for(int i = 0; i <s.length(); i++){
            if(s[i] == '0'){
                cnt1++;
            }else{
                cat--;

            }
             int cn = cnt1 + cat;
            ans = min(ans, cn);
        }
        cat =x - cnt, cnt1 =0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                
                cnt1++;
            }else{
                cat--;
            }
            int cn = cnt1 + cat;
            ans = min(ans, cn);
        }

        printf("%d\n", ans);

    }
}