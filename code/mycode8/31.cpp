#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int a[N], n, vis[N], cat[N];

struct node {
    int v, pos;

    bool operator < (const node x) const {
        return v > x.v;
    }
};

priority_queue<node>q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    long long  ans = 0, count = 0;


    for (int i = 1; i <= n; i++) {
        if (q.size() == 0) {
            q.push({a[i], i});
        } else {
            node cd = q.top();
            if (cd.v < a[i]) {
                ans += 1ll* (a[i] - cd.v); 
                if (vis[cd.pos] == 0) {
                    count++;
                    vis[cd.pos]++;
                } else {
                    q.push({a[cat[cd.pos]], cat[cd.pos]});
                }
                q.push({a[i], cd.pos});
                cat[cd.pos] = i;
                q.pop();


            } else {
                q.push({a[i], i});
            }
        }
    }

    printf("%lld %lld\n", ans, 2 * count);
    
}
