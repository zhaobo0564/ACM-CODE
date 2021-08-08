#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int a[N], n;

int vis[N * 10];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        vis[a[i]]--;
        for (int j  = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                ans += vis[j];
                if (a[i] / j != j) {
                    ans += vis[a[i] / j];
                }
            }
        }
        vis[a[i]]++;
        cout << ans << endl;
    }

}