#include<bits/stdc++.h>
const int N = 1e5 + 7;

int n, a[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 30; i >= -30; i--){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] <= i){
                sum = std::max(0, sum) + a[j];
                ans = std::max(ans, sum - i);
            }
        }
    }
    printf("%d\n", ans);
}