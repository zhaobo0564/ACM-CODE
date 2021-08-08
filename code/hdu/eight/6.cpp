#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct node {
    int l, r;
}p[N], ans[N];

int n, k;


int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &p[i].l, &p[i].r);
        }
        int l = p[n].l;
        int r = p[n].r;  
        ans[n].l = l;
        ans[n].r = r;
        l -= k;
        r += k;
        for (int i = n - 1; i; i--) {
            int ll = max(l, p[i].l);
            int rr = min(r, p[i].r);
            ans[i].l = ll;
            ans[i].r = rr;
            l = ll;
            r = rr;
            if (l > r) break;
            l -= k;
            r += k;
        }
        if (l > r) {
            puts("NO");
        } else {
            puts("YES");
            int cnt = ans[1].l;
            printf("%d ", cnt);
            for (int i = 2; i <= n; i++) {
                if (cnt >= ans[i].l && cnt <= ans[i].r) {
                     printf("%d ", cnt);
                } else if (cnt > ans[i].r ) {
                    cnt = ans[i].r;
                    printf("%d ", cnt);
                } else if (cnt < ans[i].l) {
                    cnt = ans[i].l;
                    printf("%d ", cnt);
                }
                
            }
            puts("");

        }
    }
}