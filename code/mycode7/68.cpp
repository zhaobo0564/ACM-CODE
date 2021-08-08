#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
struct node {
    ll v, id;
}p[N];

bool cmp(node x, node y) {
    return x.v < y.v;
}

int vis[N], cnt[N];

int main() {
    int t, n, pp, o = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &pp);
        int top = 1;
        for (int  i = 1; i <= n; i++) {
            cnt[i] = vis[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            ll l, r;
            scanf("%lld %lld", &r, &l);
            l *= 100, r *= 100;
            p[top].v = r;
            p[top].id = i;
            p[++top].v = l;
            p[top].id = i;
            top++;
            
            
        }
        sort(p + 1, p + top, cmp);
        // for (int i = 1; i < top; i++) {
        //     cout << p[i].v << " " << p[i].id << endl;
        // }
        // cout << endl;

        int l = top - 1, r = top - 1;
        
        int ans = 0, cn = 0;
        while (1) {
            ll limt = (p[r].v / 100) * pp;
            
            //cout << "limt " << limt << endl;
            while (p[l].v >= limt) {
                cnt[p[l].id]++;
             //   cout << p[l].id << " ";
                
                if (cnt[p[l].id] == 1) {
                    cn++;
                }
                l--;
            }
            ans = max(ans, cn);
            vis[p[r].id]++;
            if (vis[p[r].id] == 2) {
                break;
            }
            cnt[p[r--].id]--;;
            cn--;
            
            


            
        }
        printf("Case #%d: ", o++);
        cout << ans << endl;
        
    }
}