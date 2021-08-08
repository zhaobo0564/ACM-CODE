    #include<bits/stdc++.h>
    using namespace std;
    const int N = 2e5 + 7;
    int fa[N];
     
    set<int> g[N];
     
    int n, m, ans = 0;
     
    int find(int x) {
        if (x != fa[x]) {
           return fa[x] = find(fa[x]);
        }
        return x;
    }
     
    void gao() {
        for (int i = 1; i <= m; i++) {
            int last = *g[i].begin();
            last--;
            int cnt = 1;
            for (int v: g[i]) {
                if (v == last + 1) {
                    
                } else {
                    cnt++;
                }
                last = v;
            }
            ans += cnt;
        }
        ans--;
    }
     
    void merg(int x, int y) {
        if (g[x].size() > g[y].size()) {
            swap(x, y);
        }
        fa[x] = fa[y];
        int cnt = 0;
        int last = *g[x].begin();
        last--;
        int be = last + 1;
        if (g[x].size() == 0) return;
        for (int i: g[x]) {
            if (i == last + 1) {
     
            } else {
             //   cout << "II  " << last << endl;
                auto it = g[y].upper_bound(last);
                auto it1 = g[y].lower_bound(be);
                if (it1 != g[y].begin()) {
                    it1--;
                }
     
                int r = *it1, l = -100;
     
                if (it != g[y].end()) {
                    l = *it; 
                }
               // cout << "l " << l << " r = " << r << endl;
                if (l - 1 == last && be == r + 1) {
                    cnt += 2;
                } else if (l - 1 == last) {
                    cnt++;
                } else if (be == r + 1) {
                    cnt++;
                }
                be = i;
            }
            last = i;
        }
       // cout << "cnt " << cnt << endl;
      //  cout << "last " << last << " be " << be << endl;
        auto it = g[y].upper_bound(last);
        auto it1 = g[y].lower_bound(be);
        if (it1 != g[y].begin()) {
            it1--;
        }
     
        int r = *it1, l = -100;
     
        if (it != g[y].end()) {
            l = *it; 
        }
        //cout << "l = " << l << " r " << r << endl;
        if (l - 1 == last && be == r + 1) {
            cnt += 2;
        } else if (l - 1 == last) {
            cnt++;
        } else if (be == r + 1) {
            cnt++;
        }
        for (int i: g[x]) {
            g[y].insert(i);
        }
     
     
     
        ans -= cnt;
    }
     
    int main() {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= m; i++) {
            fa[i] = i;
        }
        
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            g[x].insert(i);
        }
        gao();
        printf("%d\n", ans);
        for (int i = 1; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            int fx = find(x);
            int fy = find(y);
            if (fx != fy) {
                merg(fx, fy);
            }
            printf("%d\n", ans);
        }
        
     
     
    }