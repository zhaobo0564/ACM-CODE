#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

struct node{
    int u, v, w;
}p[N];

int father[N], n, m, fn[N];

int find(int x){
    if(x != father[x]){
        return father[x] = find(father[x]);
    }
    return x;
}

bool cmp1(node a, node b){
    return a.w < b.w;
}

bool cmp2(node a, node b){
    return a.w > b.w;
}



int main(){
    fn[1] = 1, fn[2] = 2;
    int cnt = 3;
    while(1){
        fn[cnt] = fn[cnt - 1] + fn[cnt - 2];
        if(fn[cnt] > 1e7)break;
        cnt++;
    }
    int t; scanf("%d", &t);
    int ca = 0;
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++){
            scanf("%d %d %d", &p[i].u, &p[i].v, &p[i].w);
        }
        for(int i = 1; i <= n; i++){
            father[i] = i;
        }
        sort(p + 1, p + m + 1, cmp1);
        int ans = 0, f = 0;
        for(int i = 1; i <= m ;i++){
            int x = find(p[i].u);
            int y = find(p[i].v);
            if(x != y){
                ans += p[i].w;
                father[x] = y;
                f++;
            }
        }
        for(int i = 1; i <= n; i++){
            father[i] = i;
        }
        sort(p + 1, p + m + 1, cmp2);
        int ans1 = 0;
        for(int i = 1; i <= m ;i++){
            int x = find(p[i].u);
            int y = find(p[i].v);
            if(x != y){
                ans1 += p[i].w;
                father[x] = y;
            }
        }
        int p = lower_bound(fn + 1, fn + cnt, ans) - fn;
        int p1 = lower_bound(fn + 1, fn + cnt, ans1) - fn;
        printf("Case #%d: ", ++ca);
        if(f < n - 1){
            printf("No\n");
        }else if(ans == fn[p] || ans1 == fn[p1]){
            printf("Yes\n");
        }else if (p1 > p){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }       
        
        
    
}