#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
 int w, h, n;
int vis[N];

void solve() {
    cin >> w >> h >> n;
    int ans = 1;
    while (1) {
        if (w % 2 == 0) {
            ans = ans * 2;
            w = w / 2;
        } else {
            break;
        }
    }
    while (1) {
        if (h % 2 == 0) {
            ans = ans * 2;
            h = h / 2;
        } else {
            break;
        }
    }
    if (ans >= n) {
        puts("Yes");
    } else {
        puts("No");
    }
}

int main() {
   
    int t; cin >> t;
    while (t--) {
        solve();
    }
}