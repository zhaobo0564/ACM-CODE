#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<double, bool> > q;

int n, m, t, k;
double ans;

void solve() {
    priority_queue<pair<double, bool> > p;
    while(p.size()) p.pop();
    while (q.size()) {
        auto cd = q.top();
        q.pop();
        if (cd.second) cd.first = cd.first * 0.8;
        p.push(cd);
    }
    swap(p, q);
    // while (q.size()) q.pop();
    // while (p.size()) q.push(p.top()), p.pop();
}

int main() {
    cin >> n >> m >> t >> k;
    k = t - k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        q.push({x, 0});
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        q.push({w, 1});
    }
    int ok = 1;
    
    while(t--) {
        fuck:
        auto cd = q.top();
        q.pop();
        int f = 0;
        if (cd.second ) {
            if (k <= 0 && ok) {
                q.push(cd);
                solve();
                ok = 0;
                //f = 1;
                goto fuck;
               // continue;
            }
         //  if (f == 1) continue;
           if (k >= 0) k -= 1;
        }
        
        
        ans += (double)cd.first;
        cd.first = (double)cd.first * 0.6;
        q.push(cd);
    }
    printf("%.2lf\n", ans);
    return 0;
}
