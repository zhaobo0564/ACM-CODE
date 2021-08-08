#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int tree[40 * N][2];

int n, a[N], top = 1;

void insert(int x) {
    int now = 0;
    for (int i = 21; i >= 0; i--) {
        if ((x & (1 << i))) {
            if (tree[now][1]) {
                now = tree[now][1];
            } else {
                tree[now][1] = top++;
                now = tree[now][1];
            }
        } else {
            if (tree[now][0]) {
                now = tree[now][0];
            } else {
                tree[now][0] = top++;
                now = tree[now][0];
            }
        }
    }
}

int query(int base, int d, int now) {
    if (d < 0) return 0;
    if ((base & (1 << d))) {
        if (tree[now][0]) {
            return query(base, d - 1, tree[now][0]) + (1 << d);
        } else {
            return query(base, d - 1, tree[now][1]);
        }
    } else {
        if (tree[now][1]) {
            return query(base, d - 1, tree[now][1]) + (1 << d);
        } else {
            return query(base, d- 1, tree[now][0]);
        }
    }
}

int sum[N], vis[40 * N];

int main() {
    cin >> n;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }   
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        insert(sum[i - 1]);
        ans = max(ans, query(sum[i], 21, 0));
    }
    int l = 0, r = 0, minn = n + 1;
    memset(vis, -1,sizeof(vis));
    vis[0] = 0;
    for (int i = 1; i <= n; i++) {
        int cnt  =  ans ^ sum[i];
        if (vis[cnt] >= 0) {
            if (minn > i - vis[cnt]) {
                minn = i - vis[cnt];
                l = vis[cnt];
                r = i;
                break;
            } 
        }
        vis[sum[i]] = i;
    }
    cout << ans << " " << l + 1 << " " << r << endl;

}