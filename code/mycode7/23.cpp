#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct E
{
    int to,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot].to=v;
    Edge[tot].next=Head[u];
    Head[u]=tot++;
}
int siz[maxn],son[maxn];
void dfs(int u,int f)           //�������ʷ���ͬ��д�����ض���
{
    siz[u]=1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
int col[maxn],cnt[maxn];    //col���ĳ������ɫ��cnt���ĳ��ɫ�ڡ���ǰ�������е�����
long long ans[maxn],sum;    //ans�Ǵ����飬sum�����ۼӼ��������ǰ�������Ĵ�
int flag,maxc;              //flag���ڱ���ض��ӣ�maxc���ڸ������ֵ
//TODO ͳ��ĳ��㼰����������ӵĹ���
void count(int u,int f,int val)
{
    cnt[col[u]]+=val;//valΪ��Ϊ�����Կ��������ӹ��׻���ɾ������
    if(cnt[col[u]]>maxc)    //�����ֵ�����ٰ�
    {
        maxc=cnt[col[u]];
        sum=col[u];
    }
    else if(cnt[col[u]]==maxc)  //����������Ϊ���������ɫ������ͬ�Ƕ�����
        sum+=col[u];
    for(int i=Head[u];~i;i=Edge[i].next) //�ų�����ǵ��ض��ӣ�ͳ����������������Ϣ
    {
        int v = Edge[i].to;
        if(v==f||v==flag) continue; //����дif(v==f||v==son[u]) continue;
        count(v,u,val);
    }
}
//dsu on tree�İ���
void dfs(int u,int f,bool keep)
{   
    cout << "node = " << u << endl;
    //* ��һ����������Ӽ������������ɾ����
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f||v==son[u]) continue;
        dfs(v,u,false);
    }
    //* �ڶ��������ض��Ӽ�����������𰸲�ɾ����
    if(son[u])
    {
        dfs(son[u],u,true);
        flag = son[u];
    }
    //* ������������ͳ��u������������ӵĹ��׺ϲ�����������ض�����Ϣ��
    count(u,f,1);
    flag = 0;   
    ans[u] = sum;
    //* ����Ҫɾ�����׵�ɾһɾ
    if(!keep)
    {
        count(u,f,-1);
        sum=maxc=0; //������Ϊcount�����л�ı�����������ֵ
    }
}

#define ONLINE_JUDGE 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    memset(Head,-1,sizeof(Head));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",col+i);
    for(int i=1,u,v;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        AddEdge(u,v);
        AddEdge(v,u);
    }
    dfs(1,0);
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
        printf("%I64d ",ans[i]);
    return 0;
}