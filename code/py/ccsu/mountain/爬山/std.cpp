﻿#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
const int M = 2e6 + 7;
typedef long long ll;
ll dist[N][N];
int n, q, ans[M];

struct msg {
    int a, h;
}p[N];

struct qu {
    ll w;
    int id;
};

vector<qu> query[N]; 

void floyd() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
            }
        }
    }
}

int vis[N];

int main() {

    scanf("%d %d", &n, &q);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].a, &p[i].h);
        if (p[i].a > n) {
        	return 0;
		}
		if (vis[p[i].a]) return 0;
		vis[p[i].a] = 1;
    }
    sort(p + 1, p + n + 1, [](msg x, msg y) {
        return x.a < y.a;
    });
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        for (int j = i + 1; j <= n; j++) {
            if (p[i].h < p[j].h) {
                ll w = 1ll * p[j].h * 1ll * (j - i + 1);
                dist[i][j] = w;
            }
        }
    }
    floyd();
    for (int i = 1; i <= q; i++) {
        int x;
        ll w; 
        scanf("%d %lld", &x, &w);
        query[x].push_back({w, i});
    }
    for (int i = 1; i <= n; i++) {
        sort(query[i].begin(), query[i].end(), [](qu x, qu y) {
            return x.w > y.w;
        });
    }

    for (int i = 1; i <= n; i++) {
        int pos = n;
        for (int j = 0; j < query[i].size(); j++) {
            while (pos > 0 && dist[i][pos] > query[i][j].w) {
                pos--;
            }
            ans[query[i][j].id] = pos;
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
