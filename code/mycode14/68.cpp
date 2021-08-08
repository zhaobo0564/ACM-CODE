#include<bits/stdc++.h>
using namespace std;
const int N = 100007;
int h[N], n, l[N], r[N];

stack<int> q;

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
        }
        for (int i = 1; i <= n; i++) {
            while (q.size() && h[q.top()] > h[i]) {
                l[q.top()] = i;
                q.pop();
            }
            q.push(i);
        }
        while (q.size()) {
            l[q.top()] = n + 1;
            q.pop();
        }
        for (int i = n; i; i--) {
            while (q.size() && h[q.top()] > h[i]) {
                r[q.top()] = i;
                q.pop();
            }
            q.push(i);
        }
        while (q.size()) {
            r[q.top()] = 0;
            q.pop();
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            long long len = l[i] - r[i] - 1;
            ans = max(ans, len * (long long)h[i]);
        }
        printf("%lld\n", ans);

    }
}