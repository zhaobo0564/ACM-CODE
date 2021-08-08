#include<bits/stdc++.h>
using namespace std;
int T;
long long ans;
int dp[17][120][120];//dp[pos][pre][ans] pre代表前面数字各个数位的和，ans代表目前的结果
int a[20];
int len;
long long dfs(int pos,int pre,int limit,int cnt,int mod)
{
    if(pre>mod) return 0;
    if(pos==len)
    {
        if(pre==mod&&cnt==0) return 1;
        else return 0;
    }
    if(!limit&&dp[pos][pre][cnt]!=-1)
    {
        return dp[pos][pre][cnt];
    }
    int up=limit?a[pos]:9;
    long long ret=0;
    for(int i=0;i<=up;i++)
    {
        ret+=dfs(pos+1,pre+i,limit&&(i==a[pos]),(cnt*10+i)%mod,mod);
    }
    if(up == 9) dp[pos][pre][cnt]=ret;
    return ret;
}
void init(string str)
{
    len=str.size();
    for(int i=0;i<len;i++)
    {
        a[i]=str[i]-'0';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=0;
        string h;
        cin>>h;
        init(h);
        for(int j=1;j<=9*len;j++)
        {
            memset(dp,-1,sizeof(dp));
            ans+=dfs(0,0,1,0,j);
        }
        printf("Case %d: %lld\n",i,ans);
    }
}