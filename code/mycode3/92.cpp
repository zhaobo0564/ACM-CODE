#include<bits/stdc++.h>
using namespace std;
int t, n , a[100], b[100];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            if(a[i] % 2 == 0){
                if(i % 2 == 0){
                    b[i] = 0;
                }else{
                    b[i] = 1;
                }
            }else{
                if(i % 2){
                    b[i] = 0;
                }else{
                    b[i] = -1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(b[i] != b[j] && b[i] != 0 && b[j] != 0){
                    b[i] = 0;
                    b[j] = 0;
                    ans++;
                }
            }
        }
        int f = 0;
        for(int i = 0; i < n; i++){
            if(b[i] != 0){
                f = 1;
                break;
            }
        }
        if(f){
            puts("-1");
        }else{
            printf("%d\n", ans);
        }

    }
}