#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int maxx = 3e5 + 7;
#define int long long
int tree[maxx<<2];
inline int L(int root){return root<<1;};
inline int R(int root){return root<<1|1;};
inline int MID(int l,int r){return (l+r)>>1;};
int a[maxx];
void update(int root,int l,int r,int pos){
   if (l==r){
     tree[root]++;
     return;
   }
   int mid=MID(l,r);
   if (pos<=mid){
      update(L(root),l,mid,pos);
   }else {
      update(R(root),mid+1,r,pos);
   }
   tree[root]=tree[L(root)]+tree[R(root)];
}
int query(int root,int l,int r,int ql,int qr){
     if (ql<=l && r<=qr){
        return tree[root];
     }
     int mid=MID(l,r);
     if (qr<=mid){
        return query(L(root),l,mid,ql,qr);
     }else if (ql>mid){
        return query(R(root),mid+1,r,ql,qr);
     }else {
        return query(L(root),l,mid,ql,qr)+query(R(root),mid+1,r,ql,qr);
     }
}
int32_t main(){
  int n;
  cin >> n;
    int ans=0;
    memset(tree,0,sizeof(tree));
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]++;
        ans+=query(1,1,n,a[i],n);
        update(1,1,n,a[i]);
    }
    int minn=ans;
    printf("%lld\n", ans);
    for (int i=1;i<n;i++){
        ans=ans+(n-a[i]+1)-a[i];
        printf("%lld\n", ans);
    }

}