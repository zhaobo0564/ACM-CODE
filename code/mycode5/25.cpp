#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, a[500];
int vis[400];

int main (){
    int t;
    scanf("%d", &t);
    while (t--) {
        vector<int> ans;
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (vis[a[i]] == 0) {
                ans.push_back(a[i]);
                vis[a[i]] = 1;
            }
        }
        for (int i: ans) {
            printf("%d ", i);
        }
        puts("");
    }
    
}