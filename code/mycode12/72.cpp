#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, m, a[N], b[N], c[N], fa[N], sum[N];
vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int find(int x) {
    //cout << "x = " << x << endl;
    if (x != fa[x]) {
        int root = find(fa[x]);
        sum[x] ^= sum[fa[x]];
        fa[x] = root;
        return root;
    }
    return x;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> a[i] >> b[i] >> s;
        if (s[0] == 'e') {
            c[i] = 0;
        } else {
            c[i] = 1;
        }
        g.push_back(a[i] - 1);
        g.push_back(a[i]);
        g.push_back(a[i] + 1);
        g.push_back(b[i] - 1);
        g.push_back(b[i]);
        g.push_back(b[i] + 1);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= m; i++) {
        int x = get_id(a[i] - 1);
        int y = get_id(b[i]);
     //   cout << "x = " << x << " y = " << y << " " << c[i] << endl;
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            int ans = sum[x] ^ sum[y];
            if (ans != c[i]) {
                cout << i - 1 << endl;
                return 0;
            }
        } else {
            sum[fy] = sum[x] ^ sum[y] ^ c[i];
            fa[fy] = fx;
        }

    }
    cout << m << endl;
    return 0;

}