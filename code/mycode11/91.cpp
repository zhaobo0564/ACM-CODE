#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

int a[N], b[N], n, m;
int c[N];

int fa[N], d[N], sz[N];

int find(int x) {
    if (x != fa[x]) {
        int root = find(fa[x]);
        d[x] = d[x] ^ d[fa[x]];
        fa[x] = root;
        return root;
    }
    return x;
}

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
         cin >> a[i] >> b[i];
         string s; cin >> s;
         if (s == "even") {
             c[i] = 0;
         } else {
             c[i] = 1;
         }
        g.push_back(a[i]);
        g.push_back(a[i] + 1);
        g.push_back(a[i] - 1);
        g.push_back(b[i]);
        g.push_back(b[i] + 1);
        g.push_back(b[i] - 1);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= m; i++) {
        a[i] = get_id(a[i]);
        b[i] = get_id(b[i]);
     //   cout << a[i] << " " << b[i] << endl;
        int fx = find(a[i] - 1);
        int fy = find(b[i]);
    ///    cout << fx << " " << fy << " " << d[fy] << endl;
        if (fx == fy) {
            int ans = d[a[i] - 1] ^ d[b[i]];
      //      cout << "I = " << i << " ans = " << ans <<  " c " << c[i] << endl;
            if (ans != c[i]) {
                cout << i - 1 << endl;
                return 0;
            }
        } else {
            fa[fy] = fx;
          //  cout << "dy " << d[fy] << " sz " << sz[fx] << endl;
            d[fy] = d[fy] ^ d[fx] ^ d[a[i] - 1] ^ c[i]; 
          //  sz[fx] = sz[fx] ^ sz[fy] ^ c[i];   

         //   cout << "fy =" << fy << " " <<d[fy] << endl;     
         //    cout << "fx = " << fx << " " << d[fx] << endl; 
        }

       
    }
    cout << m << endl;
    return 0;
    

     
}
