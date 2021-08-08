#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        queue<int>q,p;
        for(int i=1;i<=n;i++)
        {
            if(q.empty())q.push(a[i]);
            else if(q.front()!=a[i])q.push(a[i]);
            else {
                q.pop();
            }
        }
        if(q.empty())puts("Frederica Bernkastel");
        else puts("Furude Rika");
    }
    return 0;
}
