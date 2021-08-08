#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
const long long maxn=(long long)0xffffffff;
int num[16]={6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4};
int dig[20];
long long dp[20][205][3];
const int mod=16;
int t;
long long e,s;
long long dfs(int pos,long long sum,bool limit){
    if(pos==-1)return sum;
    if(dp[pos][sum][limit]!=-1)return dp[pos][sum][li];
    int up=limit?dig[pos]:mod-1;
    long long tmp=0;
    for(int i=0;i<=up;i++){
        tmp+=dfs(pos-1,sum+num[i],limit&&i==dig[pos]);
    }
    if(!limit)dp[pos][sum]=tmp;
    return tmp;
}
long long solve(long long x){
    for(int i=0;i<8;i++){
        dig[i]=x%mod;
        x/=mod;
    }
    cout << dp[7][0] << endl;
    return dfs(7,0,1);
}
int main(){
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--){
        scanf("%lld %llX",&e,&s);
        e--;
        e=e+s;
        if(e>maxn){//ffffffff
            e=e%(maxn+1);//fffffffff+1
            printf("%lld\n",solve(maxn)-solve(s-1)+solve(e));//ffffffff
        }
        else printf("%lld\n",solve(e)-solve(s-1));
    }
    return 0;
}