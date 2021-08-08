#include<bits/stdc++.h>
using namespace std;
const int N = 5007;
int n, a[N], b[N], vis[2 * N], cnt[N], cat[2 * N], res[N];

multiset<int> s;
vector<pair<int, int> > v;

bool judge(int x, int ct) {
    for (int i = 1; i <= n; i++) {
        cat[b[i]] = 0;
    }
    for (int i = 0; i < v.size(); i++) {
        cat[v[i].first]++;
    }
    cat[x]--;
    int pos = 1, ans = 0;
    for (int i = 1; i <= N * 2; i++) {
        if (vis[i]) {
            for (int j = 1; j <= vis[i]; j++) {
                while (pos <= N * 2) {
                    if (pos <= i) pos++;
                    else {
                        if (cat[pos]) {
                            ans++;
                            cat[pos]--;
                            break;
                        }
                        pos++;
                    }
                }
            }
        }
    }  
    
    if (ct == ans) return true;
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    int ct = 0;
    for (int i = 1; i <= n; i++) {
        auto it = s.upper_bound(a[i]);
        if (it != s.end()) {
            ct++;
            s.erase(it);
        }
    }
    int cn = 0;
    for (int i = 1; i <= n; i++) {
        vis[a[i]]--;
        v.clear();
        for (int j = 1; j <= n; j++) {
            if (cnt[j]) continue;
            v.push_back({b[j], j});
        }
        sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y) {
            return x.first < y.first;
        });
        int l = 0, r = v.size() - 1, pos = v.size(), ans = -1;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].first > a[i]) {
                pos = j;
                break;
            }
        }
        l = pos;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (judge(v[mid].first, ct - cn - 1)) {
                ans = v[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans == -1) {
            l = 0, r = pos - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (judge(v[mid].first, ct - cn)) {
                    ans = v[mid].second;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        cnt[ans]++;
        res[i] = b[ans];
        if (b[ans] > a[i]) cn++;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    puts("");
    
}