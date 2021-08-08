#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], n, t, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a+ n + 1);
        int ans = 0, maxn = 0;
        for(int i = 1; i <= n; i++){
            int p = upper_bound(a + 1, a + n + 1, a[i] + k) - a;
            p--;
            if(p == 0)continue;

            ans = p - i + 1;
            maxn = max(maxn, ans);


        }
        printf("%d\n", maxn);
    }
}