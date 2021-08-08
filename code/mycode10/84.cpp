#include<bits/stdc++.h>
using namespace std;

const int N = 160000 + 7;

int a[N], n, m;

struct query {
    int op, l, r, k;
};

vector<query> q;

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int flag[N], L[N], R[N], block[N];
int L1[N], R1[N], bl[N], vis[N], fn[407][N];

void init() {
    for (int i = 1; i <= n; i++) {
        L[block[i]] = n + 1;
    }
    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }
    int b = sqrt(N);
    for (int i = 1; i < N; i++) {
        bl[i] = i / b;
        L1[bl[i]] = N;
    }
    for (int i = 1; i < N; i++) {
        L1[bl[i]] = min(L1[bl[i]], i);
        R1[bl[i]] = max(R1[bl[i]], i);
    }
}

void update(int l, int r, int x) {
    if (block[l] == block[r]) {
        for (int i = l; i <= r; i++) {
            a[i] = min(a[i], x);
        } 
    } else {
        for (int i = l; i <= R[block[l]]; i++) {
            a[i] = min(a[i], x);
        }
        for (int i = L[block[r]]; i <= r; i++) {
            a[i] = min(a[i], x);
        }
        for (int i = block[l] + 1; i < block[r]; i++) {
            flag[i] = min(flag[i], x);
        }
    }
}




int qu(int l, int r, int k) {
    for (int i = l; i <= r; i++) {
        a[i] = min(flag[block[i]], a[i]);
        vis[bl[a[i]]]++;
        fn[bl[a[i]]][a[i]]++;
    }

    int ans = 0;
    for (int i = bl[1]; i < bl[N - 1]; i++) {
        if (k > vis[i]) {
            k -= vis[i];
        } else {
            for (int j = L1[i]; j <= R1[i]; j++) {
                if (k > fn[i][j]) {
                    k -= fn[i][j];
                } else {
                    ans = j;
                    break;
                }
            }
        }
        if (ans) break;
    }
    for (int i = l; i <= r; i++) {
        a[i] = min(flag[block[i]], a[i]);
        vis[bl[a[i]]]--;
        fn[bl[a[i]]][a[i]]--;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back(a[i]);
    }
    while (m--) {
        int op, l, r, k;
        scanf("%d %d %d %d", &op, &l, &r, &k);
        q.push_back({op, l, r, k});
        if (op == 1) {
            g.push_back(k);
        }
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
       
        block[i] = i / b; 
        flag[block[i]] = INT_MAX;
    }
    init();
    for (int i = 0; i < q.size(); i++) {
        if (q[i].op == 1) {
            update(q[i].l, q[i].r, get_id(q[i].k));
        } else {
            printf("%d\n", g[qu(q[i].l, q[i].r, q[i].k) - 1]);
        }
    }



}