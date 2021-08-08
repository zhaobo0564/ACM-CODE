#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll n, a[N], sum[N], fn[N][2];

vector<int> g[N];

void dfs(int node) {
    if (2 * node <= n) {
        dfs(2 * node);
        fn[node][0] += fn[2 * node][1];
        fn[node][1] = max(fn[2 * node][0], fn[2 * node][1]);

    }
    if (2 * node + 1 <= n) {
        dfs(2 * node + 1);
        fn[node][0] += fn[2 * node + 1][1];
        fn[node][1] += max(fn[2 * node + 1][0], fn[2 * node + 1][1]);
    }
}

int main() {
  
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fn[i][0] = a[i];

    }
    dfs(1);
    cout << max(fn[1][0], fn[1][1]) << endl;

    return 0;
}