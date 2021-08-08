#include<iostream>
using namespace std;
 
int n,m,k,a[10007],dp[10007][107],minn=-1000000000;
 
int dfs(int p,int w){
    if(p>n){
        if(w==m)return 0;
        else{
            return minn;
        }
    }
    if(dp[p][w]!=minn)return dp[p][w];
    if(w==m) return dp[p][w]=dfs(p+1,w);
    return dp[p][w]=max(dfs(p+1,w),dfs(p+k,w+1)+a[p]);
}
 
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=minn;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1,0);

    printf("%d\n", dp[1][0]);
}