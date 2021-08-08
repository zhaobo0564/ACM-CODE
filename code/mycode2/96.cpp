#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<functional>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<map>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int f[110][1100];
int h[N],ne[N],e[N],w[N],idx;
int a[N];
int tmp[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
    int i;
    for(i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(j==fa)
            continue;
        dfs(j,u);
        for(int k=0;k<=128;k++)
            tmp[k]=f[u][k];
        for(int k=0;k<=128;k++)  
            for(int l=0;l<=128;l++)
            if(tmp[k]&&f[j][l]){
                f[u][k^l]=1;
            }
    }
    f[u][0]=1;
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    memset(h,-1,sizeof h);
    for(i=1;i<=n;i++){
        cin>>a[i];
        f[i][a[i]]=1;
    }
    for(i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,-1);
    int res=0;
    for(i=1;i<=n;i++){
        for(int j=1;j<=128;j++){
            if(f[i][j])
                res=max(res,j);
        }
    }
    cout<<res<<endl;
}