#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    while (m--) {
        int l, r; scanf("%d %d", &l, &r);
        reverse(a + l , a + r + 1);
    
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}