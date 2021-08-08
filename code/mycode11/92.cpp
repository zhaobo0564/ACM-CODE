#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

int m, n;

vector<int> ans;

int ac[50], all[50], vis[50];

int main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    while (m--) {
        int x;
        string op;
        cin >> x >> op;
        all[x]++;
        if (op == "AC") {
            ac[x]++;
        }
        if (ac[x] * 2 >= all[x]) {
            ans.push_back(x);
        } else {
            vis[x] = 1;
        }
    }  
    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i: ans) {
        if (vis[i]) continue;
        cout << i << " ";
    }
    cout << endl;
    return 0;
}