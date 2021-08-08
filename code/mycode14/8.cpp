#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
vector<int>g[N];

int dfn[N], flow[N], cnt, vis[N];
stack<int>q;
int n, m, k;
//int cat[N], top = 1;
ll ans = 0;


void tarjan(int u){
    dfn[u] = flow[u] = ++cnt;
    vis[u] = 1;
    q.push(u);
    for(int to: g[u]){
        if(!dfn[to]){
            tarjan(to);
            flow[u] = min(flow[u], flow[to]);
        }else if(vis[to]){
            flow[u] = min(flow[u], dfn[to]);
        }
    }


    if(flow[u] == dfn[u]){
        ll ct = 0;
        while(1){

            int now = q.top();
            q.pop();
            ct++;
            vis[now] = 0;  // now为强连通
     
           // cat[now] = top;
            if(now == u)break;
        }
        //cout << endl;
       // cout << "ct" << ct << endl;
      //  ans -= cnt;
        ans -= ct;
        ans += ct * ct;
       // top++;
    }
}

int u[N], v[N];

vector<int> cn;

bool judge(int l, int r) {
    cn.clear();
    cnt = 0;
    ans = n;
    for (int i = l; i <= r; i++) {
      //  cout << "u " << u[i] << " v " << v[i]<< endl;
        g[u[i]].push_back(v[i]);
        cn.push_back(u[i]);
        cn.push_back(v[i]);
        
    }

    for (int i: cn) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    for (int i: cn) {
        g[i].clear();
        dfn[i] = 0;
        flow[i] = 0;
    }
   // cout << "l = " << l << " r = " << r << " ans " << ans << endl;
    if (k >= ans) return true;
    return false;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }
    int res = 0;
    int L = 1, k;
    while (L <= m) {
        k = 0;
        int R = L;
        while (judge(L, R)) {
            R = R + (1 << k);
            k++;
            if (R > m) break;
            
        }
        int l = max(1, R - (1 << (k - 1))), r = min(m, R), cat;
     //   cout << "l = " << l << " r " << r << endl;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (judge(L, mid)) {
                l = mid +1;
                cat = mid;
            } else {
                r = mid - 1;
            }
        }
        res++;
        L = cat + 1;
    }
    cout << res << endl;

}