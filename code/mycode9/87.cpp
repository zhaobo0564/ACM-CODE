#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, a[N], b[N];

struct node {
    int x, y;
};

vector<node> v;
bool cmp(node x, node y) {
    return x.x > y.x;
}

bool cmp1(node x, node y) {
    return x.y > y.y;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        v.push_back({a[i], b[i]});
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0, res = 1e16, cat = 0;
    for (int i = 0; i < v.size(); i++) {
        ans = cat + v[i].x;
        res = min(res, ans);
        cat = max(cat, 1ll*v[i].y);
    }

    sort(v.begin(), v.end(), cmp1);
    cat = 0;
    for (int i = 0; i < v.size(); i++) {
        ans = cat + v[i].y;
        res = min(res, ans);
        cat = max(cat, 1ll*v[i].x);
    }


    printf("%lld\n", res);
    
}