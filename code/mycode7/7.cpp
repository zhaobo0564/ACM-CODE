#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 8;

int main() {
    ios::sync_with_stdio(0);

    char s, c; cin >> s >> c;
    if (s == 'Y') {
        if (c >= 'a') {
            cout << char(c - 32) << endl;
        } else {
            cout << c << endl;
        }
    } else {
        cout << c << endl;
    }
}