#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if(a < b)swap(a, b);
        int cnt = 0;
        if(a == b){
            puts("0");
            continue;
        }
        while(1){
            if(a % 2 == 0)a = a / 2;
            else break;
            cnt++;
            if(a <= b)break;
        }
        if(a == b){
            //cout <<cnt << endl;
            int cn[10] = {0};
            cn[1] = cnt;
            cn[3] = cn[1] / 3;
            cn[1] = cn[1] % 3;
            cn[2] = cn[1]/ 2;
            cn[1] = cn[1] % 2;
            int ans = cn[3] + cn[1] + cn[2];
            printf("%d\n", ans);
        }else{
            puts("-1");
        }
    }
}