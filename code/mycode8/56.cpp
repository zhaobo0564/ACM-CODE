#include<bits/stdc++.h>

using namespace std;
const int N = 3e3 + 7;

int a[N], n;

int dfs(int l, int r) {
    int minn = INT_MAX;
    for (int i = l; i <= r; i++) {
        minn = min(minn, a[i]);
    }

    int last = l;

    int ans = minn;
    for (int i = l; i <= r; i++) {
        a[i] -= minn;
        if (a[i] == 0) {
            ans += dfs(last, i - 1);
            last = i + 1;
        }
    }

    if (last <= r) {
        ans += dfs(last, r);
    }
    return min(ans, r - l + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << dfs(1, n) << endl;
    

}