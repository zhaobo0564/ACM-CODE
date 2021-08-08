#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

int l[N], r[N];
int n, p;
bool judge(int x) {
    int p = upper_bound(l + 1, l + n + 1, x) - l;
    if (p > n) return true;
    return false;
}

struct node {
    int l, r;
};

vector<node>v;

unordered_map<int, int> vis;
int vis1[N * 110];
vector<int>g[N];

int cn[N][110];

int main() {
    int ca = 1;
    int t; scanf("%d", &t);
    while (t--) {
        v.clear();
        v.push_back({0, 0});
        vis.clear();
        scanf("%d %d", &n, &p);
        int o = 1;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            for (int j = 0; j <= 100; j++) {
                cn[i][j] = 0;
                vis1[o++] = 0;
            }
        }
    
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &r[i], &l[i]);
            if (l[i] > 100 * n) {
                 if (vis[l[i]] == 0) {
                    v.push_back({l[i], r[i]});
                    if (r[i] - l[i] <= 100)
                        g[i].push_back(r[i]);
                    vis[l[i]] = i;
                } else {
                    v.push_back({l[i], r[i]});
                    if (r[i] - l[i] <= 100)
                        g[vis[l[i]]].push_back(r[i]);
                }
            } else {
                if (vis1[l[i]] == 0) {
                    v.push_back({l[i], r[i]});
                    if (r[i] - l[i] <= 100)
                        g[i].push_back(r[i]);
                    vis1[l[i]] = i;
                } else {
                    v.push_back({l[i], r[i]});
                    if (r[i] - l[i] <= 100)
                        g[vis1[l[i]]].push_back(r[i]);
                }
            }
           
        }
        for (int i = 1; i <= n; i++) {
            sort(g[i].begin(), g[i].end());
        }

        for (int i = 1; i <= n; i++) {
            int ct = 0;
            for (int j = 0; j < g[i].size(); j++) {
                ct++;
                cn[i][g[i][j] - l[i]] = ct;
            }
            for (int j = 1; j <= 100; j++) {
                cn[i][j] = max(cn[i][j], cn[i][j - 1]);
            }
        }

        int ans = 0;
        sort(l + 1, l + n + 1);
        sort(r + 1, r + n + 1);
       
        for (int i = 1; i <= n; i++) {
            ll L = v[i].r * p;
            if (L % 100 == 0) {
                L = L / 100;
            } else {
                L = L / 100;
                L++;
            }
            ll R = v[i].r;
            if (judge(R)) {
                int cnt = lower_bound(r + 1, r + n + 1, L) - r;
                cnt--;

                int cnt1 = upper_bound(r + 1, r + n + 1, R) - r;
                cnt1--;
    
                cnt1 = cnt1 - cnt;

                int cnt2 = lower_bound(l + 1, l + n + 1, L) - l;
                cnt2--;
                int cnt4 = upper_bound(l + 1, l + n + 1, R) - l;
                cnt4--;
                cnt2 = cnt4 - cnt2;
                int cnt3 = 0;
                for (int j = L; j <= R; j++) {
                    int pos;
                    if (j > n * 100) {
                        pos = vis[j];
                    } else {
                        pos = vis1[j];
                    }
                    
                    if (pos) {
                        cnt3 += cn[pos][R - j];
                    }
                }

                ans = max(ans, cnt1 + cnt2 - cnt3);

               
            }
            L = v[i].l * p;
            if (L % 100 == 0) {
                L = L / 100;
            } else {
                L = L / 100;
                L++;
            }
            R = v[i].l;
        
            if (judge(R)) {
                int cnt = lower_bound(r + 1, r + n + 1, L) - r;
                cnt--;
      

                int cnt1 = upper_bound(r + 1, r + n + 1, R) - r;
                cnt1--;
    
                cnt1 = cnt1 - cnt;

                int cnt2 = lower_bound(l + 1, l + n + 1, L) - l;
                cnt2--;
                int cnt4 = upper_bound(l + 1, l + n + 1, R) - l;
                cnt4--;
        
                cnt2 = cnt4 - cnt2;
                int cnt3 = 0;
                for (int j = L; j <= R; j++) {
                    int pos;
                    if (j > n * 100) {
                        pos = vis[j];
                    } else {
                        pos = vis1[j];
                    }
                    if (pos) {
                        cnt3 += cn[pos][R - j];
                    }
                }
            
                ans = max(ans, cnt1 + cnt2 - cnt3);

             
            }
        }
        printf("Case #%d: %d\n",ca++, ans);

    }
}