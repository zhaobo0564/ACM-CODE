#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int n, m, a[N], vis[N], cnt[N];

int main(){
   
    scanf("%d %d", &n, &m); 
    int k = n / m;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        cnt[i] = a[i] % m;
        vis[a[i] % m]++;
    }
    set<int>g;
    for(int i = 0; i< m; i++){
        if(vis[i] < k){
            g.insert(i);
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[cnt[i]] > k){
            
            auto it = g.upper_bound(cnt[i]);
            if(it == g.end()){
                it = g.begin();
                ans += (m +*it) - cnt[i];
                a[i] += (m + *it) - cnt[i];
                vis[cnt[i]]--;
                vis[*it]++;
                if(vis[*it] == k){
                    g.erase(it);
                }
                continue;

            }
            ans += *it - cnt[i];
            a[i] += *it - cnt[i];
            vis[cnt[i]]--;
            vis[*it]++;
            if(vis[*it] == k){
                g.erase(it);
            }

        }
    }
    printf("%lld\n", ans);
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    puts("");

    






}