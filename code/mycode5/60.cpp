#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int t, n;

string s;

set<int>a, b;
int vis[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        a.clear();
        b.clear();
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                a.insert(i);
            } else {
                b.insert(i);
            }
            vis[i] = 0;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (vis[i])continue;
            if (s[i] == '0') {
                int f = 1;
                int pos = i;
                vis[pos] = ans;
                while (1) {
                    if(f) {
                        auto it = b.lower_bound(pos);
                        if (it == b.end()) {
                            break;
                        }
                        vis[*it] = ans;
                        pos = *it;
                        b.erase(it);
                        f = 0;
                    } else {
                        auto it = a.lower_bound(pos);
                        if (it == a.end()) {
                            break;
                        }
                        pos = *it;
                        vis[pos] = ans;
                        a.erase(it);
                        f = 1;
                    }
                }
                ans++;
            } else {
                int f = 0;
                int pos = i;
                vis[pos] = ans;
                while (1) {
                    if(f) {
                        auto it = b.lower_bound(pos);
                        if (it == b.end()) {
                            break;
                        }
                        vis[*it] = ans;
                        pos = *it;
                        b.erase(it);
                        f = 0;
                    } else {
                        auto it = a.lower_bound(pos);
                        if (it == a.end()) {
                            break;
                        }
                        pos = *it;
                        vis[pos] = ans;
                        a.erase(it);
                        f = 1;
                    }
                }
                ans++;
            }
        }
        cout << ans - 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << vis[i] << " ";
        }
        cout << endl;



        

    }
}