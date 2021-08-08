#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct node {
    int l, r;
}p[N];
int maxn[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].l, &p[i].r);
    }
    sort(p + 1, p + n + 1, [](node x, node y) {
        return x.l < y.l;
    });

    for (int i = n; i; i--) {
        maxn[i] = max(maxn[i + 1], p[i].r);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (maxn[i + 1] > p[i].r) {
            ans++;
        }
    }
    printf("%d\n", ans);

}