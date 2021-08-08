#include<bits/stdc++.h>
using namespace std;
const int N = 507;
int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for(int i = 2; i <= n - 1; i++){
           ans += a[i + 1] - a[i] - 1;
        }
        int ans1 = 0;
        for(int i = 1; i <= n - 2; i++){
            ans1 += a[i + 1] - a[i] - 1;
        }

        printf("%d\n", max(ans, ans1));
    }
}