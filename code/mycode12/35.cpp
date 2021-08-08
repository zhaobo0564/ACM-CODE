#include <bits/stdc++.h>
using namespace std;

const int N = 500003, mod = 1004535809;
typedef long long ll;
ll dp[N][2];
struct Edge {
  int v, nxt;
} G[N]; int head[N], a[N], M;
void adde(int u, int v) {
  G[++head[0]] = (Edge) {v, head[u]}; head[u] = head[0];
}
void dfs(int u) {
  dp[u][0] = 1;
  ll dpu0, dpu1;
  for (int i = head[u]; i; i = G[i].nxt) {
    int v = G[i].v;
    dfs(v);
    a[u] ^= a[v];
    dpu0 = dp[u][0], dpu1 = dp[u][1];
    dp[u][0] = (dpu0 * dp[v][0] + dpu1 * dp[v][1]) % mod;
    dp[u][1] = (dpu0 * dp[v][1] + dpu1 * dp[v][0]) % mod;
  }
  dpu0 = dp[u][0], dpu1 = dp[u][1];
  if (u == 1) cout << (dpu0 * (a[u] == M) + dpu1 * (a[u] == 0)) % mod;
  //ºÍ¸¸Ç×µÄ±ß
  if (a[u] == 0) (dp[u][0] += dpu1) %= mod;
  if (a[u] == M) (dp[u][1] += dpu0) %= mod;
}
int main() {
  int n;
  scanf("%d%d", &n, &M);
  for (int u, i = 2; i <= n; i++) scanf("%d", &u), adde(u, i);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  dfs(1);
  return 0;
}