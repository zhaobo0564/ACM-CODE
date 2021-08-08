#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], n, tree[30*N][2];

int top = 2;

void insert(int x) {
    int now = 1;
    for (int i = 30; i >= 0; i--) {
       int id = ((x >> i) & 1);
       if (!tree[now][id]) {
           tree[now][id] = top++;
       }
       now = tree[now][id];
    }
}

int sz[N], ans = 0;
int work(int u, int dep) {

    if (dep == 0) {
        return 1;
    }
   
   int ans = 0;
   if (tree[u][0] && tree[u][1]) {
       ans = max(ans, work(tree[u][0], dep - 1) + 1);
       ans = max(ans, work(tree[u][1], dep - 1) + 1);
   } else if (tree[u][0]) {
       ans = max(ans, work(tree[u][0], dep - 1));
   } else if (tree[u][1]) {
       ans = max(ans, work(tree[u][1], dep - 1));
   }
   return ans;
    
}



int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int ans = work(1, 31);
    cout << n - ans << endl;

}