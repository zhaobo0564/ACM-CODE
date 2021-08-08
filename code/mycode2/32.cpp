#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int t, n, a[N];
int vis[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            vis[a[i]]++;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += vis[i] / i;
            vis[i + 1] += vis[i] % i;
        }
        printf("%d\n", ans);
        for(int i = 1; i <= n + 1; i++){
            vis[i] = 0;
        }
        
      
    }
}