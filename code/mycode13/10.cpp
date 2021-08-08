#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int n;

struct node {
    int l, r, id;
}p[N];

bool cmp(node x, node y) {
    return x.l < y.l;
}

vector<int> g;

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].l >> p[i].r;
            p[i].id = i;
        
        }
        sort(p + 1, p + n + 1, cmp);
        int base = 1, maxn = 0, fi = 1, se = 2;
        for (int i = 2; i <= n; i++) {
            if (p[i].r <= p[base].r) {
                int cnt = p[i].r -p[i].l;
                if (cnt > maxn) {
                    maxn = cnt;
                    fi = p[base].id;
                    se = p[i].id;
                }
            } else {
                int cnt = p[base].r - p[i].l;
                if (cnt > maxn) {
                    maxn = cnt;
                    fi = p[base].id;
                    se = p[i].id;
                }
                base = i;
            }
        }
        cout << maxn << " " << fi << " " << se << endl;

    }
}