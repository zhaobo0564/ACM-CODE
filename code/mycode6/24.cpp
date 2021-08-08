#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

int n, a[N], dp[N];

stack<int> q, q1;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = n + 1;
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i - 1] + 1, dp[i]);
        while (!q.empty() && a[q.top()] <= a[i]) {
            int x = a[q.top()];
            q.pop();
            if (a[i] == x) continue;
            if (!q.empty()) {
                dp[i] = min(dp[i], dp[q.top()] + 1);
            }
        }

        while (!q1.empty() && a[q1.top()] >= a[i]) {
            int x = a[q1.top()];
            q1.pop();
            if (x == a[i]) continue;
            if (!q1.empty()) {
                dp[i] = min(dp[i], dp[q1.top()] + 1);
            }
        }
        q.push(i);
        q1.push(i);
        
    }
    cout << dp[n]  << endl;


}