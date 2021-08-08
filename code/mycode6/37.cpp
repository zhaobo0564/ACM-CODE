#include<cstdio>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int T,a[20],x,y,z,t,n,i,d,ans,b[20],c[20];
int P[100050];
int nump;
void init()
{
    for(int i=2;i<=50000;i++)
    {
        int flag=0;
        for(int j=2;j*j<=i;j++)
        {
            if((i/j)*j==i)flag=1;
        }
        if(flag==0)P[++nump]=i;
    }
}
void work(int k)
{
    b[k]=c[k]=0;
    if(a[k]==1)return;
    int aa=a[k];
    while(aa%2==0)
    {
        aa/=2;
        b[k]++;
    }
    for(int i=2;P[i]*P[i]-a[k]<=0;i++)
    {
        while(aa%P[i]==0)
        {
            c[k]++;
            aa/=P[i];
        }
    }
    if(aa>1)c[k]++;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>T;
    init();
    while(T--)
    {
        cin>>n;
        x=0;
        y=0;
        z=0;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            work(i);
            if(b[i]==0&&c[i]==0)a[i]=0;
            if(c[i]==0&&(b[i]+c[i])==1)a[i]=1;
            else
            {
                a[i]=c[i];
                if(b[i])a[i]++;
            }
            ans^=a[i];
         
        }
      
        if(ans)cout<<"W"<<endl;
        else cout<<"L"<<endl;
    }
    return 0;
}
