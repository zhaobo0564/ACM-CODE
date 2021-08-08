#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],b[N],p[N];
bool vis[N];
vector<int>v;
vector<pair<int,int>>ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        if(!vis[i])
    {
        vis[i]=true;
        if(p[i]==i) continue;
        if(b[p[i]]>=a[i])
        {
            printf("-1\n");
            return 0;
        }
        v.clear();
        v.push_back(i);
        vis[i]=true;
        for(int j=p[i];j!=i;j=p[j])
        {
            if(b[p[j]]>=a[j])
            {
                printf("-1\n");
                return 0;
            }
            v.push_back(j);
            vis[j]=true;
        }
        int pos=0;
        for(int i=1;i<v.size();i++)
            if(a[v[i]]>a[v[pos]]) pos=i;
        for(int i=pos+1;i<v.size();i++)
            ans.push_back({v[i],v[pos]});
        for(int i=0;i<pos;i++)
            ans.push_back({v[i],v[pos]});
    }
    printf("%d\n",ans.size());
    for(pair<int,int>x:ans)
        printf("%d %d\n",x.first,x.second);
}

