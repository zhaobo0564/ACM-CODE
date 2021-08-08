#include <bits/stdc++.h>
using namespace std;

int t, n;

string a, b;

vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                ans.push_back(i);
                ans.push_back(0);
                ans.push_back(i);
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i: ans) {
            printf("%d ", i + 1);
        }
        puts("");

    }
}

