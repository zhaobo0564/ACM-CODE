#include<bits/stdc++.h>
using namespace std;

char change(char x) {
    if (x == '*') {
        return 'o';
    }
    return '*';
}

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] != t[i]) {
            s[i] = change(s[i]);
            s[i + 1] = change(s[i + 1]);
            ans++;
            
        }
    }
    cout << ans << endl;
    
}