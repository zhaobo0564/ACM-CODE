#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
typedef long long ll;

char a[N], b[N];

int visa[200], visb[200];

void solve() {
    int n, k;
    for (int i = 'a'; i <= 'z'; i++) {
        visa[i] = visb[i] = 0;
    }
    cin >> n >> k;
    cin >> (a + 1) >> (b + 1);
    for (int i = 1; i <= n; i++) {
        visa[a[i]]++;
        visb[b[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++){
        if (visb[i] <= visa[i]) {
            visa[i] -= visb[i];
            continue;
        }
        int cnt = visb[i] - visa[i];
        visa[i] = 0;
        for (int j = i - 1; j >= 'a'; j--) {
            if (visa[j] >= k) {
                int cn = visa[j] / k;
                if (cnt >= cn * k) {
                    cnt -= cn * k;
                    visa[j] -= cn * k;
                } else if (cnt == k) {
                    cnt = 0;
                    visa[j] -= cnt;
                }
                
            }
        }
    }

    for (int i = 'a'; i <= 'z'; i++) {
        if (visa[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}