#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], b[N], n, m;

int vis[N];

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; i++) {
       scanf("%d", &a[i]);
       vis[a[i]]++;
   }
   for (int i = 1; i <= m; i++) {
       scanf("%d", &b[i]);
       vis[b[i]]++;
   }
   for (int i = 1; i < N; i++) {
       if (vis[i] == 1) {
           cout << i << " ";
       } 
   }
   cout << endl;

}