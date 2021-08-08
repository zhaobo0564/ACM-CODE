#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    int n;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = 0, t = 0, c = 0 , g = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == 'A') {
                a++;
            } else if (s[j] == 'T') {
                t++;
            } else if (s[j] == 'C') {
                c++;
            } else if (s[j] == 'G') {
                g++;
            }
            if (a == t && g == c) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}