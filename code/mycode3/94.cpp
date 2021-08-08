#include<bits/stdc++.h>
using namespace std;
const int maxn = 3007, INF = 0x7f7f7f7f;
int a[maxn], vis[maxn];
int n,ans = 0;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = i + 1; j <= n; j++){
                if(vis[j])continue;
                if(a[i] > a[j]){
                    cnt++;
                    vis[j] = 1;
                }
            }
            int cn = min(i, n - i );
            ans += cn * cnt;
        }
        int res = ans;
     //   cout << res << endl;
        // ans = 0;
        // for(int i = 1; i <= n; i++)vis[i] = 0;
        // for(int i = n; i ; i--){
        //     int cnt = 0;
        //     for(int j = i - 1; j; j--){
        //         if(vis[j])continue;
        //         if(a[i] < a[j]){
        //             cnt++;
        //         }
        //     }
        //     int cn = min(n - i + 1, i);
        //     ans += (n - i + 1) * cnt;
        // }
        res = min(res, ans);
        res = min(res, n - 1);
        printf("%d\n",res);
        for(int i = 1; i <= n; i++)vis[i] = 0;
       
    }

}
