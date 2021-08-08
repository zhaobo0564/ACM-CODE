#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long a, b, c, d;

int main(){
    cin >> a >> b >> c >> d;
    long long ans = 0;
    for(int i = 1; i <=  10; i++){
        for(int j = 1; j <= 10; j++){
            if(__gcd(i, j) != 1)continue;
            if(i + j < 1000){
                ll cnt = (a) / i;
                ll cnt1 = b / i;
                ll cn = (c) / j;
                ll cn1 = (d) / j;
                ll l = max(cnt, cn);
                ll r = min(cnt1, cn1);
                
              //  cout << l << " " << r << endl; 
                if(r >= l){
                  //  cout << cnt << " " << cnt1 << " " <<cn << " " << cn1 <<" " <<r - l + 1<< endl;
                    ans += r - l + 1;
                }

            }
        }
    }
    printf("%lld\n", ans);
}