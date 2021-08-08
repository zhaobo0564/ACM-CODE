#include<bits/stdc++.h>
using namespace std;
int p[1007], n, a[507];

int work(int l, int r) {
    int tot = 1;
    
    for (int i = l; i <= r; i++) {
        if (tot == 1) {
            a[tot++] = p[i];
        } else {
            int pos = lower_bound(a + 1, a + tot, p[i]) - a;
            if (pos < tot) {
                a[pos] = p[i];
            } else {
                a[tot++] = p[i];
            }
        }
    }
    return tot - 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        p[n + i] = p[i] ;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
       
        ans = max(ans, work(i, i + n - 1));
        
    }
    printf("%d\n", n - ans);
}