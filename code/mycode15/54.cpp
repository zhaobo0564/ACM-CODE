#include<bits/stdc++.h>
using namespace std;

map<int, vector<int> > mp;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        mp[x].push_back(y);
    }
    set<int> ans, temp;
    ans.insert(n);
    for (auto it: mp) {
        temp.clear();
        for (int y: it.second) {
            if (ans.count(y + 1) || ans.count(y - 1)) {
                temp.insert(y);
            }
        }
        for (int y: it.second) {
            if (ans.count(y)) {
                ans.erase(y);
            }
        }
        for (int i: temp) {
            ans.insert(i);
        }
    }
    cout << ans.size() << endl;
    return 0;
}