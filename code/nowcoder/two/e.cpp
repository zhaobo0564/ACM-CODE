#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
typedef long long ll;

int a[N], n, vis[N], ans[N];
ll k;

vector<int> v;

int main() {
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(vis[a[i]] == 0) {
            v.clear();
            int now = a[i];
            while(vis[now] == 0) {
                vis[now] = 1;
                v.push_back(now);
                now = a[now];
            }
            int len = v.size();
            int niv;
    
            for(int i = 1; i < len; i++) {
                if((i % len * k % len) == 1) {
                    niv = i;
                    break;
                }
            }
            for(int i = 0; i < v.size(); i++) {
                ans[v[i]] = v[(i + k) % len];
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");




}