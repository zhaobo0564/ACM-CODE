#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    int top = 1;
    while (cin >> s) {
        if (s[0] == '-') {
            break;
        }
        int base = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{') {
                base++;
            } else {
                base--;
            }
            if (base < 0) {
                ans++;
                base += 2;
            }
        }
        cout << top++ <<". " << ans + base / 2 << endl;
        

    }
}