#include <iostream>
#include <ctime>
#include <cstdio>
#include <cctype>
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh1 = '\n', hh2 = ' ';
int p, p3 = -1;
void read() {}
void print() { buf2[p3] = hh1; }
inline int getc()
{
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
    fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
    int f = 0;
    x = 0;
    char ch = getc();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = 1;
        ch = getc();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getc();
    }
    x = f ? -x : x;
    read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
    if (p3 > 1 << 20)
        flush();
    if (x < 0)
        buf2[++p3] = 45, x = -x;
    do
    {
        a[++p] = x % 10 + 48;
    } while (x /= 10);
    do
    {
        buf2[++p3] = a[p];
    } while (--p);
    buf2[++p3] = hh2;
    print(oth...);
}
} // namespace FastIO
using FastIO::print;
using FastIO::read;
//======================================
const int maxn = 1e4+5;
const int maxk = 1e7+5;
struct E
{
    int to,w,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot]=(E){v,w,Head[u]};
    Head[u]=tot++;
}
//? rt��¼���ģ�sum��¼��ǰ����С��cnt�Ǽ�����
int n,m,rt,sum,cnt;
//? tmp��¼����ľ��룬siz��¼������С��dis[i]Ϊrt��i֮��ľ���
//? maxp���������ģ�q���ڼ�¼����ѯ��
int tmp[maxn],siz[maxn],dis[maxn],maxp[maxn],q[105];
//? judge[i]��¼��֮ǰ�����о���i�Ƿ���ڣ�ans��¼��k��ѯ���Ƿ���ڣ�vis��¼��ɾ���Ľ��
bool judge[maxk],ans[105],vis[maxn];
//TODO ������
void getrt(int u,int f)
{
    siz[u]=1,maxp[u]=0; //maxp��ʼ��Ϊ��Сֵ
    //�������ж��ӣ���maxp��������С�Ķ��ӵĴ�С
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f||vis[v]) continue;  //��ɾ����Ҳ��Ҫ��
        getrt(v,u);
        siz[u]+=siz[v];
        if(siz[v]>maxp[u]) maxp[u]=siz[v];  //����maxp
    }
    maxp[u]=std::max(maxp[u],sum-siz[u]);   //����u�����Ƚ��
    if(maxp[u]<maxp[rt]) rt=u;      //�������ģ����������С��С��
}
//TODO ��������������֮��ľ��벢ȫ����¼��tmp��
void getdis(int u,int f)
{
    tmp[cnt++]=dis[u];
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f||vis[v]) continue;
        dis[v]=dis[u]+Edge[i].w;
        getdis(v,u);
    }
}
#include <queue>
//TODO ������������·��
//! ע��judge����Ҫ���֮ǰ��������ڵ�·�����ȣ��ų��۷�·���Ŀ���
void solve(int u)
{
    static std::queue<int> que;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(vis[v]) continue;
        cnt=0;              //ע�����������
        dis[v]=Edge[i].w;
        getdis(v,u);        //�Ѿ��붼�������
        for(int j=0;j<cnt;j++)      //�������о���
            for(int k=0;k<m;k++)    //��������ѯ��
                if(q[k]>=tmp[j])    //���ѯ�ʴ��ڵ���·�����ȣ��Ǿ��п��ܴ���
                    ans[k]|=judge[q[k]-tmp[j]]; //�����������·��ƴ�������Ǿʹ���
        for(int j=0;j<cnt;j++)      //�Ѵ��ڵĵ���·�����ȱ���true�����¸�������
        {
            que.push(tmp[j]);
            if (tmp[j] <= 10000000)
                judge[tmp[j]]=true;
        }
    }
    while(!que.empty())     //���judge���飬��Ҫ��memset
    {
        if (que.front() <= 10000000)
        judge[que.front()]=false;
        que.pop();
    }
}
//TODO ����
void divide(int u)
{
    vis[u]=judge[0]=true;   //ɾ�������
    solve(u);               //���㾭��������·��
    for(int i=Head[u];~i;i=Edge[i].next)    //����ʣ�ಿ��
    {
        int v = Edge[i].to;
        if(vis[v]) continue;
        maxp[rt=0]=sum=siz[v];  //��������Ϊ0������maxp[0]��Ϊ���ֵ
        getrt(v,0);
        getrt(rt,0);        //����������ͬ���ڶ��θ���siz��С
        divide(rt);
    }
}
#include <cstring>
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    clock_t c1 = clock();
    //======================================
    memset(Head,-1,sizeof(Head));
    read(n,m);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        read(u,v,w);
        AddEdge(u,v,w);
        AddEdge(v,u,w);
    }
    for(int i=0;i<m;i++) read(q[i]);
    maxp[0]=sum=n;  //maxp[0]��Ϊ���ֵ��һ��ʼrt=0��
    getrt(1,0);     //������
    //! ��ʱsiz�����ŵ�����1Ϊ��ʱ�ĸ�����С����Ҫ���ҳ�������Ϊ������
    getrt(rt,0);
    divide(rt);     //�Һ����ľͿ��Կ�ʼ������
    for(int i=0;i<m;i++)
    {
        if(ans[i]) puts("AYE");
        else puts("NAY");
    }
    //======================================
    FastIO::flush();
    std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;
    return 0;
}