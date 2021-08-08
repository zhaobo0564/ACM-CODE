#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

vector<int>g;

vector<pair<int, int> >v;
int t, n, m, c[N];

int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main(){
    scanf("%d", &t);
    int ca = 1;
    while(t--){
        printf("Case #%d:\n", ca++);
        memset(c, 0, sizeof(c));
        v.clear(), g.clear();
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            int l, r;
            scanf("%d %d", &l, &r);
            g.push_back(l - 1);
            g.push_back(l);
            g.push_back(r);
            g.push_back(l + 1);
            v.push_back({l, r});
        }

        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());

        for(int i = 0; i < n; i++){
            int l = get_id(v[i].first);
            int r = get_id(v[i].second);
           // cout << " l = " << l << " r = " << r << endl;
            c[l]++;
            c[r + 1]--;
        }
        for(int i = 1; i < N; i++){
            c[i] += c[i - 1];
        }
        while(m--){
            int x;
            scanf("%d", &x);
            x = get_id(x);
          //  cout << "x = " << x << endl;
            printf("%d\n", c[x]);
        }

    }
}