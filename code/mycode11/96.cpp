#include<bits/stdc++.h>
using namespace std;

string s, t;

int main() {
    cin >> s >> t;
    string a = "", b = "";
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        a += s[i];
        b = "";
        for (int j = 0; j < s.length(); j++) {
            b += s[j];
            if (a.length() + b.length() <= t.length()) {
                string c = a + b;
                int f = 0;
                for (int k = 0; k < a.length() + b.length(); k++) {
                    if (t[k] != c[k]) {
                        f = 1;
                        break;
                    }
                }
              //  cout << c << endl;
                if (f == 0) {
                  //  cout << a <<" " << b << endl;
                  cout << c << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}