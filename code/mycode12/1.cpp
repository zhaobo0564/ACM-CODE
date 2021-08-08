#include<bits/stdc++.h>
using namespace std;
const int N = 4e4 + 7;

int  n, m;

vector<int> g;

int a[N], b[N], c[N], fa[N], d[N];

int find(int x) {
    if (x != fa[x]) {
        int root = find(fa[x]);
        d[x] ^= d[fa[x]];
        fa[x] = root;
        return root;
    }
    return x;
}

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string name;
        cin >> a[i] >> b[i] >> name;
        if (name == "even") {
            c[i] = 0;
        } else {
            c[i] = 1;
        }
        g.push_back(a[i]);
        g.push_back(a[i] - 1);
        g.push_back(a[i] + 1);
        g.push_back(b[i]);
        g.push_back(b[i] - 1);
        g.push_back(b[i] + 1);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 0; i < g.size() + 1; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        a[i] = get_id(a[i]);
        b[i] = get_id(b[i]);
        int fx = find(a[i] - 1);
        int fy = find(b[i]);
        if (fx == fy) {
            if (d[a[i] - 1] ^ d[b[i]] != c[i]) {
                cout << i - 1 << endl;
                return 0;
            }
        } else {
            fa[fx] = fy;
            d[fx] = d[a[i] - 1] ^ d[b[i]] ^ c[i];
        }
    }
    cout << m << endl;
    return 0;


}