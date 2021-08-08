#include<bits/stdc++.h>
using namespace std;
const int N = 207;
int n, fa[N * 1000], m;

int fn(int x, int y) {
    return n * (x - 1) + y;
}

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < N * 1000; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'D') {
            int fx = find(fn(x, y));
            int fy = find(fn(x + 1, y));
            
            if (fx == fy) {
                cout << i << endl;
                return 0;
            } else {
                fa[fx] = fy;
            }
        } else {
            int fx = find(fn(x, y));
            int fy = find(fn(x, y + 1));
            if (fx == fy) {
                cout << i << endl;
                return 0;
            }
            fa[fx] = fy;
        }
    }
    cout << "draw\n";
    return 0;
    
}