#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 7;


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        if ( n % 2) {
            int f = 0;
            for (int i = 0; i < s.length(); i += 2) {
                if ((s[i] - '0') % 2) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                puts("1");
            } else {
                puts("2");
            }
        } else {
            int f = 0;
            for (int i = 1; i < s.length(); i += 2) {
                if ((s[i] - '0') % 2 == 0) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                puts("2");
            } else {
                puts("1");
            }
        }
    }
}