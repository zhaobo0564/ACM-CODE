#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int n, k;
string s;
string t;
typedef long long ll;

ll dp[N][N][N];

ll dfs(int p, int k, int sum) {
    if (p == n) return 0;
    if (dp[p][k][sum] != -1) return dp[p][k][sum];
    ll ans = 0;

    if (k) {
        if (s[p] == t[0]) {
            ans = max(ans, dfs(p + 1, k - 1, sum) + sum);
            ans = max(ans, dfs(p + 1, k, sum + 1));
        } else if (s[p] == t[1]) {
            ans = max(ans, dfs(p + 1, k - 1, sum + 1));
            ans = max(ans, dfs(p + 1, k, sum) + sum);
        } else {
            ans = max(ans, dfs(p + 1, k - 1, sum + 1));
            ans = max(ans, dfs(p + 1, k - 1, sum) + sum);
            ans = max(ans, dfs(p + 1, k, sum));
        }
    } else {
        if (s[p] == t[0]) {
            ans = max(ans, dfs(p + 1, k, sum + 1));
        } else if (s[p] == t[1]) {
            ans = max(ans, dfs(p + 1, k, sum) + sum);
        } else {
            ans = max(ans, dfs(p + 1, k, sum));
        }
    }
    return dp[p][k][sum] = ans;
}

ll dfs1(int p, int k, int sum) {
    if (p == n) return 0;
    if (dp[p][k][sum] != -1) return dp[p][k][sum];
    ll ans = 0;
    if (k) {
        if (s[p] == t[0]) {
            ans = max(ans, dfs1(p + 1, k, sum + 1) + sum);
        } else {
            ans = max(ans, dfs1(p + 1, k - 1, sum + 1) + sum);
            ans = max(ans, dfs1(p + 1, k, sum));
        }
    } else {
        if (s[p] == t[0]) {
            ans = max(ans, dfs1(p + 1, k, sum + 1) + sum);
        } else {
            ans = max(ans, dfs1(p + 1, k, sum));
        }
    }
    return   dp[p][k][sum] = ans;
}

vector <int> nums1, nums2;
int vis[10000];

int main() {
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        nums1.push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        nums2.push_back(x);
    }
    for (int i: nums2) {
            vis[i]++;
        }
        long long ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            long long cnt = (long long)nums1[i] * (long long)nums1[i];
            for (int j = 0; j < nums2.size(); j++) {
                if (cnt % nums2[j] == 0) {
                    long long cat = cnt / nums2[j];
                    if (cat > 1e5) continue;
                    vis[nums2[j]]--;
                    
                    if (nums2[j] == cat) {
                        ans += vis[cat];
                        cout << vis[cat] << endl;
                    } else {
                        ans += vis[cat];
                        cout << vis[cat];
                    }
                } else {
                    vis[nums2[j]]--;
                }
            }
            for (int j: nums2) {
                vis[j]++;
            }
        }
        cout << ans << endl;
}   