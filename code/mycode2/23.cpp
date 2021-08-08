#include<bits/stdc++.h>
using namespace std;
int t, n, k, a[40], b[40];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
        }
      
        while(k--){  
            sort(a + 1, a + n + 1);
            sort(b + 1, b + n + 1);
            if(a[1] < b[n]){
                swap(a[1], b[n]);
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i];
        }
        printf("%d\n", sum);
    }
}