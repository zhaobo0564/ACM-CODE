#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+7;
ll n,l;
struct node{
    char a[60];
    ll v;
}pre[N];
bool cmd(node x,node y){
    return x.v<y.v;
}
int main(){
    scanf("%lld %lld",&n,&l);
    for(int i=1;i<=n;i++){
        scanf("%s",(pre[i].a));
        scanf("%lld",&pre[i].v);
    }
    sort(pre+1,pre+1+n,cmd);
    for(int i=1;i<=n-1;i++){
        printf("%s ",pre[i].a);
        printf("%lld ",(pre[i].v*i)/l);
        if((pre[i].v*i)%l==0) printf("0\n");
        else printf("%lld\n",l-(pre[i].v*i)%l);
    }
    printf("%s\n",pre[n].a);
}
