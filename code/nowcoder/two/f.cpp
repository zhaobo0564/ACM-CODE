#include<bits/stdc++.h>
using namespace std;
const int N = 150007;
 
int a[N], b[N], n, m, pos[N];
 
bitset<40007> cnt[40007], ans;
 
int find(int x) {
    int l = 1, r = m;
    int an = 0;
 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[pos[mid]] <= x) {
            an = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return an;
}
 
 
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        pos[i] = i;
    }
 
    sort(pos + 1, pos + m + 1, [](int x, int y) {return b[x] < b[y];});
    for (int i = 1; i <= m; i++) {
        cnt[i] = cnt[i - 1];
        cnt[i].set(m - pos[i], 1);
    }
 
 
    int res = 0;
    for (int i = 0; i <= m; i++) ans.set(i, 0);
 
    for (int i = 1; i <= n; i++) {
        int p = find(a[i]);
        ans >>= 1;
        ans.set(m - 1, 1);
        ans &= cnt[p];
        res += ans[0];
    }
    printf("%d\n", res);
 
}