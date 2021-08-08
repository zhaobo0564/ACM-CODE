#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int a[N], n, m, fa[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

priority_queue<int> q[N];

int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            fa[i] = i;
            while (q[i].size())q[i].pop();
            q[i].push(a[i]);
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            int fx = find(u), fy = find(v);
            if (fx == fy) {
                cout << -1 << endl;
            } else {
                int cnt = q[fx].top();
                q[fx].pop();
                q[fx].push(cnt / 2);
                int cn = q[fy].top();
                q[fy].pop();
                q[fy].push(cn / 2);

                if (q[fx].size() < q[fy].size()) {
                    while (q[fx].size()) {
                        q[fy].push(q[fx].top());
                        q[fx].pop();
                    }
                    fa[fx] = fy; 
                    cout << q[fy].top() << endl;
                } else {
                    while (q[fy].size()) {
                        q[fx].push(q[fy].top());
                        q[fy].pop();
                    }
                    fa[fy] = fx;
                    cout << q[fx].top() << endl;
                }
                
                
            }

        }
    }
}