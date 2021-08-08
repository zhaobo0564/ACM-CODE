#include<bits/stdc++.h>
using namespace std;

int n, m, x, c[20], a[20][20];
int minn = INT_MAX;

void dfs(int p, int va){
    if(p == n){
        int cnt = va;
        int sum[20];
        for(int i = 1; i <= m; i++)sum[i] = 0;
        int pos = 0;
        int ans = 0;
        while(cnt){
            if(cnt & 1){
                for(int i = 1; i <= m; i++){
                    sum[i] += a[pos][i];
                }
                ans += c[pos];
            }
            pos++;
            cnt /= 2;

        }
        int f = 0;
        for(int i = 1; i <= m; i++){
            if(x > sum[i]){
                f = 1;
                break;
            }
        }
        if(f == 0){
            minn = min(minn, ans);
        }
        return;
    }
    dfs(p + 1, va+(1<<(p + 1)));
    dfs(p + 1, va);
}

int main(){
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    dfs(1, 2);
    dfs(1, 0);
    if(minn == INT_MAX){
        printf("-1\n");
    }else{
        printf("%d\n", minn);
    }

}