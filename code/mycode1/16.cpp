#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int dp[3700], a[N];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            a[i] = a[i] % 3600;
           
        }
        memset(dp, 0, sizeof(dp));
        dp[a[1]] = 1;

        for(int i = 2; i <= n && !dp[0]; i++){
            vector<int>v;
            for(int j = 1; j < 3600; j++){
                if(dp[j]){
                   v.push_back((j + a[i]) % 3600);
                }
            }
            for(int j : v){
                dp[j] = 1;
            }
            dp[a[i]] = 1;
        }
        if(dp[0]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        

    }
}