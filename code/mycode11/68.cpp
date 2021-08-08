#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;
multiset<int> s;

int n, a[N], m;

deque<int> q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
        q.push_back(a[i]);
    }

    while (m--) {
        char a[7], b[7];
        scanf("%s %s",a, b);
        if (a[1] == 'O') {
            if (b[0] == 'B') {
                if (q.size()) {
                    int cnt = q.back();
                    q.pop_back();
                    auto it = s.lower_bound(cnt);
                    s.erase(it);
                }
            } else {
                if (q.size()) {
                    int cnt = q.front();
                    q.pop_front();
                    auto it = s.lower_bound(cnt);
                    s.erase(it);
                }
            }
        } else {
            if (b[0] == 'F') {
                int x; scanf("%d", &x);
                q.push_front(x);
                s.insert(x);
            } else {
                int x; scanf("%d", &x);
                q.push_back(x);
                s.insert(x);
            }
        }
        if (q.size()) {
            auto it = s.begin();
            printf("%d ", *it);
            it = s.end();
            it--;
            printf("%d\n", *it);
        } else {
            puts("EMPTY");
        }
    }
}