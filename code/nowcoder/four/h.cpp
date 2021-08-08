#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;

int t, n;
vector<pair<int, int> >ans;
vector<int> cnt;

int prime[N],vis[N],top=1;

void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;

        }
    }
}


int main () {
    scanf("%d", &t); 
    Prime();
    for (int i = 1; i < top; i++) {
        if (prime[i] > 1e6) {
            top = i;
            break;
        } 
    }
    while (t--) {
        ans.clear();
        cnt.clear();
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            vis[i] = 0;
        }

        for (int i = 2; i < top; i++) {
            vector<int> v;
            for (int j = prime[i]; j <= n; j += prime[i]) {
                if (vis[j] == 0)
                    v.push_back(j), vis[j] = 1;
            }
            vector<int> cat;
            if ((int)v.size() % 2) {
                int f = 0;
                for (int i = 0; i < v.size(); i++) {
                    if (f == 0 && v[i] % 2 ==0) {
                        cnt.push_back(v[i]);
                        f = 1;
                    } else {
                        cat.push_back(v[i]);
                    }
                }
            } else {
                cat = v;
            }
            for (int i = 0; i < cat.size() / 2; i++) {
                ans.push_back({cat[i], cat[cat.size() - i - 1]});
            }
        }
        for (int i = 2; i <= n; i += 2) {
            if (vis[i] == 0) {
                cnt.push_back(i);
            }
        }
        for (int i = 0; i < cnt.size() / 2; i++) {
            ans.push_back({cnt[i], cnt[cnt.size() - 1 - i]});
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
       
     
    }
}