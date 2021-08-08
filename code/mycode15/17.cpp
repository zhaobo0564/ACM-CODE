#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '6') {
            cout << 9;
        } else if (s[i] == '9') {
            cout << 6;
        } else {
            cout << s[i];
        }
    }
    cout << endl;
}