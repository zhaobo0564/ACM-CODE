#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, a[N];
char op[N];

int x[N * 202];

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 2;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %c", &a[i], &op[i]);
        g.push_back(a[i]);
        g.push_back(a[i] + 1);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (op[i] == '+') {
            x[1]++;
            x[a[i]]--;
        } else if (op[i] == '-') {
            x[a[i] + 1]++;
            x[N * 100]--;
        } else {
            x[a[i]]++;
            x[a[i] + 1]--;
        }
    }
    for (int i = 1; i <= 200 * N; i++) {
        x[i] = x[i - 1] + x[i];
    }
    int ans = 0;
    for (int i = 0; i <= 200 * N; i++) {
        ans = max(ans, x[i]);
    }
    cout << ans << endl;

}