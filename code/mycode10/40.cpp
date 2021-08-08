#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int main() {
    string a, b;
    cin >> a >> b;
    string ans = "";
    vector<string> v;
    for (int i = 0; i < a.length(); i++) {
        ans += a[i];
        string cnt = ans;
        for (int j = 0; j < b.length(); j++) {
            cnt += b[j];
            v.push_back(cnt);
        }
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
}