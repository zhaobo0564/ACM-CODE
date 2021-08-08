#include<bits/stdc++.h>
using namespace std;
int t, n, m, x;
vector<pair<int, int> >g;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        g.clear();
        scanf("%d %d %d", &n, &x, &m);
        for(int i = 1; i <= m; i++){
            int l, r;
            scanf("%d %d", &l, &r);
            g.push_back({l, r});
        }
        int ans = 1;
        for(int i = 0; i < g.size(); i++){
            int l = g[i].first;
            int r = g[i].second;
            if(l <= x && r >= x);
            else continue;
            for(int j = i + 1; j < g.size(); j++){
                if(min(r, g[j].second) <= max(l, g[j].first)){
                   
                    l = min(l, g[j].first);
                    r = max(r, g[j].second);
                }
            }
            
            ans = max(ans, r - l + 1);
        }
        printf("%d\n", ans);

    }
   
}