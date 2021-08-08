

 #include <algorithm>
 #include <iostream>
 #include <cstring>
 #include <climits>
 #include <cstdio>
 #include <vector>
 #include <cstdlib>
 #include <ctime>
 #include <cmath>
 #include <queue>
 #include <stack>
 #include <map>
 #include <set>
 #define fi first
 #define lc (x<<1)
 #define se second
 #define U unsigned
 #define rc (x<<1|1)
 #define Re register
 #define LL long long
 #define MP std::make_pair
 #define CLR(i,a) memset(i,a,sizeof(i))
 #define FOR(i,a,b) for(Re int i = a;i <= b;++i)
 #define ROF(i,a,b) for(Re int i = a;i >= b;--i)
 #define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
 #define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
 #define DEBUG(x) std::cerr << #x << '=' << x << std::endl
 const int MAXN = 1000000+5;
 int N,maxL;
 std::set<std::pair<int,int> > L;

int tree[1500007], flag[1500007];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(int v, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        tree[node] += v;
        if(tree[node]) flag[node] = r - l + 1;
        else flag[node] = flag[lson] + flag[rson];
        return;
    }
    if(ql <= m) update(v, ql, qr, l, m, lson);
    if(qr > m) update(v, ql, qr, m + 1, r, rson);
    //flag[node] = std::max(flag[node], flag[lson] + flag[rson]);
    if(!tree[node])flag[node] = flag[lson] + flag[rson];

}

 inline int calc(){
     return flag[1];
     // 返回 set 中所有线段的并长度。(每个 pair 表示一个线段[first,second]
 }
 int main(){
     scanf("%d%d",&N,&maxL);
     while(N--){
         int opt,x,y;
         scanf("%d%d%d",&opt,&x,&y);
         if(opt == 1){
             if(L.find(MP(x,y)) != L.end()) continue;
             L.insert(MP(x,y));
             if(x > y) continue;
             update(1, x, y, 1, maxL, 1);
         }
         if(opt == 2){
             if(L.find(MP(x,y)) == L.end()) continue;
             if(x > y)continue;

             update(-1, x, y, 1, maxL, 1);
             L.erase(MP(x,y));
         }
         if(opt == 3){
             printf("%d\n",calc());
         }
     }
     return 0;
 }