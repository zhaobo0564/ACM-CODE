#include<bits/stdc++.h>
using namespace std;

const int N = 50;

int a[N], n;

int vis[N];

int dfs(int p, int one,  int ok) {
   if (p > n) {
       if (ok == n / 2) return 1;
       return 0;
   }
   int ans = 0;

   for (int i = one + 1; i <= n; i++) {
       if (a[p] == a[i]) {
           ans = max(ans, dfs(p + 1, i, ok + 1));
       }
   }
  
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            //scanf("%d", &a[i]);
            a[i] = i;
        }
        if (dfs(1, 0)) {
            puts("Frederica Bernkastel");
        } else {
            puts("Furude Rika");
        }
    }
}