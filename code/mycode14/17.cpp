#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 7;

ll a[N], sum[N];

deque<int> q;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n + n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 0;
    q.push_back(0);
    for (int i = 1; i <= n + n; i++) {
        while (q.size() && q.front() + n < i) {
            q.pop_front();
        }
        if (q.size()) {
            ans = max(ans, sum[i] - sum[q.front()]);
        }
        while (q.size() && sum[q.back()] >= sum[i]) {
            q.pop_back();
        }
        q.push_back(i);
        
    }
    cout << ans << endl;


}