#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
vector<int> v;
void dfs(int p) {
    if (p > n) {
        int cnt = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > v[i - 1]) {
                cnt++;
            } else if (v[i] < v[i - 1]) {
                cnt += 2;
            }
        }
        ans += cnt;
        return ;
    }

    for (int i = 1; i <= m; i++) {
        v.push_back(i);
        dfs(p + 1);
        v.pop_back();
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> m;
   
        for (int i = 1; i <= m; i++) {
            v.push_back(i);
            dfs(2);
            v.pop_back();
        }
        cout << ans << endl;
    }

}