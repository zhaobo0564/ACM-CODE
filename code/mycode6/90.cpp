#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

int a[N];
int vis[N];
int mp[100][100];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n * n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }

    if (n % 2 == 0) {
        for (int i = 1; i <= n * n; i++) {
            if (vis[a[i]] >= 4) {
                for (int j = 1; j <= n / 2; j++) {
                    int f = 0;
                    for (int k = 1; k <= n / 2; k++) {
                        if (mp[j][k] == 0) {
                            mp[j][k] = a[i];
                            mp[j][n / 2 - k + n / 2 + 1] = a[i];
                            mp[n / 2 - j + n / 2 + 1][k] = a[i];
                            mp[n / 2 - j + n / 2 + 1][n / 2 - k + n / 2 + 1] = a[i];
                            vis[a[i]] -= 4;
                            f = 1;
                            break;
                        }

                    }
                    if (f) break;
                }
            }
        }
    } else {
       for (int i = 1; i <= n * n; i++) {
            if (vis[a[i]] >= 4) {
                int f = 0;
                for (int j = 1; j <= n / 2; j++) {
                    for (int k = 1; k <= n / 2; k++) {
                        if (mp[j][k] == 0) {
                            mp[j][k] = a[i];
                            mp[j][n / 2 - k + n / 2 + 2] = a[i];
                            mp[n / 2 - j + n / 2 + 2][k] = a[i];
                            mp[n / 2 - j + n / 2 + 2][n / 2 - k + n / 2 + 2] = a[i];
                            vis[a[i]] -= 4;
                            f = 1;
                            break;
                        }

                    }
                    if (f) break;
                }
               // if (f == 0) break;
            }
        }

        for (int i = 1; i <= n * n; i++) {
            if (vis[a[i]] >= 2) {
              //  cout << "**\n";
                for (int j = 1; j <= n / 2; j++) {
                    if (mp[n / 2 + 1][j] == 0) {
                        mp[n /  2 + 1][j] = a[i];
                        mp[n / 2 + 1][ n / 2 - j + n / 2 + 2] = a[i];
                        vis[a[i]] -= 2;
                        break;
                    }
                }
            } 
        }
        for (int i = 1; i <= n * n; i++) {
            if (vis[a[i]] >= 2) {
                for (int j = 1; j <= n / 2; j++) {
                    if (mp[j][n / 2 + 1] == 0) {
                        mp[j][n / 2 + 1] = a[i];
                        mp[n / 2 - j + n / 2 + 2][n / 2 + 1] = a[i];
                        vis[a[i]] -= 2;
                        break;
                    }
                }
            } 
        }
        for (int i = 1; i <= n * n; i++) {
            if (vis[a[i]] == 1) {
                if (mp[n / 2 + 1][n / 2 + 1] == 0) {
                    mp[n / 2 + 1][n / 2 + 1] = a[i];
                    vis[a[i]]--;
                }
            }
        }

    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == 0) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }

    


}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;

    while (t--) {
        solve();
    }
}