#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct query {
    int l, r, id, t;
}

int block[N], n, m;

bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        if (block[x.r] == block[y.r]) {
            return x.t < y.t;
        }
        return block[x.r] < block[y.r];
    }
    return block[x.l] < block[y.l];
}

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

void add(int pos) {

} 

void del(int pos) {

}

void update(int pos) {

}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }

    int l = 1, r = 0, now = 0;
    for (int i = 1; i <= m; i++) {
        while ()
    }

    
}