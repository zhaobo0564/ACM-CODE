#include<bits/stdc++.h>
using namespace std;

const int N = 507;

vector<int> g[N];

int d[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    int ct = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            ct++;
        }
    }
    if (ct == 2) {
        puts("I");
    } else if (ct == 3) {
        puts("Y");
    } else if (ct == 4) {
        puts("X");
    } else {
        puts("NotValid");
    }
}