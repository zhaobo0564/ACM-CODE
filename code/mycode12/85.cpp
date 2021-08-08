#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int fa[N], n, k;

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < N; i++) {
        fa[i] = i;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (x > n || y > n) {
            ans++;
            continue;
        }
        int x_a = x + n, y_a = y + n;
        int x_s = x_a + n, y_s = y_a + n;
        int x_f = x_s + n, y_f = y_s + n;
        x_a = find(x_a);
        x_s = find(x_s);
        x_f = find(x_f);
        y_a = find(y_a);
        y_s = find(y_s);
        y_f = find(y_f);
        if (op == 1) {
            if (x_a == y_s) {
                ans++;
            } else if (y_a == x_s) {
                ans++;
            } else {
               fa[x_s] = y_s; 
               fa[x_f] = y_f;
               fa[x_a] = y_a;
            }
            
        } else {
            if (x == y) {
                ans++;
            } else if (x_s == y_s) {
                ans++;
            } else if (y_f == x_s) {
                ans++;
            } else {
                fa[x_f] = y_s;
                fa[y_a] = x_s;
                fa[x_a] = y_f;
            }
            
        }
    } 
    cout << ans << endl;
}