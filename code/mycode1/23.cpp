#include<bits/stdc++.h>
using namespace std;
int n, k, a[1000];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] <= k){
            ans++;
        }else{
            break;
        }
    }

    for(int i = n; i; i--){
        if(a[i] <= k){
            ans++;
        }else{
            break;
        }
    }
    if(ans > n){
        printf("%d\n", n);
    }else{
        printf("%d\n", ans);
    }


}