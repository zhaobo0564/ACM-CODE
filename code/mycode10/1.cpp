#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

string s[N];

int n;

vector<string> v;

bool judge(string a, string b) {
    if (a.length() < b.length()) {
        return false;
    }
    for (int i = 0; i < b.length(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() { 
    string t;
    cin >> t;
    cin >> n;
   
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (judge(s[i], t)) {
            v.push_back(s[i]);
        }
    }
    if (v.size() == 0)  {
        cout << t << endl;
    } else {
        sort(v.begin(), v.end());
        cout << v[0] << endl;
    }
}