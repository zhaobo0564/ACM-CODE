#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

int n, a[N], T, b[N];

map<int, int>fi, se;

void solve() {
    fi.clear();
    se.clear();
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 

    for (int i = 1; i <= n; i++) {
        if (a[i] > T) {
            fi[a[i]]++;
            b[i] = 1;
        } else {
            int cnt = T - a[i];
            if (fi[cnt] > se[cnt]){
                se[a[i]]++;
                b[i] = 0;
            } else {
                fi[a[i]]++;
                b[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;


}

int main() {
    // ios::sync_with_stdio(0);
    // int t; cin >> t;
    // while (t--) {
    //     solve();
    // }

    int ans = 0;
    for (int i = 1; i <= 3e5; i++) {
        ans += (350000) / i;
    }
    cout << ans << endl;
}