#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int fa[N], d[N], sz[N];

int find(int x) {
    if (x != fa[x]) {
        int root = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = root;
        return root;
    }
    return x;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i < N; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    while (t--) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'M') {
            int fx = find(x), fy = find(y);
            if (fx != fy) {
                fa[fx] = fy;
                d[fx] += sz[fy];
                sz[fy] += sz[fx];
            } 
        } else {
            int fx = find(x), fy = find(y);
         //    cout << d[y]<< " " << d[x] << endl;
            if (fx != fy) {
                cout << -1 << endl;
            } else {
               
              cout << abs(d[y] - d[x]) - 1 << endl;  
            }
            
        }
    }
}