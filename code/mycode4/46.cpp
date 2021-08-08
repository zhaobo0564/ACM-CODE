#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string s;

int main(){
    scanf("%d", &t);
    while(t--){
        cin >> s;
        ll ans = 0, cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '-')cnt--;
            else cnt++;
            if(cnt < 0){
                ans += 1ll * (i + 1);
                cnt = 0;
            }
        }
        ans += s.length();
        cout << ans << endl;
    }
}