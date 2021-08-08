#include<bits/stdc++.h>
using namespace std;

int n, m, up[20];
int dp[20][10];

int dfs(int p, int pre, int flag){
    if(p == 0)return 1;
    int maxn, ans = 0;
    if(!flag && dp[p][pre] != -1 ) return dp[p][pre];
    if(!flag)maxn = 9;
    else maxn = up[p];
 //   cout <<"p = " << p << "maxn = " << maxn << endl;
    for(int i = 0; i <= maxn; i++){
        if(i == 4)continue;
        if(pre == 6 && i == 2)continue;
        ans += dfs(p - 1, i, flag && (i == maxn));
    }
    if(!flag)dp[p][pre] =  ans;
   
    return ans;

}

void init(int x){
    int cnt = 0;
    while(x){
       
        up[cnt + 1] =  x % 10;

        x = x / 10;
        cnt++;
    }
}

int main(){
    while(~scanf("%d %d", &n, &m) && (n + m)){
        init(m);

        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        while(m){
            m = m / 10;
            cnt++;
        }
        int ans = dfs(cnt, 0, 1);
        n--;
        init(n);
        cnt = 0;
        while(n){
            n = n / 10;
            cnt++;
        }
        printf("%d\n", ans - dfs(cnt, 0, 1));
    }
    
    
}