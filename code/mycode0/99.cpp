#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 7;

int n;

struct power{
    int v, s;
}p[N];

struct node{
    
    ll v;
    bool operator<(const node a)const{
        return v > a.v;
    }
};

bool cmp(power x, power y){
    return x.s > y.s;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &p[i].v, &p[i].s);
    }

    sort(p + 1, p + n + 1, cmp);
    ll ans = 0;
    priority_queue<node>q;

    ll maxn = 0;
    for(int i = 1; i <= n; i++){
        ans += p[i].v;
        q.push({p[i].v});
        while(q.size() > p[i].s){
            ans -= q.top().v;
            q.pop();
        }
        maxn = max(ans, maxn);
    }
    printf("%lld\n", maxn);
}