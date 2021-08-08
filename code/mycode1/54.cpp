#include<bits/stdc++.h>
using namespace std;
const int N = 2507;

struct node{
    int l, r;
}p[N];

int vis[N], c, l, v[N];

// bool cmp(node x, node y){
//     if(x.l == y.l)
//         return x.r < y.l;
//     return x.l > y.l;
// }

int main(){
    scanf("%d %d", &c, &l);
    for(int i = 1; i <= c; i++){
        scanf("%d %d", &p[i].l, &p[i].r);
    }
    int ans = 0;

    for(int i = 1; i <= l; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vis[x] = y;
    }
  //  sort(p + 1, p + c + 1, cmp);
    for(int i = 1; i <= 1000; i++){
        if(vis[i]){
            int pos = 0;
            int maxn = 100000;
            int maxn1 = 100000;
            for(int j = 1; j <= c; j++){
               if(v[j] == 0 && p[j].l <= i && p[j].r >= i){
                   int cn = p[i].r - i;
                   if()
               }
            }
           
        }
    }
    printf("%d\n",ans);
}