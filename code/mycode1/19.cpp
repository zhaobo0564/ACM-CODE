#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, x, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &x, &n, &m);
        int now = x;
        while(n--){
            x = x / 2 + 10;
            if(x >= now){
                break;
            }
            now = x;
        }
        if(x >= now) x = now;
        if(m * 10 >= x){
            printf("YES\n");
        }else{
            printf("NO\n");
        }


    }
}