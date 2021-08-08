#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int vis[N * 100], a[N], n, m, sum[N];

int cnt[N][30], ans[N], res;

int fn[30];

char s[N];

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

struct query{
    int l, r, id;
}q[N];

int block[N];

bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return x.l < y.l;
}

void add(int pos) {
    res += vis[sum[pos]];
    for (int i = 0; i < 26; i++) {
        if (cnt[pos][i] == -1) continue;
        res += vis[cnt[pos][i]];
    }
    vis[sum[pos]]++;
}

void del(int pos) {
    vis[sum[pos]]--;
    res -= vis[sum[pos]];
    for (int i = 0; i < 26; i++) {
        if (cnt[pos][i] == -1) continue;
        res -= vis[cnt[pos][i]];
    }
}

int main() {
    fn[0] = 1;
    for (int i = 1; i <= 28; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    scanf("%d %d", &n, &m);
    int b = sqrt(n);
    scanf("%s", (s + 1));
    for (int i = 1; i <= n; i++) {
        int x = s[i] - 'a';
        a[i] = (1 << x);
        block[i] = i / b;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] ^ a[i];
        g.push_back(a[i]);
    }
    g.push_back(0);
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            int x = a[i] ^ fn[j];
            int pos = get_id(x);
            if (g[pos - 1] != x) {
                cnt[i][j] = -1;
            } else {
                cnt[i][j] = pos;
            }

        }
    }
    for (int i = 0; i <= n; i++) {
        sum[i] = get_id(a[i]);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    vis[get_id(0)] = 1;
    for (int i = 1; i <= m; i++) {
        while (l < q[i].l) {
            del(l - 1);
            l++;
        }
        while (l > q[i].l) {
            --l;
            add(l - 1);

        }
        while (r < q[i].r) {
            add(++r);
        }
        while (r > q[i].r) {
            del(r--);
        }
        ans[q[i].id] = res;
    }

    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }



}