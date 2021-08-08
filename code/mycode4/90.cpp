#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

struct hjt{
    int sum, l, r;
}tree[30 * N];

#define m (l + r)/2

ll n, h[N], q;
int rt[N], top = 1;

vector<ll>g;

int get_id(ll x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

void update(int pos, int last, int &now, int l, int r){ now = top++; tree[now] = tree[last];tree[now].sum++; if(l == r)return;if(pos <= m) update(pos, tree[last].l, tree[now].l, l, m);else update(pos, tree[last].r, tree[now].r, m + 1, r);
}

int query(int pos, int last, int now, int l, int r, int ans){ if(l == r)return ans;int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;if(pos <= m) return query(pos, tree[last].l, tree[now].l, l, m, ans);
    return query(pos, tree[last].r, tree[now].r, m + 1, r, ans + sum);
}

int main(){int t; scanf("%d", &t);int cas = 1;
    while(t--){ top = 1; g.clear();
        int n, q; scanf("%d %d", &n, &q); for(int i = 1; i <= n; i++){scanf("%lld", &h[i]);  g.push_back(h[i]);    }  g.push_back(1000000001);sort(g.begin(), g.end());  g.erase(unique(g.begin(), g.end()), g.end()); for(int i = 1; i <= n; i++){
            int pos = get_id(h[i]);
        
            update(pos, rt[i - 1], rt[i], 1, g.size());
        }
        //cout << endl;
        n = g.size();printf("Case %d:\n", cas++);while(q--){ int l, r;
            ll k;scanf("%d %d %lld", &l, &r, &k); l++, r++;
            int pos = get_id(k);
           // pos++;
           if(g[pos - 1] == k){
               pos++;
           }
  
            printf("%d\n", query(pos, rt[l - 1], rt[r], 1, n, 0));

        }

    }
}