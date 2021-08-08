#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
string s[N];
int vis[200], n;

bool solve() {

    int l = 1, r = n;
    while (l <= r) {
        for (int i = 'a'; i <= 'z'; i++) {
            vis[i] = 0;
        }
        for (char i: s[l]) {
            vis[i] = 1;
        }
        int f = 0;
        for (char i: s[r]) {
            if (vis[i]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            return false;
        }
        l++, r--;
    }
    return true;
  
}

int main() {
    int t; cin >> t;
    while (t--) {
         cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        if (solve()) {
            puts("Yes");
        } else {
            puts("No");
        }
        

    }
}

