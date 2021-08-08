#include<bits/stdc++.h>
using namespace std;
int n, a[250000];

int  main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if((n / 2) % 2 != 0){
            printf("NO\n");
        }else{
            printf("YES\n");

            for(int i = 1; i <= n; i++){
                if(i % 2 == 0){
                    printf("%d ", i);
                }
            }
            for(int i = 1; i < n - 1; i++){
                if(i % 2 == 1){
                    printf("%d ", i);
                }
            }
            printf("%d\n", n - 1 + n / 2);
        
        }
    }
}