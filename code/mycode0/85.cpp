#include"cstdio"
#include"queue"
#include"cmath"
#include"stack"
#include"iostream"
#include"algorithm"
#include"cstring"
#include"queue"
#include"map"
#include"vector"
#define ll long long
#define mems(a,b) memset(a,b,sizeof(a))
#define ls pos<<1
#define rs pos<<1|1

using namespace std;
const int MAXN = 1e5+50;
const int MAXE = 200500;
const int INF = 0x3f3f3f;

struct Node{
    int l,r;
    int num[2];
    int lazy[3];///0为置零1为置一2为翻转
    int lc[2][2];///最大left/right连续长度
    int mc[2];    ///最大长度
}node[MAXN<<2];
int x[MAXN];

void pushup(int pos){
    for(int i=0;i<2;i++) node[pos].num[i]=node[ls].num[i]+node[rs].num[i];
    int l=node[pos].l,r=node[pos].r,mid=(l+r)>>1;

    for(int i=0;i<2;i++){
        if(node[ls].num[i]==mid-l+1) node[pos].lc[0][i]=node[ls].num[i]+node[rs].lc[0][i];  ///只有在左区间全为0或1时才能这样更新
        else node[pos].lc[0][i]=node[ls].lc[0][i];
    }
    for(int i=0;i<2;i++){
        if(node[rs].num[i]==r-mid) node[pos].lc[1][i]=node[rs].num[i]+node[ls].lc[1][i];    ///同上
        else node[pos].lc[1][i]=node[rs].lc[1][i];
    }

    for(int i=0;i<2;i++) node[pos].mc[i]=max(node[ls].mc[i],node[rs].mc[i]);
    for(int i=0;i<2;i++) node[pos].mc[i]=max(node[pos].mc[i],node[ls].lc[1][i]+node[rs].lc[0][i]);///可以是左右区间的最大个数，也可能是连接后的个数
}

void pushdown(int pos){
    for(int i=0;i<2;i++)
        if(node[pos].lazy[i]){
            node[ls].lazy[i]=node[rs].lazy[i]=node[pos].lazy[i];
            node[ls].lazy[!i]=node[ls].lazy[2]=0;
            node[ls].mc[i]=node[ls].num[i]=node[ls].r-node[ls].l+1;
            node[ls].mc[!i]=node[ls].num[!i]=0;

            node[rs].lazy[!i]=node[rs].lazy[2]=0;
            node[rs].mc[i]=node[rs].num[i]=node[rs].r-node[rs].l+1;
            node[rs].mc[!i]=node[rs].num[!i]=0;
            for(int j=0;j<2;j++){
                node[ls].lc[j][i]=node[ls].r-node[ls].l+1;
                node[ls].lc[j][!i]=0;
                node[rs].lc[j][i]=node[rs].r-node[rs].l+1;
                node[rs].lc[j][!i]=0;
            }
        for(int i=0;i<3;i++) node[pos].lazy[i]=0;   ///如果已经置数，那么翻转标记就无用了
        }
    if(node[pos].lazy[2]){
        node[ls].lazy[2]^=1;
        node[rs].lazy[2]^=1;    ///写成直接=node[pos].lazy[2]WA了半天 - -||

        swap(node[ls].mc[0],node[ls].mc[1]);
        swap(node[ls].num[0],node[ls].num[1]);
        swap(node[ls].lazy[0],node[ls].lazy[1]);

        swap(node[rs].mc[0],node[rs].mc[1]);
        swap(node[rs].num[0],node[rs].num[1]);
        swap(node[rs].lazy[0],node[rs].lazy[1]);
        for(int i=0;i<2;i++){
            swap(node[ls].lc[i][0],node[ls].lc[i][1]);
            swap(node[rs].lc[i][0],node[rs].lc[i][1]);
        }
        node[pos].lazy[2]=0;
    }
}

void build(int l,int r,int pos){
    node[pos].l=l;
    node[pos].r=r;
    for(int i=0;i<3;i++) node[pos].lazy[i]=0;
    if(l==r){
        node[pos].num[x[l]]=1;
        node[pos].num[!x[l]]=0;
        node[pos].mc[x[l]]=1;
        node[pos].mc[!x[l]]=0;
        for(int i=0;i<2;i++){
            node[pos].lc[i][x[l]]=1;
            node[pos].lc[i][!x[l]]=0;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushup(pos);
}

void update(int l,int r,int pos,int kind){
    if(l<=node[pos].l&&node[pos].r<=r){
        if(kind==2){
            node[pos].lazy[kind]^=1;
            swap(node[pos].mc[0],node[pos].mc[1]);
            swap(node[pos].num[0],node[pos].num[1]);
            swap(node[pos].lazy[0],node[pos].lazy[1]);
            for(int i=0;i<2;i++) swap(node[pos].lc[i][0],node[pos].lc[i][1]);
        }
        else if(!node[pos].lazy[kind]){
            node[pos].lazy[kind]=1;
            node[pos].lazy[!kind]=0;
            node[pos].lazy[2]=0;
            node[pos].mc[kind]=node[pos].num[kind]=node[pos].r-node[pos].l+1;
            node[pos].mc[!kind]=node[pos].num[!kind]=0;
            for(int j=0;j<2;j++){
                node[pos].lc[j][kind]=node[pos].r-node[pos].l+1;
                node[pos].lc[j][!kind]=0;
            }
        }
        return;
    }
    pushdown(pos);
    int mid=(node[pos].l+node[pos].r)>>1;
    if(l<=mid) update(l,r,ls,kind);
    if(r>mid) update(l,r,rs,kind);
    pushup(pos);
}

int queryone(int l,int r,int pos){
    int ans=0;
    if(l<=node[pos].l&&node[pos].r<=r){
        return node[pos].num[1];
    }
    pushdown(pos);
    int mid=(node[pos].l+node[pos].r)>>1;
    if(l<=mid) ans+=queryone(l,r,ls);
    if(r>mid) ans+=queryone(l,r,rs);
    return ans;
}

int query_maxlen(int l,int r,int pos){
    if(l==node[pos].l&&node[pos].r==r){
        return node[pos].mc[1];
    }
    pushdown(pos);
    int mid=(node[pos].l+node[pos].r)>>1;
    if(r<=mid) return query_maxlen(l,r,ls);
    else if(l>mid) return query_maxlen(l,r,rs);
    else {
        int ans=max(query_maxlen(l,mid,ls),query_maxlen(mid+1,r,rs));
        int a=min(node[ls].lc[1][1],mid-l+1);
        int b=min(node[rs].lc[0][1],r-mid);
        ans=max(ans,a+b);
        return ans;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("pending.txt","w",stdout);
    int n,m,T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&x[i]);
        build(0,n-1,1);
        int a,b,op;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&op,&a,&b);
            if(op==0||op==1||op==2) update(a,b,1,op);
            else if(op==3) printf("%d\n",queryone(a,b,1));
            else if(op==4) printf("%d\n",query_maxlen(a,b,1));
        }
        printf("***********\n");
    }
    return 0;
}