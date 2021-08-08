#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;
int n, m;
ll c[N];

struct node{
    ll v;
    int pos;
}p[N];

bool cmp(node x, node y){
    return x.v > y.v;
}

int main(){
    scanf("%d %d",&n, &m);
    for(int i = 1; i <= m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        c[l]++;
        c[r + 1]--;
    }
    for(int i = 1; i <= n; i++){
        c[i] += c[i - 1];
    }
    int top = 1;
    for(int i = 1; i <= n; i++){
        if(c[i]){
            p[top].pos = i;
            p[top].v = c[i];
            top++;
        }
    }
    sort(p + 1, p + top, cmp);
    ll ans = 0;
    for(int i = 1; i < top; i++){
        ans += 1ll* n * p[i].v;
        n--;
    }
    printf("%lld\n", ans);

}