#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

string s;

bool judge() {
    int n = s.length();
    int l = 0, r = n - 1;
    while (s[l] == s[r]) {
        l++, r--;
    }
    if (l >= r) return true;
    return false;
}

void solve() {
    cin >> s;
    int n = s.length();
    // vector<pair<int, int> >ans;
    // ans.push_back({2, 2});
    // ans.push_back({1, n});
    // ans.push_back({1, n - 1});
    // string a = "";
    // for (int i = ans[0].second - 1; i < n - 1; i++) {
    //     a += s[i];
    // }    
    // reverse(a.begin(), a.end());
    // s += a;
    // a = "";
    // //cout << s << endl;
    // for (int i = 1; i < ans[1].second; i++) {
    //     a += s[i];
    // }
    // reverse(a.begin(), a.end());
    // s = a + s;
    // a = "";
    // for (int i = 1; i < ans[2].second; i++) {
    //     a += s[i];
    // }
    // reverse(a.begin(), a.end());
    // s = a + s;
    // cout << s << endl;
    // cout << judge() << endl;
    cout << 3 << endl;
    cout << "R " << 2 << endl;
    cout <<"L " << n << endl;
    cout << "L " << n - 1 << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t = 1 ;
 //   cin >> t;
    while (t--) {
        solve();
    }
}