#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll n, m, a[N];

struct node {
    ll v, pos;
}p[N];

bool cmp(node x, node y) {
    return x.v > y.v;
}

vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ans.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i].v = a[i];
            p[i].pos = i;
        }
        sort(p + 1, p + n + 1, cmp);
        ll base = m / 2;
        if (m % 2) base++;
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
           if (cnt + p[i].v <= m) {
               cnt += p[i].v;
               ans.push_back(p[i].pos);
           }
           if (cnt >= base) {
               break;
           }
        }

        if (cnt >= base) {
            sort(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (int i: ans) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout <<  -1 << endl;
        }
        
    }
}