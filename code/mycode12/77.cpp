#include<bits/stdc++.h>
using namespace std;

const int N = 60;

int   n, vis[N];

struct node{
    double v; 
    int id, f;
}a[N];

bool cmp(node x, node y) {
    return x.v < y.v;
}
int ans = 1;
int cnt[N];

void work() {
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cnt[a[i].id] = i;
    }
    for (int i = 1; i < n; i++) {
        if ( a[i].v == a[i + 1].v) {
            if (a[i].f != a[i + 1].f) {
                a[i].f = -a[i].f;
                a[i].f = -a[i + 1].f;
                if (vis[a[i].id] == 1) {
                    if (vis[a[i + 1].id] == 0) {
                        ans++;
                    }
                    vis[a[i + 1].id] = 1;
                }
                if (vis[a[i + 1].id] == 1) {
                    if (vis[a[i].id] == 0) {
                        ans++;
                    }
                    vis[a[i].id] = 1;
                }
            }
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
        if (a[i].v < 0) {
            a[i].v = -a[i].v;
            a[i].f = -1;
        } else {
            a[i].f = 1;
        }
        a[i].id = i;
    }
    vis[1] = 1;
    int t = 200000;
    while(t--) {
        work();
        for (int i = 1; i <= n; i++) {
            a[cnt[i]].v += 0.5 * (double)a[cnt[i]].f;
            work();
        }

    }


    cout << ans << endl;


    return 0;
}