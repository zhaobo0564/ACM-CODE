#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int n, a[N], vis[N], dp[N][3], fn[N], cnt[N];
int  r[N], pos[N], l[N];
vector<int>g;


int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        g.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            g.push_back(a[i]);
        
        }
        for(int i = 0; i <= n; i++){
           dp[i][2] = dp[i][1] = dp[i][0] = 0;
            l[i] = 0;
            r[i] = 0;
            vis[i] = 0;
            cnt[i] = 0;
            pos[i] = 0;


        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        for(int i = 1; i <= n; i++){
            int x = get_id(a[i]);
            vis[x]++;
            cnt[i] = x;
            if(l[x] == 0){
                l[x] = i;
            }
            r[x] = i;
        }
        for(int i = 1; i <= n; i++){
            a[i] = cnt[i];
        }
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[pos[a[i]]][0] + 1;
            dp[i][1] = max(dp[pos[a[i]]][1] + 1, max(dp[pos[a[i] - 1]][0] + 1, dp[pos[a[i] - 1]][2] + 1));
            if(i == r[a[i]]){
                dp[i][2] = dp[l[a[i]]][1] + vis[a[i]] - 1;
            }
            pos[a[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i <= n; i++){
            ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
        }
        printf("%d\n", n - ans);

    

        
    }
}