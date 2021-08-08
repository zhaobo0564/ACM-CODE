#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], b[N], c[N], n;

long long vis[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        vis[b[c[i]]]++;
    }
   
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += vis[a[i]];
    }
    cout << ans << endl;
    return 0;
}