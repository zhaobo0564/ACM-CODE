#include<bits/stdc++.h>
using namespace std;
int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            ans += a * b;
        }
        printf("%d\n", ans);
    }
}