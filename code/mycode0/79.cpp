#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, tree[N], a[N];

int lowbit(int x){return x & (-x);}
long long ans[N], ans1[N];

void add(int x){
    while(x <= 10000 ){
        tree[x]++;
        x += lowbit(x);
    }
}

int query(int x){
    int ans = 0;
    while(x > 0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    int t;scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        memset(tree, 0, sizeof(tree));
        for(int i = 1; i <= n; i++){
            ans[i] = query(a[i]);
            add(a[i]);
        }
        memset(tree, 0, sizeof(tree));
        for(int i = n; i; i--){
            ans1[i] = query(a[i]);
            add(a[i]);
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
            res += (i - 1 -ans[i]) * ans1[i];
            res += (ans[i]) * (n - i - ans1[i]);
        }
        printf("%lld\n", res);

    }
}