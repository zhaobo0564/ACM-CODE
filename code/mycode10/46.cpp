#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(l, r) for (int i = l; i <= r; i++)
const int N = 2e5 + 7;

bool judge(string s, string a) {
    if (a.length() % s.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i = i + s.length()) {
        for (int j = 0; j < s.length(); j++) {
            if (s[j] !=  a[i + j]) {
                return false;
            }
        }
    }
    return true;
}

int lcm(int x, int y) {
    return x * y / __gcd(x, y);
}

void solve() {
    string a, b;
    cin >> a >> b;
    string str = "";
    int f = 0;

    for (int i = 0; i < a.length(); i++) {
        str += a[i];
        if (judge(str, a)) {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        cout << -1 << endl;
        return;
    }
    if (judge(str, b)) {
        int aa = a.length() / str.length();
        int bb = b.length() / str.length();
        int lc = lcm(aa, bb);
        rep(1, lc) {
            cout << str;
        }
        cout << endl;

    } else {
        cout << -1 << endl;
        return;
    }

}


int main() {
    int t; cin >> t;
    while (t--) {
       solve();
    }

}