#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1007;
int n,flag[10*N];
double x1, x2,y1,y2;
 vector<double>x;
struct line{
    double l,r,h;
    int c;
}lines[2*N];

struct node{
    double l,r;
    int c;
}tree[10*N];

bool cmp(line a,line b){
    return a.h<b.h;
}
#define m (l+r)/2

void build(int l,int r,int node){
    flag[node]=0;
    tree[node].l=x[l-1];
    tree[node].r=x[r-1];
    if(r-l==1)return;
    build(l,m,2*node);
    build(m,r,2*node+1);
}

void push_down(int node){
    if(flag[node]){
        tree[2*node].c+=flag[node];
        tree[2*node+1].c+=flag[node];
        flag[2*node]+=flag[node];flag[2*node+1]+=flag[node];
        flag[node]=0;
    }
}

void update(int v,double ql,double qr,int node){
    //cout<<"l="<<tree[node].l<<" r="<<tree[node].r<<endl;
    if(tree[node].l>=qr||tree[node].r<=ql)return;
    if(ql<=tree[node].l&&qr>=tree[node].r){
        tree[node].c+=v;
        flag[node]+=v;
       // cout<<"ll="<<tree[node].l<<" rr=="<<tree[node].r<<" "<<tree[node].c<<endl;
        return;
    }
    push_down(node);
    update(v,ql,qr,2*node);
    update(v,ql,qr,2*node+1);
}

double query(int node){
    //cout<<"L="<<tree[node].l<<" r="<<tree[node].r<<" "<<tree[node].c<<endl;   
     if(tree[node].l==0&&tree[node].r==0)return 0;
    if(tree[node].c)return abs(tree[node].r-tree[node].l);
    double ans=0.0;
    push_down(node);
    ans+=query(2*node);
    ans+=query(2*node+1);
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int top=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            lines[top].l=x1,lines[top].r=x2,lines[top].h=y1,lines[top++].c=1;
            lines[top].l=x1,lines[top].r=x2,lines[top].h=y2,lines[top++].c=-1;
            x.push_back(x1),x.push_back(x2);
        }
        sort(x.begin(),x.end());
        sort(lines+1,lines+top,cmp);
        x.erase(unique(x.begin(),x.end()),x.end());
        build(1,x.size(),1);
        double ans=0.0;
        for(int i=1;i<top-1;i++){
           // cout<<lines[i].c<<endl;
            update(lines[i].c,lines[i].l,lines[i].r,1);
            double w=query(1);
          //  cout<<"w="<<w<<endl;
            ans+=w*(lines[i+1].h-lines[i].h);
        }
        printf("%.4lf\n",ans);
        x.clear();
        memset(tree,0,sizeof(tree));
    }
}