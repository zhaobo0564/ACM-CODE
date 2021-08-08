#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

vector<int> g[N];
int n;

int ans = 0;


int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        ans += max(0, (int)g[i].size() - 2);
    }
    printf("%d\n", ans);
}