#include<bits/stdc++.h>
using namespace std;
int t, n;
const int N = 2e5 + 7;
int a[N];

int vis[1000000];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            int ans = ((i + a[i])%n + n)%n;
            vis[ans]++;
        }
        int f = 0;
        for(int i = 0; i <= n; i++){
            if(vis[i] > 1){
                f = 1;
                break;
            }
        }
        if(f)puts("NO");
        else puts("YES");
        for(int i = 0; i <= n; i++)vis[i] = 0;
    }
}