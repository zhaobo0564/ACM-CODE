#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> q;
int a[1000];

bool work() {
    while (q.size()) q.pop();
    for (int i = 0; i < s.length(); i++) {
        if (q.size() == 0) {
            q.push(a[i]);
        } else {
            if (q.top() == 1 && q.top() != a[i]) {
                q.pop();
            } else {
                q.push(a[i]);
            }
        }
    }
    if (q.size()) return false;
    return true;
}

void solve() {
    
    cin >> s;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int z = 0; z <= 1; z++) {
                for (int k = 0; k < s.length(); k++) {
                    if (s[k] == 'A') {
                        a[k] = i;
                    } else if (s[k] == 'B') {
                        a[k] = j;
                    } else {
                        a[k] = z;
                    }
                }
                if (work()) {
                    
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
    
    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}