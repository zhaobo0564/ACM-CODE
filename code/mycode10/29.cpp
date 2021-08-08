#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, a[N], b[N], p[N];

vector<pair<int, int> >ans;

int vis[N], cnt[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        cnt[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) continue;
        if (a[cnt[i]] <= b[i]) {
            cout << -1 << endl;
            return 0;
        }
        if (vis[i]) continue;
        vis[i] = 1;
        vector<int> v;
        v.push_back(i);
        for (int j = p[i]; j != i; j = p[j]) {
            if (a[cnt[j]] <= b[j]) {
                cout << -1 << endl;
                return 0;
            }
            v.push_back(j);
            vis[j] = 1;
        }
        int pos = 0;
        for (int j = 0; j < v.size(); j++) {
            if (a[v[j]] > a[v[pos]]) {
                pos = j;
            }
        }
        for (int j = pos + 1; j < v.size(); j++) {
            ans.push_back({v[pos], v[j]});
        }
        for (int j = 0; j < pos; j++) {
            ans.push_back({v[j], v[pos]});
        }
    }
    cout << ans.size() << endl;
    for (auto it: ans) {
        cout << it.first << " " << it.second << endl;
    }
}