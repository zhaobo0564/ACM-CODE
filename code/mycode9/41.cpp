
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> g[N];
vector<int> v;

int n, a[N], L[N], R[N], block[N], cnt[400][400], cnt_maxn[400][400];
int vis[N], c[400][N];



void build() {
    for (int i = 1; i <= n; i++) {
        g[a[i]].push_back(i);
        L[block[i]] = n + 1;
        R[block[i]] = 0;
    }

    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }

    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        for (int j = L[block[i]]; j <= R[block[i]]; j++) {
            vis[a[j]]++;
            c[block[i]][a[j]] = vis[a[j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = block[1]; j <= block[n]; j++) {
            if (c[j][a[i]] == 0) {
                c[j][a[i]] = c[j - 1][a[i]];
            }
        }
    }

    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        int maxn = 0, va;
        int mx = 0, id;

        for (int j = L[block[i]]; j <= n; j = R[block[j]] + 1) {

            maxn = 0, va;

            for (int k = L[block[j]]; k <= R[block[j]]; k++) {
                int cat = c[block[j]][a[k]] - c[block[i] - 1][a[k]];

                if (maxn < cat) {
                    maxn = cat;
                    va = a[k];
                } else if (maxn == cat) {
                    va = min(va, a[k]);
                }

            }

            if (mx < maxn) {
                mx = maxn;
                id = va;
            } else if (mx == maxn) {
                id = min(id, va);
            }

            cnt_maxn[block[i]][block[j]] = mx;
            cnt[block[i]][block[j]] = id;
    
        }
    }



}
int vi[N];
vector<int>cn;
int query(int l, int r) {
    int maxn = 0, va = 1;
    cn.clear();

    for (int i = l; i <= R[block[l]]; i++) {
        if (i >= l && i <= r) {
            vi[a[i]]++;
            cn.push_back(a[i]);
            int cat = c[block[r] - 1][a[i]] - c[block[l]][a[i]] ;
            cat = max(cat, 0);
            cat += vi[a[i]];

            if (maxn < cat) {
                maxn = cat;
                va = a[i];
            } else if (maxn == cat) {
                va = min(va, a[i]);
            }
        }
    }

    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= r; i++) {
            if (i >= l && i <= r) {
                vi[a[i]]++;
                cn.push_back(a[i]);
                int cat = c[block[r] - 1][a[i]] - c[block[l]][a[i]];
                cat += vi[a[i]];

                if (maxn < cat) {
                    maxn = cat;
                    va = a[i];
                } else if (maxn == cat) {
                    va = min(va, a[i]);
                }
            }
        }

        if (maxn < cnt_maxn[block[l] + 1][block[r] - 1]) {
            maxn = cnt_maxn[block[l] + 1][block[r] - 1];
            va = cnt[block[l] + 1][block[r] - 1];
        } else if (maxn == cnt_maxn[block[l] + 1][block[r] - 1]) {
            va = min(va, cnt[block[l] + 1][block[r] - 1]);
        }


    }

    for (int i = 0; i < cn.size(); i++) {
        vi[cn[i]] = 0;
    }

    return v[va - 1];

}

int get_id(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int read() {
    int x = 0, f = 1;
    char ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;

        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }

    return x * f;
}

void write(int x) {
    if (x >= 10)
        write(x / 10);

    putchar(x % 10 + '0');
}

int main() {
    n = read();
    int b = sqrt(n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
        block[i] = i / b + 1;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }

    build();
    int q = n;

    while (q--) {
        int l, r;
        l = read(), r = read();
        write(query(l, r));
        putchar('\n');
    }
}