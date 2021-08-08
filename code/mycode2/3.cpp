#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        int cnt = (k - 1) * 2;
        if((n - cnt) % 2 == 0 && n - cnt > 0 ){
            puts("YES");
            for(int i = 1; i < k; i++){
                printf("2 ");
            }
            printf("%d\n", n - cnt);
        }else{
            cnt = k - 1;
            if((n - cnt) % 2 == 1 && n - cnt > 0){
                puts("YES");
                for(int i = 1; i < k; i++){
                    printf("1 ");
                }
                printf("%d\n", n - cnt);
            }else{
                puts("NO");
            }
        }
    }
}