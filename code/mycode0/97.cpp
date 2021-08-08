#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, n, a[N], b[N];


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
        }
        int ok = 0, one = 0, fu = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > b[i]){
                if(!fu){
                    ok = 1;
                    break;
                }
            }else if(a[i] < b[i]){
                if(!one){
                    ok = 1;
                    break;
                }
            }

            if(a[i] == 1)one = 1;
            else if(a[i] == -1) fu = 1;
        }
        if(ok){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}