#include<bits/stdc++.h>
using namespace std;

const int N = 2007;

int t, n, a[N];

int sum[N][30], cnt[N][30];
int v[30];

int work(int l, int r){
    if(l + 1 > r - 1)return 0;
    int vis[27];
    for(int i = 1; i <= 26; i++){
        vis[i] = 0;
    }
    for(int i = l + 1; i <= r - 1; i++){
        vis[a[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= 26; i++){
        ans = max(ans, vis[i]);
    }
    return ans;
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
         for(int i = 0; i<= n + 1; i++){
            for(int j = 0; j <= 26; j++ ){
                sum[i][j] = cnt[i][j] = 0;
                v[j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        
        for(int i = 1; i <= n; i++){
            
            v[a[i]]++;
            sum[i][a[i]] =  v[a[i]];
        }
        memset(v,0, sizeof(v));
        for(int i = n; i; i--){
            v[a[i]]++;
            cnt[i][a[i]] = v[a[i]];
        }
        int l, r;
        int ans = 0, maxn = 0;
        for(int i = 1; i <= n; i++){
            int cat = sum[i][a[i]];
            maxn = max(maxn, sum[i][a[i]]);

            for(int j = n; j > i; j--){
           
                if(a[j] == a[i] && cat == cnt[j][a[j]]){
                 
                    ans = work(i, j);

                    maxn = max(maxn, ans + cat + cat);
                    break;
                }
            }
        }
        printf("%d\n", maxn);
       

    }
}