#include<bits/stdc++.h>
using namespace std;
 
vector<int>R[100005];
bool F=0,V[100005]={0},S[100005];
void DFS(int x)
{
    int i,j;
    for(i=0;i<R[x].size();i++)
    {
        j=R[x][i];
        if(!V[j])V[j]=1,S[j]=!S[x],DFS(j);
        else if(S[x]==S[j])F=1;
    }
}
int main()
{
    int i,j,ans=0,n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&i,&j);
        R[i].push_back(j),R[j].push_back(i);
    }
    for(i=1;i<=n;i++)if(!V[i])ans++,V[i]=S[i]=1,DFS(i);
    printf("%d\n",ans-F);
}