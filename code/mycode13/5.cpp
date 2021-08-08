#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 7;

int n, m, a[N];

struct node {
    int l, r;
}p[N];

bool cmp(node x, node y) {
    if (x.r == y.r) {
        return x.l < y.l;
    }
    return x.r < y.r;
}



int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int f = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &p[i].l, &p[i].r);
    }
   
    sort(p + 1, p + m + 1, cmp);
    sort(a + 1, a + n + 1);
    int ans = 1, pos = 1;

    while (a[pos] <= p[1].r) {
        pos++;
    }
    pos--;
    if (a[pos] < p[1].l) {
        cout << -1 << endl;
        return 0;
    }
    a[n + 1] = 1000000;
    for (int i = 2; i <= m; i++) {
        if (a[pos] >= p[i].l && a[pos] <= p[i].r) {
            continue;
        } else {
            while (a[pos] <= p[i].r) {
                pos++;
            }
            pos--;
            if (a[pos] < p[i].l) {
                cout << -1 << endl;
                return 0;
            }
            ans++;
        }
    }
    cout << ans << endl;

    

    
    
    
    
}

