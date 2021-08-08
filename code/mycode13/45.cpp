#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

char s[N];

int sum[N][30], vis[30], cnt[N];

deque<int> g[200];
vector<char> ans;
int n, last = 0;



bool judge(int pos) {

    for (int i = 0; i <= 25; i++) {
        if (cnt[i]) continue;
        if ((sum[pos - 1][i] - sum[last][i]) > 0) {
            int cnt = sum[n][i] - sum[pos][i];
           // cout << "cnt " << cnt << endl; 
            if (cnt <= 0) {
                return false;
            }
        }
    }    
    for (int i = 0; i <= 25; i++) {
        while (g[i].size() && g[i].front() <= pos) {
            g[i].pop_front();
        }
    }

    return true;
}

void solve() {
    ans.clear();
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 0; i <= 26; i++) {
        vis[i] = 0;
        cnt[i] = 0;
        g[i].clear();
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 26; j++) {
            sum[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        vis[s[i] - 'a']++;
        for (int j = 0; j <= 25; j++) {
            sum[i][j] = vis[j];
        }
        g[s[i] - 'a'].push_back(i);
    }
    last = 0;
    while (1) {
        int f = 0;
        for (int i = 25; i >= 0; i--) {
            if (g[i].size()) {
                int pos = g[i].front();
                if (judge(pos)) {
                 //  cout << "pos " << pos << endl;
                    f = 1;
                    cnt[i] = 1;
                    last = pos;
                    ans.push_back(char(i + 'a'));
                    g[i].clear();
                    break;
                }

            }
        }
        if (f == 0) break;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}