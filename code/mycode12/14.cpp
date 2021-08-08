#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q = 0;
void solve() {
    
    ll u, v;
    cin >> u >> v;
    if (u > v) {
        cout << "No\n";
        return;
    } 
    vector<int>uone, vone;
    for (int i = 0; i <= 30; i++) {
        if (((1 << i) & u)) {
            uone.push_back(i);
        } 
        if (((1 << i) & v)) {
            vone.push_back(i);
        }
    }
    if (uone.size() < vone.size()) {
        cout << "No\n";
    } else if (uone.size() == vone.size()) {
        for (int i = 0; i < uone.size(); i++) {
            if (uone[i] > vone[i]) {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    } else {
        for (int i = 0; i < vone.size(); i++) {
            if (uone[i] > vone[i]) {
                cout << "No\n";
                return;
            }
        }
        if (vone[vone.size() - 1] < uone[uone.size() - 1]) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        return;
    }
    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}