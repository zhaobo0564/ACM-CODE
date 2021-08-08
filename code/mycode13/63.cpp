#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;
int op, w;
int t = 1;
int o = 1;
ll sum[N], ans[N];

int lowbit(int x) {
    return (x & -x);
}

void add(ll v, int x) {
    while (x <= t) {
        sum[x] += v;
        x += lowbit(x);
    }
}

ll query(int x) {
    ll ans = 0;
    while (x > 0) {
        ans += sum[x];
        x -= lowbit(x);
    }
    return ans;
}

struct node {
    int x, y, z, sum, id, f;
}p[N];

bool cmp(node x, node y) {
    if (x.x == y.x) {
        if (x.y == y.y) {
            return x.z < y.z;
        }
        return x.y < y.y;    
    }
    return x.x < y.x;
}
#define m (l + r >> 1)

struct msg {
    int x, y, z, sum, f, id, ok; 
};


vector<msg> g;

bool cmp1(msg x, msg y) {
    if (x.y == y.y) {
        return x.f < y.f;
    }
    return x.y < y.y;
}

void work(int l, int r) {
    if (l == r) return;
    g.clear();
    for (int i = l; i <= m; i++) {
        g.push_back({p[i].x, p[i].y, p[i].z, p[i].sum, -1, p[i].id, p[i].f});
    }
    for (int i = m + 1; i <= r; i++) {
         g.push_back({p[i].x, p[i].y, p[i].z, p[i].sum, 1, p[i].id, p[i].f});
    }
    sort(g.begin(), g.end(), cmp1);
    //cout << "l = " << l << "r = " << r << endl;
  //  cout << "********\n\n";
    for (int i = 0; i < g.size(); i++) {
        if (g[i].f == -1 && g[i].id == -1) {
        //    cout << "sum = " << g[i].sum << " z = " << g[i].z << endl;
            add(g[i].sum, g[i].z);
        } else if (g[i].f == 1 && g[i].id != -1) {
          //  cout << "VA " << query(g[i].z) << "z = " <<g[i].z << " " << g[i].ok << " id = " << g[i].id << endl;
            //cout << "x = " << g[i].x << " y = " << g[i].y << " z = " << g[i].z << endl;
            ans[g[i].id] += query(g[i].z) * 1ll*g[i].ok;
        }
    }
    for (int i = 0; i < g.size(); i++) {
        if (g[i].f == -1 && g[i].id == -1) {
            add(-g[i].sum, g[i].z);
        }
    }
    work(l, m);
    work(m + 1, r);

}



int main() {
    scanf("%d %d", &op, &w);
    while (~scanf("%d", &op) && op != 3) {
        if (op == 1) {
            int x, y, a;
            scanf("%d %d %d", &x, &y, &a);
            p[t] = {x, y, t++, a, -1, 0};

        } else {
            int x[3], y[3];
            scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
            p[t] = {x[1], y[1], t++, 0, o, 1};
            p[t] = {x[1], y[0] - 1, t++, 0, o, -1};
            p[t] = {x[0] - 1, y[1], t++, 0, o, -1};
            p[t] = {x[0] - 1, y[0] - 1, t++, 0, o, 1};
            o++;
        }
    }
    sort(p + 1, p + t, cmp);

    work(1, t - 1);
    for (int i = 1; i < o; i++) {
        cout << ans[i] << endl;
    }
}
/*
0 4
1 2 3 3
2 1 1 3 3
1 2 2 2
2 2 2 3 4
3
*/