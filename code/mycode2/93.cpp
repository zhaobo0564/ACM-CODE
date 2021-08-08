#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] <= i){
                ans = max(ans, i);
            }
        }
        printf("%d\n", ans + 1);
    }
}