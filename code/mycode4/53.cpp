#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>
 
#define LL long long
#define DB double
#define SI(a) scanf("%d",&a)
#define SD(a) scanf("%lf",&a)
#define SS(a) scanf("%s",a)
#define SF scanf
#define PF printf
#define MM(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define N 100009
#define INF 0x3f3f3f3f
#define EPS 1e-8
#define bug puts("bug")
using namespace std;
map<string,int> city;
map<string,int> peop;
struct nod{
    char ch[2][29];
    LL k;
} re1[N],re2[N];
int n,m,d;
LL money[N];
int sum[N];
char where[N][29];
string recity[N];
struct TR{
    LL mx;int two,p;
} tree[N<<2];
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
void update(int rt)
{
    int l=rt<<1,r=rt<<1|1;
    if(tree[l].mx>tree[r].mx)
    {
        tree[rt] = tree[l];
    }else if(tree[l].mx<tree[r].mx)
    {
        tree[rt] = tree[r];
    }else
    {
        tree[rt].mx = tree[l].mx;
        tree[rt].two = 1;
        tree[rt].p = -1;
    }
}
void build(int rt,int l,int r)
{
    if(l==r)
    {
        tree[rt].mx = 0;
        tree[rt].two = 0;
        tree[rt].p = l;
        return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    update(rt);
}
void add(int p,LL c,int rt,int l,int r)
{
    if(l==r)
    {
        tree[rt].mx += c;
        tree[rt].two = 0;
        return ;
    }
    int m = (l+r)>>1;
    if(p<=m) add(p,c,lson);
    else add(p,c,rson);
    update(rt);
}
struct AN{
    string cit;
    bool operator<(const AN t)const
    {
        return cit<t.cit;
    }
    int val;
} ans[N];
int main()
{

    SI(n);
    int cnt = 0;
    REP(i,0,n)
    {
        SS(re1[i].ch[0]);//peop
        SS(re1[i].ch[1]);//city
        LL tm;
        cin>>tm;
        money[i] = re1[i].k = tm;
        peop[string(re1[i].ch[0])]=i;
        recity[cnt] = re1[i].ch[1];
        city[string(re1[i].ch[1])]=cnt++;
        memcpy(where[i],re1[i].ch[1],sizeof(re1[i].ch[1]));
    }
    SI(d);SI(m);
    REP(i,0,m)
    {
        cin>>re2[i].k;
        SS(re2[i].ch[0]);//name
        SS(re2[i].ch[1]);//city
        if(city.find(re2[i].ch[1])==city.end())
        {
            recity[cnt] = re2[i].ch[1];
            city[string(re2[i].ch[1])] = cnt++;
        }
    }
    build(1,0,cnt-1);
    REP(i,0,n){
        add(city[re1[i].ch[1]],money[i],1,0,cnt-1);
    }
    int dy = 0;
    REP(i,0,m)
    {
        int tmp = re2[i].k - dy;
        dy = re2[i].k;
        if(tree[1].two==0)
        {
            sum[tree[1].p] += tmp;
        }
        int who = peop[string(re2[i].ch[0])];
        add(city[string(where[who])],0-money[who],1,0,cnt-1);
        add(city[string(re2[i].ch[1])],money[who],1,0,cnt-1);
        strcpy(where[who],re2[i].ch[1]);
    }
    if(tree[1].two==0)
    {
        sum[tree[1].p] += d-dy;
    }
    int an = 0;
    REP(i,0,cnt)
    {
        if(sum[i]>0)
        {
            ans[an].cit = recity[i];
            ans[an].val = sum[i];
            an++;
        }
    }
    sort(ans,ans+an);
    REP(i,0,an)
    {
        cout<<ans[i].cit<<" "<<ans[i].val<<endl;
    }
    return 0;
}