#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;

int a[N], n;
multiset<int> s;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }

    int ans = 0;
    while (s.size()) {
        auto it = s.end();
        it--;
        auto cnt = s.upper_bound((*it) / 2);
        if (cnt != s.begin()) {
            cnt--;
            s.erase(cnt);
        }
        s.erase(it);
        ans++;
    }
    cout << ans << endl;

    return 0;
}