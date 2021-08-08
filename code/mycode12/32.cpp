#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
stack<int> q;
int n, a[N], k, last[N], vis[N];


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]]) continue;
        while (q.size() && last[q.top()] > i && q.top() > a[i]) {
            vis[q.top()] = 0;
            q.pop();
        }
        q.push(a[i]);
        vis[a[i]] = 1;
    }

    vector<int> v;
    while (q.size()) {
        v.push_back(q.top());
        q.pop();
    }
    reverse(v.begin(), v.end());
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
}